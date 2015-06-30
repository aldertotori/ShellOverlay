// LockedOverlay.h: Definition of the CLockedOverlay class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOCKEDOVERLAY_H__7B41F90C_5111_4939_9E36_CC665F9799F9__INCLUDED_)
#define AFX_LOCKEDOVERLAY_H__7B41F90C_5111_4939_9E36_CC665F9799F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLockedOverlay

class CLockedOverlay : 
	public IDispatchImpl<ILockedOverlay, &IID_ILockedOverlay, &LIBID_SHELLOVERLAYLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CLockedOverlay,&CLSID_LockedOverlay>,
	public IShellIconOverlayIdentifier
{
public:
	CLockedOverlay() {}
BEGIN_COM_MAP(CLockedOverlay)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ILockedOverlay)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IShellIconOverlayIdentifier)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CLockedOverlay) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_LockedOverlay)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IShellIconOverlayIdentifier
public:
	STDMETHOD (IsMemberOf)(THIS_ LPCWSTR pwszPath, DWORD dwAttrib);
    STDMETHOD (GetOverlayInfo)(THIS_ LPWSTR pwszIconFile, int cchMax, int * pIndex, DWORD * pdwFlags);
    STDMETHOD (GetPriority)(THIS_ int * pIPriority);
};

#endif // !defined(AFX_LOCKEDOVERLAY_H__7B41F90C_5111_4939_9E36_CC665F9799F9__INCLUDED_)
