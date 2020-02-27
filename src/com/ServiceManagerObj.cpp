#include <vector>
#include <objbase.h>
#include <atlbase.h>
#include <atlsafe.h>

#include "ServiceManagerObj.h"

long g_ObjCnt = 0;

HRESULT __stdcall ServiceManagerObj::QueryInterface(REFIID riid, void **ppObj) {
	if (riid == IID_IUnknown) {
		*ppObj = static_cast<IServiceManager*>(this);
		AddRef();
		return S_OK;
	}
	if (riid == IID_IServiceManager) {
		*ppObj = static_cast<IServiceManager*>(this);
		AddRef();
		return S_OK;
	}
	
	*ppObj = nullptr;
	return E_NOINTERFACE ;
}

ULONG __stdcall ServiceManagerObj::AddRef() {
	return InterlockedIncrement(&m_RefCnt);
}

ULONG __stdcall ServiceManagerObj::Release() {
	long refCnt = 0;
	
	refCnt = InterlockedDecrement(&m_RefCnt);
	if (refCnt == 0) 
		delete this;
	
	return refCnt;
}

HRESULT __stdcall ServiceManagerObj::init(void) {
	ServiceManagement::ServiceResult res = m_ServiceManager.init();
	if (!res)
		return RPC_E_ACCESS_DENIED;
	
	return S_OK;
}

HRESULT __stdcall ServiceManagerObj::enumetateServiceNames(SAFEARRAY **ppServices) {
	ServiceManagement::ServiceResult res;
	std::vector<ServiceManagement::ServiceString> serviceNames;
	
	res = m_ServiceManager.enumerateServices(serviceNames);
	if (!res)
		return RPC_E_ACCESS_DENIED;
	
	CComSafeArray<BSTR> result;
	for (auto &x : serviceNames) {
		CComBSTR bs(x.data());
		HRESULT hr = result.Add(bs, FALSE);
		
		if (FAILED(hr))
			AtlThrow(hr);
	}
	
	*ppServices = result.Detach();
	return S_OK;
}