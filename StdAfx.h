// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__5EFEA9BE_70CD_4E7E_961A_F4C4FB91C307__INCLUDED_)
#define AFX_STDAFX_H__5EFEA9BE_70CD_4E7E_961A_F4C4FB91C307__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED


#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>
#include <atlapp.h>
#include <atlmisc.h>
#include <atlconv.h>
#include <shlguid.h>
#include <comdef.h>
#include <shlobj.h>

using namespace ATL;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__5EFEA9BE_70CD_4E7E_961A_F4C4FB91C307__INCLUDED)
