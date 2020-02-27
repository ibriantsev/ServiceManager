#include "ServiceManagerObjFactory.h"

HRESULT __stdcall ServiceManagerObjFactory::QueryInterface(REFIID riid, void** ppObj) {
	if (riid == IID_IUnknown) {
		*ppObj = static_cast<IUnknown*>(this);
		AddRef();
		return S_OK;
	}
	if (riid == IID_IClassFactory) {
		*ppObj = static_cast<IClassFactory*>(this);
		AddRef();
		return S_OK;
	}
	
	*ppObj = nullptr;
	return E_NOINTERFACE;
}

ULONG __stdcall ServiceManagerObjFactory::AddRef() {
	return InterlockedIncrement(&m_RefCnt);
}

ULONG __stdcall ServiceManagerObjFactory::Release() {
	long refCnt = 0;
	
	refCnt = InterlockedDecrement(&m_RefCnt);
	if (refCnt == 0)
		delete this;
	
	return refCnt;
}

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