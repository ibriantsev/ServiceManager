#include <vector>
#include <objbase.h>
#include <atlbase.h>
#include <atlsafe.h>

#include "ServiceManagerObj.h"
#include "ServiceInfoConverter.h"

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

HRESULT __stdcall ServiceManagerObj::enumetateServicesInfo(SAFEARRAY **ppServices) {
	ServiceManagement::ServiceResult res;
	std::vector<ServiceManagement::ServiceInfo> servicesInfo;
	
	res = m_ServiceManager.enumerateServicesInfo(servicesInfo);
	if (!res) return RPC_E_ACCESS_DENIED;
	
	CComSafeArray<VARIANT> result;
	for (auto& x : servicesInfo) {
		HRESULT hr;
		VARIANT variant;
		
		hr = com::ServiceInfoConverter::convertToVariant(x, variant);
		if (FAILED(hr)) AtlThrow(hr);

		hr = result.Add(variant, FALSE);
		if (FAILED(hr)) AtlThrow(hr);
	}
	
	*ppServices = result.Detach();
	return S_OK;
}