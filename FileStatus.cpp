// FileStatus.cpp: implementation of the CFileStatus class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FileStatus.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

static CFileStatus	FileStatus;

WCHAR *SkipExtensions[] = 
{
	L".idb",
	L".scc",
	L".exe",
	L".dll",
	L".sys",
	L".ocx",
	L".scr",
	L".cpl",
	L".acm",
	L".drv",
	L".ax",
	L".ime",
	// c/c++ ignore file
	L".obj",
	L".res",
	L".pdb",
	L".tlb",
	L".pch",
	L".lib",
	L".ilk",
	L".tlh",
	L".tli",
	L".sbr",
	L".bsc",
	L".exp",
	L".user",
	L".opt",
	L".ncb",
	L".plg",
	NULL
};

BOOL CFileStatus::IsIgnoredFile(LPCWSTR pwszPath)
{
	BOOL bRet = FALSE;
	int  i = 0;
	CSCCFile* sccFile = NULL;
	WCHAR	sccFileName[4096] = {0};
	UINT	iLen = wcslen(pwszPath);
	UINT	iSkipLen;
	// Find
	if(!IsDirectory(pwszPath))
	{
		if(FindSccFileUseFile((LPWSTR)pwszPath,sccFileName))
		{
			sccFile = FindSccClass(sccFileName);
			if(sccFile)
			{
				while(SkipExtensions[i])
				{
					iSkipLen = wcslen(SkipExtensions[i]);
					if(iSkipLen < iLen)
					{
						if(wcsicmp(pwszPath+iLen-iSkipLen,SkipExtensions[i]) == 0)
						{
							bRet = TRUE;
							break;
						}
					}
					i++;
				}
			}
		}
	}
	return bRet;
}

CFileStatus::CFileStatus()
{
	InitializeCriticalSection(&m_lock);
}

CFileStatus::~CFileStatus()
{
	DeleteCriticalSection(&m_lock);
}

CSCCFile* CFileStatus::FindSccClass(IN LPWSTR sccFileName)
{
	CSCCFile* scc = NULL;
	lock();
	scc = g_SCCCache.FindSccClass(sccFileName);
	unlock();
	return scc;
}

BOOL CFileStatus::FindSccFileUseFile(IN LPWSTR CurrentFile,OUT LPWSTR sccFileName)
{
	BOOL	bRet = FALSE;
	LPWSTR  szParentDir = NULL;
	DWORD   dwSize = wcslen(CurrentFile)*sizeof(WCHAR) + 
			wcslen(L"\\vssver2.scc")*sizeof(WCHAR) + 
					 sizeof(WCHAR);
	LPWSTR  strSccFile = (LPWSTR)CoTaskMemAlloc(dwSize);
	if(strSccFile)
	{
		wcscpy(strSccFile,CurrentFile);
		LPWSTR pTemp = wcsrchr(strSccFile,L'\\');
		if(pTemp) *pTemp = L'\0';
		wcscat(strSccFile,L"\\vssver2.scc");
		if(FileExist(strSccFile))
		{
			wcscpy(sccFileName,strSccFile);
			bRet  = TRUE;
		}
	}
	CoTaskMemFree(strSccFile);
	return bRet;
}

BOOL CFileStatus::FindSccFileInDir(IN LPWSTR CurrentDirectory,OUT LPWSTR sccFileName)
{
	BOOL	bRet = FALSE;
	LPWSTR  szParentDir = NULL;
	DWORD   dwSize = wcslen(CurrentDirectory)*sizeof(WCHAR) + 
					 wcslen(L"\\vssver2.scc")*sizeof(WCHAR) + 
					 sizeof(WCHAR);
	LPWSTR  strSccFile = (LPWSTR)CoTaskMemAlloc(dwSize);
	if(strSccFile)
	{
		wcscpy(strSccFile,CurrentDirectory);
		wcscat(strSccFile,L"\\vssver2.scc");
		if(FileExist(strSccFile))
		{
			wcscpy(sccFileName,strSccFile);
			bRet  = TRUE;
		}
	}
	CoTaskMemFree(strSccFile);
	return bRet;
}

BOOL CFileStatus::Added(LPCWSTR pwszPath)
{
	WCHAR	sccFileName[4096] = {0};
	BOOL	bRet = FALSE;
	CSCCFile* sccFile = NULL;
	lock();
	if(IsIgnoredFile(pwszPath))
	{

	}
	else if(IsDirectory(pwszPath)) // dir
	{
		if(FindSccFileInDir((LPWSTR)pwszPath,sccFileName))
		{
			if(sccFile = FindSccClass(sccFileName))
			{
				FileState state = sccFile->GetDirState(pwszPath);
				if( state == FileState_Added)
				{
					bRet = TRUE;
				}
			}
		}
	}
	else if(!IsDrivePath(pwszPath))
	{
		if(FindSccFileUseFile((LPWSTR)pwszPath,sccFileName))
		{
			sccFile = FindSccClass(sccFileName);
			if(sccFile)
			{
				if(sccFile->GetFileState(pwszPath) == FileState_Added)
				{
					bRet = TRUE;
				}
			}
		}
	}
	unlock();
	return bRet;
}

BOOL CFileStatus::Conflict(LPCWSTR pwszPath)
{
	WCHAR	sccFileName[4096] = {0};
	BOOL	bRet = FALSE;
	CSCCFile* sccFile = NULL;
	lock();
	if(IsIgnoredFile(pwszPath))
	{
		
	}
	else if(IsDirectory(pwszPath))
	{
		if(FindSccFileInDir((LPWSTR)pwszPath,sccFileName))
		{
			if(sccFile = FindSccClass(sccFileName))
			{
				FileState state = sccFile->GetDirState(pwszPath);
				if( state == FileState_Conflict)
				{
					bRet = TRUE;
				}
			}
		}
	}
	else if(!IsDrivePath(pwszPath))
	{
		if(FindSccFileUseFile((LPWSTR)pwszPath,sccFileName))
		{
			sccFile = FindSccClass(sccFileName);
			if(sccFile)
			{
				if(sccFile->GetFileState(pwszPath) == FileState_Conflict)
				{
					bRet = TRUE;
				}
			}
		}
	}
	unlock();
	return bRet;
}

BOOL CFileStatus::Deleted(LPCWSTR pwszPath)
{
	WCHAR	sccFileName[4096] = {0};
	BOOL	bRet = FALSE;
	CSCCFile* sccFile = NULL;
	lock();
	if(IsIgnoredFile(pwszPath))
	{
		
	}
	else if(IsDirectory(pwszPath))
	{
		if(FindSccFileInDir((LPWSTR)pwszPath,sccFileName))
		{
			if(sccFile = FindSccClass(sccFileName))
			{
				FileState state = sccFile->GetDirState(pwszPath);
				if( state == FileState_Deleted)
				{
					bRet = TRUE;
				}
			}
		}
	}
	else if(!IsDrivePath(pwszPath))
	{
		if(FindSccFileUseFile((LPWSTR)pwszPath,sccFileName))
		{
			sccFile = FindSccClass(sccFileName);
			if(sccFile)
			{
				if(sccFile->GetFileState(pwszPath) == FileState_Deleted)
				{
					bRet = TRUE;
				}
			}
		}
	}
	unlock();
	return bRet;
}

BOOL CFileStatus::Ignored(LPCWSTR pwszPath)
{
	WCHAR	sccFileName[4096] = {0};
	BOOL	bRet = FALSE;
	CSCCFile* sccFile = NULL;
	lock();
	bRet = IsIgnoredFile(pwszPath);
	unlock();
	return bRet;
}

BOOL CFileStatus::Locked(LPCWSTR pwszPath)
{
	WCHAR	sccFileName[4096] = {0};
	BOOL	bRet = FALSE;
	CSCCFile* sccFile = NULL;
	lock();
	if(IsIgnoredFile(pwszPath))
	{
		
	}
	else if(IsDirectory(pwszPath))
	{
		if(FindSccFileInDir((LPWSTR)pwszPath,sccFileName))
		{
			if(sccFile = FindSccClass(sccFileName))
			{
				FileState state = sccFile->GetDirState(pwszPath);
				if( state == FileState_Locked)
				{
					bRet = TRUE;
				}
			}
		}
	}
	else if(!IsDrivePath(pwszPath))
	{
		if(FindSccFileUseFile((LPWSTR)pwszPath,sccFileName))
		{
			sccFile = FindSccClass(sccFileName);
			if(sccFile)
			{
				if(sccFile->GetFileState(pwszPath) == FileState_Locked)
				{
					bRet = TRUE;
				}
			}
		}
	}
	unlock();
	return bRet;
}

BOOL CFileStatus::Modified(LPCWSTR pwszPath)
{
	WCHAR	sccFileName[4096] = {0};
	BOOL	bRet = FALSE;
	CSCCFile* sccFile = NULL;
	lock();
	if(IsIgnoredFile(pwszPath))
	{
		
	}
	else if(IsDirectory(pwszPath))
	{
		if(FindSccFileInDir((LPWSTR)pwszPath,sccFileName))
		{
			if(sccFile = FindSccClass(sccFileName))
			{
				FileState state = sccFile->GetDirState(pwszPath);
				if( state == FileState_Modified)
				{
					bRet = TRUE;
				}
			}
		}
	}
	else if(!IsDrivePath(pwszPath))
	{
		if(FindSccFileUseFile((LPWSTR)pwszPath,sccFileName))
		{
			sccFile = FindSccClass(sccFileName);
			if(sccFile)
			{
				if(sccFile->GetFileState(pwszPath) == FileState_Modified)
				{
					bRet = TRUE;
				}
			}
		}
	}
	unlock();
	return bRet;
}

BOOL CFileStatus::Unversioned(LPCWSTR pwszPath)
{
	WCHAR	sccFileName[4096] = {0};
	BOOL	bRet = FALSE;
	CSCCFile* sccFile = NULL;
	lock();
	if(IsIgnoredFile(pwszPath))
	{
		
	}
	else if(IsDirectory(pwszPath))
	{
		if(FindSccFileInDir((LPWSTR)pwszPath,sccFileName))
		{
			if(sccFile = FindSccClass(sccFileName))
			{
				FileState state = sccFile->GetDirState(pwszPath);
				if( state == FileState_Unversioned)
				{
					bRet = TRUE;
				}
			}
		}
	}
	else if(!IsDrivePath(pwszPath))
	{
		if(FindSccFileUseFile((LPWSTR)pwszPath,sccFileName))
		{
			sccFile = FindSccClass(sccFileName);
			if(sccFile)
			{
				if(sccFile->GetFileState(pwszPath) == FileState_Unversioned)
				{
					bRet = TRUE;
				}
			}
		}
	}
	unlock();
	return bRet;
}

BOOL CFileStatus::FileExist(LPCWSTR pwszPath)
{
	DWORD dwAttr = GetFileAttributesW(pwszPath);
	if(dwAttr == INVALID_FILE_ATTRIBUTES) return FALSE;
	if(dwAttr & FILE_ATTRIBUTE_DIRECTORY) return FALSE;
	return TRUE;
}

BOOL CFileStatus::IsDirectory(LPCWSTR pwszPath)
{
	DWORD dwAttr = GetFileAttributesW(pwszPath);
	if( dwAttr != INVALID_FILE_ATTRIBUTES	&&
		(dwAttr & FILE_ATTRIBUTE_DIRECTORY)	)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL CFileStatus::IsReadOnly(LPCWSTR pwszPath)
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

void CFileStatus::lock()
{
	EnterCriticalSection(&m_lock);
}
	
void CFileStatus::unlock()
{
	LeaveCriticalSection(&m_lock);
}

BOOL CFileStatus::IsAdded(LPCWSTR pwszPath)
{
	return FileStatus.Added(pwszPath);
}

BOOL CFileStatus::IsConflict(LPCWSTR pwszPath)
{
	return FileStatus.Conflict(pwszPath);
}

BOOL CFileStatus::IsDeleted(LPCWSTR pwszPath)
{
	return FileStatus.Deleted(pwszPath);
}

BOOL CFileStatus::IsIgnored(LPCWSTR pwszPath)
{
	return FileStatus.Ignored(pwszPath);
}

BOOL CFileStatus::IsLocked(LPCWSTR pwszPath)
{
	return FileStatus.Locked(pwszPath);
}

BOOL CFileStatus::IsModified(LPCWSTR pwszPath)
{
	return FileStatus.Modified(pwszPath);
}

BOOL CFileStatus::IsUnversioned(LPCWSTR pwszPath)
{
	return FileStatus.Unversioned(pwszPath);
}