#pragma once

#include <objbase.h>

#include "ServiceManagerObj.h"

class ServiceManagerObjFactory : public IClassFactory {
	public:
		ServiceManagerObjFactory(void) : m_RefCnt(0) {
			++g_ObjCnt;
		}
		~ServiceManagerObjFactory(void) {
			--g_ObjCnt;
		}
		//interface IUnknown methods 
		HRESULT __stdcall QueryInterface(REFIID riid, void **ppObj);
		ULONG   __stdcall AddRef();
		ULONG   __stdcall Release();
		
		//interface IClassFactory methods 
		HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv);
		HRESULT __stdcall LockServer(BOOL bLock); 
	private:
		long m_RefCnt;
};