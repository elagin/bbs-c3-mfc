

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Feb 24 23:31:42 2011
 */
/* Compiler settings for .\bbsc3mfc.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __bbsc3mfc_h_h__
#define __bbsc3mfc_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __Ibbsc3mfc_FWD_DEFINED__
#define __Ibbsc3mfc_FWD_DEFINED__
typedef interface Ibbsc3mfc Ibbsc3mfc;
#endif 	/* __Ibbsc3mfc_FWD_DEFINED__ */


#ifndef __bbsc3mfc_FWD_DEFINED__
#define __bbsc3mfc_FWD_DEFINED__

#ifdef __cplusplus
typedef class bbsc3mfc bbsc3mfc;
#else
typedef struct bbsc3mfc bbsc3mfc;
#endif /* __cplusplus */

#endif 	/* __bbsc3mfc_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __bbsc3mfc_LIBRARY_DEFINED__
#define __bbsc3mfc_LIBRARY_DEFINED__

/* library bbsc3mfc */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_bbsc3mfc;

#ifndef __Ibbsc3mfc_DISPINTERFACE_DEFINED__
#define __Ibbsc3mfc_DISPINTERFACE_DEFINED__

/* dispinterface Ibbsc3mfc */
/* [uuid] */ 


EXTERN_C const IID DIID_Ibbsc3mfc;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F81D591F-7AF6-4B0F-B9DC-BBCF734DDE3F")
    Ibbsc3mfc : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct Ibbsc3mfcVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Ibbsc3mfc * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Ibbsc3mfc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Ibbsc3mfc * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Ibbsc3mfc * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Ibbsc3mfc * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Ibbsc3mfc * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Ibbsc3mfc * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } Ibbsc3mfcVtbl;

    interface Ibbsc3mfc
    {
        CONST_VTBL struct Ibbsc3mfcVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Ibbsc3mfc_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define Ibbsc3mfc_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define Ibbsc3mfc_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define Ibbsc3mfc_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define Ibbsc3mfc_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define Ibbsc3mfc_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define Ibbsc3mfc_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __Ibbsc3mfc_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_bbsc3mfc;

#ifdef __cplusplus

class DECLSPEC_UUID("02271C5C-0989-4496-B14A-EB2DBB7608F2")
bbsc3mfc;
#endif
#endif /* __bbsc3mfc_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


