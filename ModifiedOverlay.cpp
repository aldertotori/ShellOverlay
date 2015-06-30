// ModifiedOverlay.cpp : Implementation of CShellOverlayApp and DLL registration.

#include "stdafx.h"
#include "ShellOverlay.h"
#include "ModifiedOverlay.h"
#include "FileStatus.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CModifiedOverlay::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IModifiedOverlay,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (IsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CModifiedOverlay::IsMemberOf(THIS_ LPCWSTR pwszPath, DWORD dwAttrib)
{
	HRESULT bRet = CFileStatus::IsModified(pwszPath) ? S_OK : S_FALSE;
	//if(CFileStatus::IsDrivePath(pwszPath)) return S_FALSE;
	return bRet;
}

STDMETHODIMP CModifiedOverlay::GetOverlayInfo(THIS_ LPWSTR pwszIconFile, int cchMax, int * pIndex, DWORD * pdwFlags)
{
	CString sIcofile;
	GetModuleFileName(_Module.GetModuleInstance(), sIcofile.GetBuffer(MAX_PATH+1), MAX_PATH+1);
	sIcofile.ReleaseBuffer();
	int nPos = sIcofile.ReverseFind(_T('\\'));
	if(nPos > 0)
		sIcofile = sIcofile.Left(nPos);
	sIcofile += _T("\\icons\\ModifiedIcon.ico");
	
	BSTR bstrIcoFile = sIcofile.AllocSysString();
	wcscpy(pwszIconFile, bstrIcoFile);
	SysFreeString(bstrIcoFile);
	
	*pIndex = 0;
	*pdwFlags = ISIOI_ICONFILE | ISIOI_ICONINDEX;
	
	return S_OK;
}

STDMETHODIMP CModifiedOverlay::GetPriority(THIS_ int * pIPriority)
{
	*pIPriority = 1;
	return S_OK;
}
