// VSSEventHandler.h: interface for the CVSSEventHandler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VSSEVENTHANDLER_H__076B6620_BE5A_4B34_AD9A_F2680C27DEE8__INCLUDED_)
#define AFX_VSSEVENTHANDLER_H__076B6620_BE5A_4B34_AD9A_F2680C27DEE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CVSSEventHandler : public IVSSEventHandler
{
public:
	CVSSEventHandler();
	virtual ~CVSSEventHandler();
public:
	//IUnknown members
	STDMETHODIMP			QueryInterface(REFIID, LPVOID FAR *);
	STDMETHODIMP_(ULONG)	AddRef();
	STDMETHODIMP_(ULONG)	Release();
	// IVSSEventHandler members
	STDMETHODIMP			Init(IUnknown* pIVSS);
protected:
	ULONG        m_cRef;
	GUID		 m_clsid;
};

#endif // !defined(AFX_VSSEVENTHANDLER_H__076B6620_BE5A_4B34_AD9A_F2680C27DEE8__INCLUDED_)
