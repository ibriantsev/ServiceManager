

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for C:/Users/briantsev/source/repos/ServiceManager/ServiceManagerCOMObject/includes/com/IServiceManager.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __IServiceManager_h__
#define __IServiceManager_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IServiceManager_FWD_DEFINED__
#define __IServiceManager_FWD_DEFINED__
typedef interface IServiceManager IServiceManager;

#endif 	/* __IServiceManager_FWD_DEFINED__ */


#ifndef __ServiceManagerObj_FWD_DEFINED__
#define __ServiceManagerObj_FWD_DEFINED__

#ifdef __cplusplus
typedef class ServiceManagerObj ServiceManagerObj;
#else
typedef struct ServiceManagerObj ServiceManagerObj;
#endif /* __cplusplus */

#endif 	/* __ServiceManagerObj_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __ServiceManagement_LIBRARY_DEFINED__
#define __ServiceManagement_LIBRARY_DEFINED__

/* library ServiceManagement */
/* [version][uuid] */ 

typedef /* [uuid] */  DECLSPEC_UUID("12ceaef9-7319-47dd-bf6e-ce01dc87e6ff") 
enum EServiceState
    {
        Stopped	= 0,
        StartPending	= ( Stopped + 1 ) ,
        StopPending	= ( StartPending + 1 ) ,
        Running	= ( StopPending + 1 ) ,
        ContinuePending	= ( Running + 1 ) ,
        PausePending	= ( ContinuePending + 1 ) ,
        Paused	= ( PausePending + 1 ) 
    } 	EServiceState;

/* [uuid] */ struct  DECLSPEC_UUID("57973979-ae63-48df-a553-89d61ed1f099") TServiceInfo
    {
    BSTR m_ServiceName;
    BSTR m_DisplayName;
    ULONG m_Type;
    EServiceState m_CurrentState;
    ULONG m_ProcessId;
    } ;

EXTERN_C const IID LIBID_ServiceManagement;

#ifndef __IServiceManager_INTERFACE_DEFINED__
#define __IServiceManager_INTERFACE_DEFINED__

/* interface IServiceManager */
/* [uuid][object] */ 


EXTERN_C const IID IID_IServiceManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9490e8d9-ca97-4ffe-81f1-c6d125479c1f")
    IServiceManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE init( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE enumetateServicesInfo( 
            /* [retval][out] */ SAFEARRAY * *ppServices) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IServiceManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IServiceManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IServiceManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IServiceManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *init )( 
            IServiceManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *enumetateServicesInfo )( 
            IServiceManager * This,
            /* [retval][out] */ SAFEARRAY * *ppServices);
        
        END_INTERFACE
    } IServiceManagerVtbl;

    interface IServiceManager
    {
        CONST_VTBL struct IServiceManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServiceManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IServiceManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IServiceManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IServiceManager_init(This)	\
    ( (This)->lpVtbl -> init(This) ) 

#define IServiceManager_enumetateServicesInfo(This,ppServices)	\
    ( (This)->lpVtbl -> enumetateServicesInfo(This,ppServices) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IServiceManager_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ServiceManagerObj;

#ifdef __cplusplus

class DECLSPEC_UUID("4fa8f5b0-f690-4152-90c4-32d67c26e4a8")
ServiceManagerObj;
#endif
#endif /* __ServiceManagement_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


