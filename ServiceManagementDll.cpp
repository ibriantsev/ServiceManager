#include "ServiceManagerObjFactory.h"

STDAPI DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv) {
	if (clsid == CLSID_ServiceManagerObj) {
		ServiceManagerObjFactory* pObjFact = new ServiceManagerObjFactory();

		if (pObjFact == nullptr)
			return E_OUTOFMEMORY;
		else
			return pObjFact->QueryInterface(iid, ppv);
	}
	return CLASS_E_CLASSNOTAVAILABLE;
}

STDAPI DllCanUnloadNow(void) {
	return g_ObjCnt ? S_FALSE : S_OK;
}