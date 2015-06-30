// IgonredOverlay.h: Definition of the CIgonredOverlay class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IGONREDOVERLAY_H__283ED304_4D9B_44E5_BA9E_C13709B59B0F__INCLUDED_)
#define AFX_IGONREDOVERLAY_H__283ED304_4D9B_44E5_BA9E_C13709B59B0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CIgonredOverlay

class CIgonredOverlay : 
	public IDispatchImpl<IIgonredOverlay, &IID_IIgonredOverlay, &LIBID_SHELLOVERLAYLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CIgonredOverlay,&CLSID_IgonredOverlay>,
	public IShellIconOverlayIdentifier
{
public:
	CIgonredOverlay() {}
BEGIN_COM_MAP(CIgonredOverlay)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IIgonredOverlay)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IShellIconOverlayIdentifier)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CIgonredOverlay) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_IgonredOverlay)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IShellIconOverlayIdentifier
public:
	STDMETHOD (IsMemberOf)(THIS_ LPCWSTR pwszPath, DWORD dwAttrib);
    STDMETHOD (GetOverlayInfo)(THIS_ LPWSTR pwszIconFile, int cchMax, int * pIndex, DWORD * pdwFlags);
    STDMETHOD (GetPriority)(THIS_ int * pIPriority);
};

#endif // !defined(AFX_IGONREDOVERLAY_H__283ED304_4D9B_44E5_BA9E_C13709B59B0F__INCLUDED_)
