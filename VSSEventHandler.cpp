// VSSEventHandler.cpp: implementation of the CVSSEventHandler class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "VSSApi.h"
#include "VSSEventHandler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/*
 1.   Visual SourceSafe finds your ProgID in SSADDIN.INI.
 1.   Based on that, Visual SourceSafe calls CoCreateInstance on your ProgID to instantiate your object.
 1.   Visual SourceSafe queries your object for an interface called IVSSEventHandler. Your object must support this interface which contains only one method: Init.
 1.   Visual SourceSafe calls your Init method, passing in a pointer to an interface called IVSS on a Visual SourceSafe object.
 1.   You then QueryInterface from IVSS to another interface on the same object, called IConnectionPointContainer. This interface supports a method called FindConnectionPoint.
 1.   From that interface, you call FindConnectionPoint(IID_IVSSEvents), which returns an interface called IConnectionPoint.
 1.   From that interface, you call the Advise method, passing a pointer to your own IVSSEvents interface.
 1.   Visual SourceSafe is then hooked up and will start calling methods in your IVSSEvents interface.
*/

CVSSEventHandler::CVSSEventHandler()
{
	m_cRef = 0L;
	CLSIDFromString(L"{783CD4EA-9D54-11CF-B8EE-00608CC9A71F}",&m_clsid);
}

CVSSEventHandler::~CVSSEventHandler()
{
}

STDMETHODIMP CVSSEventHandler::QueryInterface(REFIID riid, LPVOID FAR *ppv)
{
    *ppv = NULL;
	
    if (IsEqualIID(riid, IID_IUnknown))
    {
		*ppv = (IUnknown*)this;
    }
    else if (IsEqualIID(riid, m_clsid))
    {
        *ppv = (IVSSEventHandler*)this;
    }
	
    if (*ppv)
    {
        AddRef();
		
        return NOERROR;
    }
	
	return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CVSSEventHandler::AddRef()
{
    return ++m_cRef;
}

STDMETHODIMP_(ULONG) CVSSEventHandler::Release()
{
    if (--m_cRef)
        return m_cRef;
	
    delete this;
	
    return 0L;
}

STDMETHODIMP CVSSEventHandler::Init(IUnknown* pIVSS)
{

	return S_OK;
}