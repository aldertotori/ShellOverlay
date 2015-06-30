// ConflictOverlay.cpp : Implementation of CShellOverlayApp and DLL registration.

#include "stdafx.h"
#include "ShellOverlay.h"
#include "FileStatus.h"
#include "ConflictOverlay.h"


/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CConflictOverlay::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IConflictOverlay,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (IsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CConflictOverlay::IsMemberOf(THIS_ LPCWSTR pwszPath, DWORD dwAttrib)
{
	HRESULT bRet = CFileStatus::IsConflict(pwszPath) ? S_OK : S_FALSE;
	//if(CFileStatus::IsDrivePath(pwszPath)) return S_FALSE;
	return bRet;
}

STDMETHODIMP CConflictOverlay::GetOverlayInfo(THIS_ LPWSTR pwszIconFile, int cchMax, int * pIndex, DWORD * pdwFlags)
{
	CString sIcofile;
	GetModuleFileName(_Module.GetModuleInstance(), sIcofile.GetBuffer(MAX_PATH+1), MAX_PATH+1);
	sIcofile.ReleaseBuffer();
	int nPos = sIcofile.ReverseFind(_T('\\'));
	if(nPos > 0)
		sIcofile = sIcofile.Left(nPos);
	sIcofile += _T("\\icons\\ConflictIcon.ico");
	
	BSTR bstrIcoFile = sIcofile.AllocSysString();
	wcscpy(pwszIconFile, bstrIcoFile);
	SysFreeString(bstrIcoFile);
	
	*pIndex = 0;
	*pdwFlags = ISIOI_ICONFILE | ISIOI_ICONINDEX;
	
	return S_OK;
}

STDMETHODIMP CConflictOverlay::GetPriority(THIS_ int * pIPriority)
{
	*pIPriority = 2;
	return S_OK;
}
