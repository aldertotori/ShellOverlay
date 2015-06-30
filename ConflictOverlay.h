// ConflictOverlay.h: Definition of the CConflictOverlay class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONFLICTOVERLAY_H__C26B684C_7265_4584_BF5A_AEEB4295034C__INCLUDED_)
#define AFX_CONFLICTOVERLAY_H__C26B684C_7265_4584_BF5A_AEEB4295034C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CConflictOverlay

class CConflictOverlay : 
	public IDispatchImpl<IConflictOverlay, &IID_IConflictOverlay, &LIBID_SHELLOVERLAYLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CConflictOverlay,&CLSID_ConflictOverlay>,
	public IShellIconOverlayIdentifier
{
public:
	CConflictOverlay() {}
BEGIN_COM_MAP(CConflictOverlay)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConflictOverlay)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IShellIconOverlayIdentifier)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CConflictOverlay) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_ConflictOverlay)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IShellIconOverlayIdentifier
public:
	STDMETHOD (IsMemberOf)(THIS_ LPCWSTR pwszPath, DWORD dwAttrib);
    STDMETHOD (GetOverlayInfo)(THIS_ LPWSTR pwszIconFile, int cchMax, int * pIndex, DWORD * pdwFlags);
    STDMETHOD (GetPriority)(THIS_ int * pIPriority);
};

#endif // !defined(AFX_CONFLICTOVERLAY_H__C26B684C_7265_4584_BF5A_AEEB4295034C__INCLUDED_)
