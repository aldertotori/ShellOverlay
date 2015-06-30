/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Jun 06 21:55:58 2015
 */
/* Compiler settings for C:\Documents and Settings\antime\My Documents\ShellOverlay\ShellOverlay.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ShellOverlay_h__
#define __ShellOverlay_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IConflictOverlay_FWD_DEFINED__
#define __IConflictOverlay_FWD_DEFINED__
typedef interface IConflictOverlay IConflictOverlay;
#endif 	/* __IConflictOverlay_FWD_DEFINED__ */


#ifndef __IModifiedOverlay_FWD_DEFINED__
#define __IModifiedOverlay_FWD_DEFINED__
typedef interface IModifiedOverlay IModifiedOverlay;
#endif 	/* __IModifiedOverlay_FWD_DEFINED__ */


#ifndef __IIgonredOverlay_FWD_DEFINED__
#define __IIgonredOverlay_FWD_DEFINED__
typedef interface IIgonredOverlay IIgonredOverlay;
#endif 	/* __IIgonredOverlay_FWD_DEFINED__ */


#ifndef __IUnversionedOverlay_FWD_DEFINED__
#define __IUnversionedOverlay_FWD_DEFINED__
typedef interface IUnversionedOverlay IUnversionedOverlay;
#endif 	/* __IUnversionedOverlay_FWD_DEFINED__ */


#ifndef __ILockedOverlay_FWD_DEFINED__
#define __ILockedOverlay_FWD_DEFINED__
typedef interface ILockedOverlay ILockedOverlay;
#endif 	/* __ILockedOverlay_FWD_DEFINED__ */


#ifndef __IShellContextMenu_FWD_DEFINED__
#define __IShellContextMenu_FWD_DEFINED__
typedef interface IShellContextMenu IShellContextMenu;
#endif 	/* __IShellContextMenu_FWD_DEFINED__ */


#ifndef __ConflictOverlay_FWD_DEFINED__
#define __ConflictOverlay_FWD_DEFINED__

#ifdef __cplusplus
typedef class ConflictOverlay ConflictOverlay;
#else
typedef struct ConflictOverlay ConflictOverlay;
#endif /* __cplusplus */

#endif 	/* __ConflictOverlay_FWD_DEFINED__ */


#ifndef __ModifiedOverlay_FWD_DEFINED__
#define __ModifiedOverlay_FWD_DEFINED__

#ifdef __cplusplus
typedef class ModifiedOverlay ModifiedOverlay;
#else
typedef struct ModifiedOverlay ModifiedOverlay;
#endif /* __cplusplus */

#endif 	/* __ModifiedOverlay_FWD_DEFINED__ */


#ifndef __IgonredOverlay_FWD_DEFINED__
#define __IgonredOverlay_FWD_DEFINED__

#ifdef __cplusplus
typedef class IgonredOverlay IgonredOverlay;
#else
typedef struct IgonredOverlay IgonredOverlay;
#endif /* __cplusplus */

#endif 	/* __IgonredOverlay_FWD_DEFINED__ */


#ifndef __UnversionedOverlay_FWD_DEFINED__
#define __UnversionedOverlay_FWD_DEFINED__

#ifdef __cplusplus
typedef class UnversionedOverlay UnversionedOverlay;
#else
typedef struct UnversionedOverlay UnversionedOverlay;
#endif /* __cplusplus */

#endif 	/* __UnversionedOverlay_FWD_DEFINED__ */


#ifndef __LockedOverlay_FWD_DEFINED__
#define __LockedOverlay_FWD_DEFINED__

#ifdef __cplusplus
typedef class LockedOverlay LockedOverlay;
#else
typedef struct LockedOverlay LockedOverlay;
#endif /* __cplusplus */

#endif 	/* __LockedOverlay_FWD_DEFINED__ */


#ifndef __ShellContextMenu_FWD_DEFINED__
#define __ShellContextMenu_FWD_DEFINED__

#ifdef __cplusplus
typedef class ShellContextMenu ShellContextMenu;
#else
typedef struct ShellContextMenu ShellContextMenu;
#endif /* __cplusplus */

#endif 	/* __ShellContextMenu_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IConflictOverlay_INTERFACE_DEFINED__
#define __IConflictOverlay_INTERFACE_DEFINED__

/* interface IConflictOverlay */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IConflictOverlay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0632A410-1931-4D77-B216-CDABC991E4C1")
    IConflictOverlay : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IConflictOverlayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IConflictOverlay __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IConflictOverlay __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IConflictOverlay __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IConflictOverlay __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IConflictOverlay __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IConflictOverlay __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IConflictOverlay __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } IConflictOverlayVtbl;

    interface IConflictOverlay
    {
        CONST_VTBL struct IConflictOverlayVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConflictOverlay_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IConflictOverlay_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IConflictOverlay_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IConflictOverlay_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IConflictOverlay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IConflictOverlay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IConflictOverlay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IConflictOverlay_INTERFACE_DEFINED__ */


#ifndef __IModifiedOverlay_INTERFACE_DEFINED__
#define __IModifiedOverlay_INTERFACE_DEFINED__

/* interface IModifiedOverlay */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IModifiedOverlay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E5781EC-E78F-498D-81F0-3912B34157D6")
    IModifiedOverlay : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IModifiedOverlayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IModifiedOverlay __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IModifiedOverlay __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IModifiedOverlay __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IModifiedOverlay __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IModifiedOverlay __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IModifiedOverlay __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IModifiedOverlay __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } IModifiedOverlayVtbl;

    interface IModifiedOverlay
    {
        CONST_VTBL struct IModifiedOverlayVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IModifiedOverlay_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IModifiedOverlay_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IModifiedOverlay_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IModifiedOverlay_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IModifiedOverlay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IModifiedOverlay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IModifiedOverlay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IModifiedOverlay_INTERFACE_DEFINED__ */


#ifndef __IIgonredOverlay_INTERFACE_DEFINED__
#define __IIgonredOverlay_INTERFACE_DEFINED__

/* interface IIgonredOverlay */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIgonredOverlay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ECC336D7-637B-4F29-AB94-4B96DBE4C575")
    IIgonredOverlay : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IIgonredOverlayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIgonredOverlay __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIgonredOverlay __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIgonredOverlay __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IIgonredOverlay __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IIgonredOverlay __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IIgonredOverlay __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IIgonredOverlay __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } IIgonredOverlayVtbl;

    interface IIgonredOverlay
    {
        CONST_VTBL struct IIgonredOverlayVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIgonredOverlay_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIgonredOverlay_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIgonredOverlay_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIgonredOverlay_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IIgonredOverlay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IIgonredOverlay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IIgonredOverlay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIgonredOverlay_INTERFACE_DEFINED__ */


#ifndef __IUnversionedOverlay_INTERFACE_DEFINED__
#define __IUnversionedOverlay_INTERFACE_DEFINED__

/* interface IUnversionedOverlay */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUnversionedOverlay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("39B3D604-1D04-48AA-B772-F554017B763A")
    IUnversionedOverlay : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IUnversionedOverlayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IUnversionedOverlay __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IUnversionedOverlay __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IUnversionedOverlay __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IUnversionedOverlay __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IUnversionedOverlay __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IUnversionedOverlay __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IUnversionedOverlay __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } IUnversionedOverlayVtbl;

    interface IUnversionedOverlay
    {
        CONST_VTBL struct IUnversionedOverlayVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnversionedOverlay_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnversionedOverlay_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnversionedOverlay_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnversionedOverlay_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUnversionedOverlay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUnversionedOverlay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUnversionedOverlay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUnversionedOverlay_INTERFACE_DEFINED__ */


#ifndef __ILockedOverlay_INTERFACE_DEFINED__
#define __ILockedOverlay_INTERFACE_DEFINED__

/* interface ILockedOverlay */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ILockedOverlay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37A27E8A-6D00-4234-BF9C-B4AAE8722962")
    ILockedOverlay : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ILockedOverlayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ILockedOverlay __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ILockedOverlay __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ILockedOverlay __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ILockedOverlay __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ILockedOverlay __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ILockedOverlay __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ILockedOverlay __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } ILockedOverlayVtbl;

    interface ILockedOverlay
    {
        CONST_VTBL struct ILockedOverlayVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILockedOverlay_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILockedOverlay_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILockedOverlay_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILockedOverlay_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILockedOverlay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILockedOverlay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILockedOverlay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILockedOverlay_INTERFACE_DEFINED__ */


#ifndef __IShellContextMenu_INTERFACE_DEFINED__
#define __IShellContextMenu_INTERFACE_DEFINED__

/* interface IShellContextMenu */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IShellContextMenu;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("143EDD86-3035-48B5-A3B7-0E43BA2EB9C9")
    IShellContextMenu : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IShellContextMenuVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IShellContextMenu __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IShellContextMenu __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IShellContextMenu __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IShellContextMenu __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IShellContextMenu __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IShellContextMenu __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IShellContextMenu __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } IShellContextMenuVtbl;

    interface IShellContextMenu
    {
        CONST_VTBL struct IShellContextMenuVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellContextMenu_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShellContextMenu_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShellContextMenu_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShellContextMenu_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IShellContextMenu_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IShellContextMenu_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IShellContextMenu_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IShellContextMenu_INTERFACE_DEFINED__ */



#ifndef __SHELLOVERLAYLib_LIBRARY_DEFINED__
#define __SHELLOVERLAYLib_LIBRARY_DEFINED__

/* library SHELLOVERLAYLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SHELLOVERLAYLib;

EXTERN_C const CLSID CLSID_ConflictOverlay;

#ifdef __cplusplus

class DECLSPEC_UUID("E1B54096-34DB-463C-B65F-5C9C1566D6B6")
ConflictOverlay;
#endif

EXTERN_C const CLSID CLSID_ModifiedOverlay;

#ifdef __cplusplus

class DECLSPEC_UUID("F869C1EF-B5E6-4B1F-9B0D-AFB69310823C")
ModifiedOverlay;
#endif

EXTERN_C const CLSID CLSID_IgonredOverlay;

#ifdef __cplusplus

class DECLSPEC_UUID("CE28A651-67AF-409A-9A42-4CFC479FCBE9")
IgonredOverlay;
#endif

EXTERN_C const CLSID CLSID_UnversionedOverlay;

#ifdef __cplusplus

class DECLSPEC_UUID("B413CFE2-F3DF-4456-8FF4-8A7936E6B691")
UnversionedOverlay;
#endif

EXTERN_C const CLSID CLSID_LockedOverlay;

#ifdef __cplusplus

class DECLSPEC_UUID("13203C45-FC5B-4F9D-B851-4AB096BF56B3")
LockedOverlay;
#endif

EXTERN_C const CLSID CLSID_ShellContextMenu;

#ifdef __cplusplus

class DECLSPEC_UUID("4D028AB2-C832-4EB7-9D18-808DA64FF7B2")
ShellContextMenu;
#endif
#endif /* __SHELLOVERLAYLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
