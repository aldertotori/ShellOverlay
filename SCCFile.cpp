// SCCFile.cpp: implementation of the CSCCFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SCCFile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

static CHAR SCC_FILE_SIGN[] = {0x34,0x12,0x1,0x00};

#define SCC_FILE_COUNT_OFFSET		0x1C

#ifndef ARRAY_SIZE
#define ARRAY_SIZE	1
#endif

#pragma pack(push,1)
// 0x10
typedef struct _SCC_FILE_STATUS
{
	ULONG	unk1;
	ULONG	unk2;
	ULONG	unk3;
	ULONG	unk4;
} SCC_FILE_STATUS;

typedef struct _SCC_FILE_STRUCT
{
	UCHAR	FileSign[4];	// 0
	ULONG	unk1;			// 4
	ULONG	unk2;			// 8
	ULONG	unk3;			// C
	ULONG	unk4;			// 10
	ULONG	unk5;			// 14
	ULONG	ControlVersion;	// 18 VERSION_OFFSET
	ULONG	FileCount;		// 1C SCC_FILE_COUNT_OFFSET
	SCC_FILE_STATUS Status[ARRAY_SIZE];	// 0x20
} SCC_FILE_STRUCT;

#pragma pack(pop)

SCCCache	g_SCCCache;

// -1 First file time is earlier than second file time
// 0  First file time is equal to second file time.
// 1  First file time is later than second file time.
LONG MyCompareFileTime(LARGE_INTEGER FileTime1,LARGE_INTEGER FileTime2)
{
	if ( FileTime1.u.HighPart > FileTime2.u.HighPart )
		return 1;
	if ( FileTime1.u.HighPart >= FileTime2.u.HighPart &&
		 FileTime1.u.LowPart  >= FileTime2.u.LowPart )
	{
		if ( FileTime1.u.HighPart < FileTime2.u.HighPart || 
			 (FileTime1.u.HighPart <= FileTime2.u.HighPart && 
			 FileTime1.u.LowPart <= FileTime2.u.LowPart ))
			return 0;
		return 1;
	}
	return -1;
}

FileState CSCCFile::GetFileState(IN LPCWSTR pwszPathFileName)
{
	BOOL			bTimeReady = FALSE;
	FILETIME		fileTime;
	LARGE_INTEGER	curTime;
	BOOL			bIncluded;
	HANDLE			hFile;
	DWORD			dwAttr = GetFileAttributesW(pwszPathFileName);

	if(dwAttr == INVALID_FILE_ATTRIBUTES) return FileState_Unknown;
	if(dwAttr & FILE_ATTRIBUTE_DIRECTORY) return FileState_Unknown;
	if(dwAttr & FILE_ATTRIBUTE_DEVICE) return FileState_Unknown;
	if(dwAttr & FILE_ATTRIBUTE_HIDDEN) return FileState_Unknown;
	
	bIncluded = IsIncludedFile(pwszPathFileName);
	if(!bIncluded) return FileState_Unversioned;

	hFile = CreateFileW(pwszPathFileName,
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if(hFile != INVALID_HANDLE_VALUE)
	{
		GetFileTime(hFile,NULL,NULL,&fileTime);
		curTime.u.HighPart = fileTime.dwHighDateTime;
		curTime.u.LowPart  = fileTime.dwLowDateTime;
		bTimeReady = TRUE;
	}
	CloseHandle(hFile);

	if(bTimeReady)
	{
		LONG lret = MyCompareFileTime(curTime,m_scc_filetime);
		if(dwAttr & FILE_ATTRIBUTE_READONLY)
		{
			if(lret <= 0)
			{	
				return FileState_Locked;
			}
			else
			{
				return FileState_Conflict;
			}
		}
		else
		{
			if(lret > 0)
			{
				AtlTrace("%ws -> %s\n",pwszPathFileName,"FileState_Modified");
				return FileState_Modified;
			}
			else
			{
				return FileState_Conflict;
			}
		}
	}

	return FileState_Unknown;
}


BOOL CSCCFile::Load(LPWSTR sccFileName)
{
	CSCCFile*	sccFile = NULL;
	DWORD	dwReaded = 0,dwSize;
	DWORD   dwMinFileSize;
	FILETIME	fileTime;
	HANDLE  hFile = CreateFileW(sccFileName,
						GENERIC_READ,
						FILE_SHARE_READ,
						NULL,
						OPEN_EXISTING,
						FILE_ATTRIBUTE_NORMAL,
						NULL);
	if(hFile != INVALID_HANDLE_VALUE)
	{
		dwSize = GetFileSize(hFile,NULL);
		m_file_buf = (char*)CoTaskMemAlloc(dwSize + 1);
		if(m_file_buf)
		{
			if(	ReadFile(hFile,m_file_buf,dwSize,&dwReaded,NULL) &&
				dwSize == dwReaded	)
			{
				if(	memcmp(m_file_buf,SCC_FILE_SIGN,4) == 0 &&
					m_file_buf[dwSize-1] == 0				)
				{
					SCC_FILE_STRUCT* scc_file = (SCC_FILE_STRUCT*)m_file_buf;
					// check file data ok
					if(dwSize > FIELD_OFFSET(SCC_FILE_STRUCT,Status))
					{
						dwMinFileSize = scc_file->FileCount * sizeof(SCC_FILE_STATUS) + 
											FIELD_OFFSET(SCC_FILE_STRUCT,Status);
						if( dwSize > dwMinFileSize	&&
							scc_file->FileCount >= 1)
						{
							sccFile = this;
							m_file_size = dwSize;
							GetFileTime(hFile,NULL,NULL,&fileTime);
							m_scc_filetime.u.HighPart = fileTime.dwHighDateTime;
							m_scc_filetime.u.LowPart  = fileTime.dwLowDateTime;
							ParseSccFile();
						}
					}
				}

				if(sccFile == NULL)
				{
					sccFile = NULL;
					CoTaskMemFree(m_file_buf);
					m_file_buf = NULL;
				}
			}
		}
		CloseHandle(hFile);
	}

	if(sccFile)
	{
		dwSize = wcslen(sccFileName)*sizeof(WCHAR) + sizeof(WCHAR);
		m_file_name = (LPWSTR)CoTaskMemAlloc(dwSize);
		if(m_file_name)
		{
			wcscpy(m_file_name,sccFileName);
		}
		else
		{
			Close();
			sccFile = NULL;
		}
	}
	return sccFile ? TRUE : FALSE;
}

VOID  CSCCFile::ReLoad()
{
	CSCCFile* sccFile = NULL;
	LPWSTR wzFileName = NULL;
	DWORD  dwSize;
	if(!m_file_name) return;
	dwSize = wcslen(m_file_name)*sizeof(WCHAR) + sizeof(WCHAR);
	wzFileName = (LPWSTR)CoTaskMemAlloc(dwSize);
	if(wzFileName)
	{
		wcscpy(wzFileName,m_file_name);
		Load(wzFileName);
		CoTaskMemFree(wzFileName);
	}
}

VOID CSCCFile::ParseSccFile()
{
	FILE_NAME_ITEM*	NameItem;
	UINT	NameOffset = FIELD_OFFSET(SCC_FILE_STRUCT,Status);
	SCC_FILE_STRUCT* scc_file = (SCC_FILE_STRUCT*)m_file_buf;
	NameOffset += scc_file->FileCount * sizeof(SCC_FILE_STATUS);
	AtlTrace("CSCCFile::ParseSccFile -> FileNameOffset : 0x%x,FileCount : %d\n",NameOffset,scc_file->FileCount);
	while(NameOffset < (m_file_size -1))
	{
		UINT dwNeed = MultiByteToWideChar(CP_ACP,
											0,
											m_file_buf + NameOffset,
											-1,
											NULL,
											0);
		if(dwNeed)
		{
			UINT len = dwNeed*sizeof(WCHAR) + sizeof(WCHAR) + sizeof(FILE_NAME_ITEM);
			NameItem = (FILE_NAME_ITEM*)CoTaskMemAlloc(len);
			if(NameItem)
			{
				ZeroMemory(NameItem,len);
				MultiByteToWideChar(CP_ACP,
					0,
					m_file_buf + NameOffset,
					-1,
					(LPWSTR)NameItem->FileName,
					dwNeed + 1);
				NameItem->Next = m_name_items;
				m_name_items = NameItem;
			}
		}
		NameOffset += strlen(m_file_buf + NameOffset) + 1;
	}
	AtlTrace("Parse file Exit");
}

void  CSCCFile::Close()
{
	FILE_NAME_ITEM *pre,*cur = m_name_items;
	while(cur)
	{
		pre = cur;
		if(cur->FileName) CoTaskMemFree(cur->FileName);
		cur = cur->Next;
		CoTaskMemFree(pre);
	}
	m_name_items = NULL;
	if(m_file_name) CoTaskMemFree(m_file_name);
	if(m_file_buf) CoTaskMemFree(m_file_buf);
	m_file_name = NULL;
	m_file_buf  = NULL;
	m_file_size = 0;
}

BOOL CSCCFile::IsReadOnly(LPCWSTR pwszPath)
{
	DWORD dwAttr = GetFileAttributesW(pwszPath);
	if( dwAttr != INVALID_FILE_ATTRIBUTES	&&
		(dwAttr & FILE_ATTRIBUTE_READONLY)	)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
