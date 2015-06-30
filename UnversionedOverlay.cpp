// UnversionedOverlay.cpp : Implementation of CShellOverlayApp and DLL registration.

#include "stdafx.h"
#include "ShellOverlay.h"
#include "UnversionedOverlay.h"
#include "FileStatus.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CUnversionedOverlay::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IUnversionedOverlay,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (IsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CUnversionedOverlay::IsMemberOf(THIS_ LPCWSTR pwszPath, DWORD dwAttrib)
{
	HRESULT bRet = CFileStatus::IsUnversioned(pwszPath) ? S_OK : S_FALSE;
	//if(CFileStatus::IsDrivePath(pwszPath)) return S_FALSE;
	return bRet;
}

STDMETHODIMP CUnversionedOverlay::GetOverlayInfo(THIS_ LPWSTR pwszIconFile, int cchMax, int * pIndex, DWORD * pdwFlags)
{
	CString sIcofile;
	GetModuleFileName(_Module.GetModuleInstance(), sIcofile.GetBuffer(MAX_PATH+1), MAX_PATH+1);
	sIcofile.ReleaseBuffer();
	int nPos = sIcofile.ReverseFind(_T('\\'));
	if(nPos > 0)
		sIcofile = sIcofile.Left(nPos);
	sIcofile += _T("\\icons\\UnversionedIcon.ico");
	
	BSTR bstrIcoFile = sIcofile.AllocSysString();
	wcscpy(pwszIconFile, bstrIcoFile);
	SysFreeString(bstrIcoFile);
	
	*pIndex = 0;
	*pdwFlags = ISIOI_ICONFILE | ISIOI_ICONINDEX;
	
	return S_OK;
}

STDMETHODIMP CUnversionedOverlay::GetPriority(THIS_ int * pIPriority)
{
	*pIPriority = 4;
	return S_OK;
}
