// SCCFile.h: interface for the CSCCFile class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _SCCFILE_H_
#define _SCCFILE_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class SCCCache;

LONG MyCompareFileTime(LARGE_INTEGER FileTime1,LARGE_INTEGER FileTime2);

class CacheLock
{
public:
	CacheLock()
	{
		InitializeCriticalSection(&m_lock);
	}
	virtual ~CacheLock()
	{
		DeleteCriticalSection(&m_lock);
	}
public:
	VOID Lock()
	{
		EnterCriticalSection(&m_lock);
	}
	VOID UnLock()
	{
		LeaveCriticalSection(&m_lock);
	}
private:
	CRITICAL_SECTION	m_lock;
};

typedef struct _FILE_NAME_ITEM
{
	struct _FILE_NAME_ITEM* Next;
	WCHAR					FileName[1];
} FILE_NAME_ITEM;

enum FileState
{
	FileState_Unknown,
	FileState_Added,
	FileState_Conflict,
	FileState_Deleted,
	FileState_Ignored,
	FileState_Locked,
	FileState_Modified,
	FileState_Unversioned
};

class CSCCFile  
{
	friend class SCCCache;
public:
	CSCCFile() : m_file_name(NULL) , 
				m_file_buf(NULL) , 
				m_name_items(NULL) ,
				m_scc_dir(NULL),
				m_file_size(0)
	{
	}
protected:
	virtual ~CSCCFile()
	{
		Close();
	}
public:
	LPWSTR	Name() { return m_file_name;}
	BOOL	IsIncludedFile(IN LPCWSTR pwszPath)
	{
		LPWSTR		itemFileName;
		FILE_NAME_ITEM *cur = m_name_items;
		UINT		iLen,iPathLen;
		iPathLen = wcslen(pwszPath);
		while(cur)
		{
			if(	cur->FileName)
			{
				iLen = wcslen(cur->FileName);
				if(iLen < iPathLen)
				{
					itemFileName = (LPWSTR)pwszPath + iPathLen - iLen;
					if(wcsicmp(cur->FileName,itemFileName) == 0) return TRUE;
				}

			}
			cur = cur->Next;
		}
		return FALSE;
	}

	// FileState_Locked 
	// FileState_Modified
	// FileState_Unversioned
	// FileState_Added
	// FileState_Ignored
	FileState GetDirState(IN LPCWSTR pwszPath)
	{
		// Enum dir files state

		return FileState_Locked;
	}

	FileState GetFileState(IN LPCWSTR pwszPathFileName);
	BOOL IsReadOnly(LPCWSTR pwszPath);
protected:
	BOOL		Load(LPWSTR sccFileName);
	VOID		ReLoad();
	void		Close();
	VOID		ParseSccFile();
	VOID		GetCacheFileTime(LARGE_INTEGER* fileTime)
	{
		fileTime->QuadPart = m_scc_filetime.QuadPart;
	}

	LARGE_INTEGER	m_scc_filetime;
	
private:
	char	*m_file_buf;
	UINT	m_file_size;
	WCHAR	*m_file_name;
	
	WCHAR	*m_scc_dir;
	FILE_NAME_ITEM* m_name_items;
};

typedef struct _CACHE_ITEM
{
	struct _CACHE_ITEM* Next;
	CSCCFile*			CacheFile;
	ULONG				Reserved;
} CACHE_ITEM;

class SCCCache
{
public:
	SCCCache() : m_cache_items(NULL)
	{
	}
	virtual ~SCCCache()
	{
		while(m_cache_items)
			RemoveItem(m_cache_items->CacheFile);
	}

	CSCCFile* FindSccClass(LPWSTR sccFullPathName)
	{
		CACHE_ITEM* Cache = FindCacheItem(sccFullPathName);
		if(Cache)
		{
			if(NeedUpdated(Cache)) Cache->CacheFile->ReLoad();
		}
		else if(FileExist(sccFullPathName))
		{
			Cache = AddCacheItem(sccFullPathName);
		}
		if(Cache && Cache->CacheFile) return Cache->CacheFile;
		return NULL;
	}

private:
	BOOL  NeedUpdated(CACHE_ITEM* item)
	{
		FILETIME		fileTime;
		LARGE_INTEGER	curTime;
		if(!item) return FALSE;
		HANDLE hFile = CreateFileW(item->CacheFile->Name(),
								GENERIC_READ,
								FILE_SHARE_READ,
								NULL,
								OPEN_EXISTING,
								0,
								NULL);
		if(hFile == INVALID_HANDLE_VALUE)
		{
			RemoveItem(item->CacheFile); //sccFile);
			return FALSE;
		}
		GetFileTime(hFile,NULL,NULL,&fileTime);
		CloseHandle(hFile);

		curTime.u.HighPart = fileTime.dwHighDateTime;
		curTime.u.LowPart  = fileTime.dwLowDateTime;
		if(curTime.QuadPart != item->CacheFile->m_scc_filetime.QuadPart)
		{
			return TRUE;
		}
		return FALSE;
	}

	CACHE_ITEM* AddCacheItem(LPWSTR sccFullPathName)
	{
		CSCCFile* sccFile;
		CACHE_ITEM* cacheItem = (CACHE_ITEM*)CoTaskMemAlloc(sizeof(CACHE_ITEM));
		if(cacheItem)
		{
			sccFile = new CSCCFile();
			if(sccFile)
			{
				if(sccFile->Load(sccFullPathName))
				{
					cacheItem->CacheFile = sccFile;
					cacheItem->Next = m_cache_items;
					m_cache_items = cacheItem;
				}
				else
				{
					delete sccFile;
					CoTaskMemFree(cacheItem);
					cacheItem = NULL;
				}
			}
			else
			{
				CoTaskMemFree(cacheItem);
				cacheItem = NULL;
			}
		}
		return cacheItem;
	}

	CACHE_ITEM*	FindCacheItem(LPWSTR sccFullPathName)
	{
		CACHE_ITEM* cur = NULL;
		for(cur = m_cache_items; cur != NULL; cur = cur->Next)
		{
			if(cur->CacheFile)
			{
				if( cur->CacheFile->Name()	&&
					wcsicmp(cur->CacheFile->Name(),sccFullPathName) == 0)
				{
					break;
				}
			}
		}
		return cur;
	}

	VOID RemoveItem(CSCCFile* sccFile)
	{
		CACHE_ITEM* cur,*pre = NULL;
		for(cur = m_cache_items; cur != NULL; cur = cur->Next)
		{
			if(cur->CacheFile == sccFile)
			{
				if(pre == NULL) 
					m_cache_items = cur->Next;
				else
					pre->Next = cur->Next;
				delete cur->CacheFile;
				CoTaskMemFree(cur);
				break;
			}
			pre = cur;
		}
	}

	BOOL FileExist(LPCWSTR pwszPath)
	{
		DWORD dwAttr = GetFileAttributesW(pwszPath);
		if(dwAttr == INVALID_FILE_ATTRIBUTES) return FALSE;
		if(dwAttr & FILE_ATTRIBUTE_DIRECTORY) return FALSE;
		return TRUE;
	}
	CACHE_ITEM*			m_cache_items;
};

extern SCCCache		g_SCCCache;

#endif // _SCCFILE_H_


