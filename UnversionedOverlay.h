// UnversionedOverlay.h: Definition of the CUnversionedOverlay class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNVERSIONEDOVERLAY_H__52B31DB4_12D8_4A55_87A9_35C0E5DF5258__INCLUDED_)
#define AFX_UNVERSIONEDOVERLAY_H__52B31DB4_12D8_4A55_87A9_35C0E5DF5258__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CUnversionedOverlay

class CUnversionedOverlay : 
	public IDispatchImpl<IUnversionedOverlay, &IID_IUnversionedOverlay, &LIBID_SHELLOVERLAYLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CUnversionedOverlay,&CLSID_UnversionedOverlay>,
	public IShellIconOverlayIdentifier
{
public:
	CUnversionedOverlay() {}
BEGIN_COM_MAP(CUnversionedOverlay)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IUnversionedOverlay)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IShellIconOverlayIdentifier)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CUnversionedOverlay) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_UnversionedOverlay)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IShellIconOverlayIdentifier
public:
	STDMETHOD (IsMemberOf)(THIS_ LPCWSTR pwszPath, DWORD dwAttrib);
    STDMETHOD (GetOverlayInfo)(THIS_ LPWSTR pwszIconFile, int cchMax, int * pIndex, DWORD * pdwFlags);
    STDMETHOD (GetPriority)(THIS_ int * pIPriority);
};

#endif // !defined(AFX_UNVERSIONEDOVERLAY_H__52B31DB4_12D8_4A55_87A9_35C0E5DF5258__INCLUDED_)
