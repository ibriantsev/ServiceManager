#include "ServiceManagerObjFactory.h"

HRESULT __stdcall ServiceManagerObjFactory::CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv) {
	if (pUnknownOuter != nullptr) {
		return CLASS_E_NOAGGREGATION ;
	}
	
	ServiceManagerObj* pObject = new ServiceManagerObj;
	if (pObject == nullptr) {
		return E_OUTOFMEMORY ;
	}
	
	return pObject->QueryInterface(iid, ppv);
}

HRESULT __stdcall ServiceManagerObjFactory::LockServer(BOOL bLock) {
	return E_NOTIMPL;
}