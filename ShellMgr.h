// ShellMgr.h: interface for the CShellMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHELLMGR_H__A5EDA0D6_0FC9_45D9_B647_6F072FFEF2ED__INCLUDED_)
#define AFX_SHELLMGR_H__A5EDA0D6_0FC9_45D9_B647_6F072FFEF2ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>

class CShellMgr  
{
public:
	CShellMgr(){}
	virtual ~CShellMgr() {}
public:
	UINT GetSize(LPCITEMIDLIST pidl)
	{
		UINT cbTotal = 0;
		if (pidl != NULL)
		{
			while (pidl->mkid.cb != 0)
			{
				cbTotal += pidl->mkid.cb;
				pidl = Next(pidl);
			}
		}
		return cbTotal;
	}

	LPCITEMIDLIST Next(LPCITEMIDLIST pidl)
	{
		if(pidl)
			return (LPITEMIDLIST)(LPBYTE)(((LPBYTE)pidl) + pidl->mkid.cb);
		else
			return (NULL);
	}

	BOOL GetName (LPSHELLFOLDER lpsf, LPITEMIDLIST lpi, DWORD dwFlags, LPSTR Buf,IN OUT UINT* BufLen)
	{
		BOOL	bSuccess = TRUE;
		STRRET str;
		if (NOERROR == lpsf->GetDisplayNameOf(lpi, dwFlags, &str))
		{
			switch (str.uType)
			{
			case STRRET_WSTR:
				*BufLen = WideCharToMultiByte (
					CP_ACP,			// code page
					0 ,				// dwFlags
					str.pOleStr,	// lpWideCharStr
					-1,				// cchWideChar
					Buf,			// lpMultiByteStr
					*BufLen,		// cchMultiByte
					NULL,			// lpDefaultChar
					NULL);			// lpUsedDefaultChar
				break;
			case STRRET_OFFSET:
				lstrcpy (Buf, (LPSTR)lpi + str.uOffset);
				break;
			case STRRET_CSTR:
				lstrcpy (Buf, (LPSTR) str.cStr);
				break;
			default:
				bSuccess = FALSE;
				break;
			}
		}
		else
			bSuccess = FALSE;
		return bSuccess;
	}

	BOOL GetPathName(LPCITEMIDLIST lpi, LPTSTR Buf,IN OUT UINT* BufLen)
	{
		TCHAR szBuffer[MAX_PATH];
		if(::SHGetPathFromIDList(lpi,szBuffer))
		{
			if (szBuffer[0] == 0) return FALSE;
			_tcscpy(Buf,szBuffer);
			*BufLen = _tcslen(Buf) * sizeof(TCHAR) + sizeof(TCHAR);
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
};

#endif // !defined(AFX_SHELLMGR_H__A5EDA0D6_0FC9_45D9_B647_6F072FFEF2ED__INCLUDED_)
