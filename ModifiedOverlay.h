// ModifiedOverlay.h: Definition of the CModifiedOverlay class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODIFIEDOVERLAY_H__278244CE_A599_4A44_8CB1_5F8EE06B59D4__INCLUDED_)
#define AFX_MODIFIEDOVERLAY_H__278244CE_A599_4A44_8CB1_5F8EE06B59D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CModifiedOverlay

class CModifiedOverlay : 
	public IDispatchImpl<IModifiedOverlay, &IID_IModifiedOverlay, &LIBID_SHELLOVERLAYLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CModifiedOverlay,&CLSID_ModifiedOverlay>,
	public IShellIconOverlayIdentifier
{
public:
	CModifiedOverlay() {}
BEGIN_COM_MAP(CModifiedOverlay)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IModifiedOverlay)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IShellIconOverlayIdentifier)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CModifiedOverlay) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_ModifiedOverlay)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IShellIconOverlayIdentifier
public:
	STDMETHOD (IsMemberOf)(THIS_ LPCWSTR pwszPath, DWORD dwAttrib);
    STDMETHOD (GetOverlayInfo)(THIS_ LPWSTR pwszIconFile, int cchMax, int * pIndex, DWORD * pdwFlags);
    STDMETHOD (GetPriority)(THIS_ int * pIPriority);
};

#endif // !defined(AFX_MODIFIEDOVERLAY_H__278244CE_A599_4A44_8CB1_5F8EE06B59D4__INCLUDED_)
