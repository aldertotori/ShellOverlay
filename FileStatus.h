// FileStatus.h: interface for the CFileStatus class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILESTATUS_H__66F2D87D_D2D3_4C6D_991F_1226B1E0D458__INCLUDED_)
#define AFX_FILESTATUS_H__66F2D87D_D2D3_4C6D_991F_1226B1E0D458__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SccFile.h"

class CFileStatus  
{
public:
	CFileStatus();
	virtual ~CFileStatus();

	static BOOL IsAdded(LPCWSTR pwszPath);
	static BOOL IsConflict(LPCWSTR pwszPath);
	static BOOL IsDeleted(LPCWSTR pwszPath);
	static BOOL IsIgnored(LPCWSTR pwszPath);
	static BOOL IsLocked(LPCWSTR pwszPath);
	static BOOL IsModified(LPCWSTR pwszPath);
	static BOOL IsUnversioned(LPCWSTR pwszPath);
	static BOOL IsDrivePath(LPCWSTR pwszPath)
	{
		size_t len = wcslen(pwszPath);
		if(len == 2)
		{
			if(pwszPath[1] == L':') return TRUE;
		}
		else if(len == 3)
		{
			if(pwszPath[1] == L':' && pwszPath[2] == L'\\') return TRUE;
		}
		return FALSE;
	}
public:
	BOOL Added(LPCWSTR pwszPath);
	BOOL Conflict(LPCWSTR pwszPath);
	BOOL Deleted(LPCWSTR pwszPath);
	BOOL Ignored(LPCWSTR pwszPath);
	BOOL Locked(LPCWSTR pwszPath);
	BOOL Modified(LPCWSTR pwszPath);
	BOOL Unversioned(LPCWSTR pwszPath);
	BOOL IsIgnoredFile(LPCWSTR pwszPath);
	CSCCFile* FindSccClass(IN LPWSTR sccFileName);
protected:
	void lock();
	void unlock();
	BOOL IsDirectory(LPCWSTR pwszPath);
	BOOL IsReadOnly(LPCWSTR pwszPath);
	BOOL FileExist(LPCWSTR pwszPath);
private:
	CRITICAL_SECTION	m_lock;
	BOOL FindSccFileInDir(IN LPWSTR CurrentDirectory,OUT LPWSTR sccFileName);
	BOOL FindSccFileUseFile(IN LPWSTR CurrentFile,OUT LPWSTR sccFileName);

};

#endif // !defined(AFX_FILESTATUS_H__66F2D87D_D2D3_4C6D_991F_1226B1E0D458__INCLUDED_)
