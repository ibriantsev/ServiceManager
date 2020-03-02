#include <string>
#include <sstream>
#include <comutil.h>

#include "Util.h"
#include "ServiceManagerObjFactory.h"

STDAPI __stdcall DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv) {
	if (clsid == CLSID_ServiceManagerObj) {
		ServiceManagerObjFactory* pObjFact = new ServiceManagerObjFactory();

		if (pObjFact == nullptr)
			return E_OUTOFMEMORY;
		else
			return pObjFact->QueryInterface(iid, ppv);
	}
	return CLASS_E_CLASSNOTAVAILABLE;
}

STDAPI __stdcall DllCanUnloadNow(void) {
	return g_ObjCnt ? S_FALSE : S_OK;
}

HRESULT convertCLSID(CLSID clsid, std::wstring &result) {
	LPOLESTR lpCLSID;

	HRESULT rs = StringFromCLSID(CLSID_ServiceManagerObj, &lpCLSID);
	result = (_bstr_t) lpCLSID;

	return rs;
}

STDAPI __stdcall DllRegisterServer(void) {
	std::wstring CLSID;
	HRESULT rs = convertCLSID(CLSID_ServiceManagerObj, CLSID);
	if (FAILED(rs)) return STG_E_INSUFFICIENTMEMORY;
	
	std::wstring moduleName;
	rs = util::getCurrentModuleName(moduleName);
	if (FAILED(rs)) return rs;

	std::wstring progId = ServiceManagerObj::ProgID;
	std::wstring descrition = L"COM Object implementing Windows Service Management";

	std::wstring key = L"CLSID\\" + CLSID;
	rs = util::writeRegKey(key, descrition);
	if (FAILED(rs)) return rs;
	rs = util::writeRegKey(key + L"\\InprocServer32", moduleName);
	if (FAILED(rs)) return rs;
	rs = util::writeRegKey(key + L"\\ProgId", progId);
	if (FAILED(rs)) return rs;
	rs = util::writeRegKey(progId, descrition);
	if (FAILED(rs)) return rs;
	rs = util::writeRegKey(progId + L"\\CLSID", CLSID);
	if (FAILED(rs)) return rs;
	
	return S_OK;
}

STDAPI __stdcall DllUnregisterServer(void) {
	std::wstring CLSID;
	HRESULT rs = convertCLSID(CLSID_ServiceManagerObj, CLSID);
	if (FAILED(rs)) return STG_E_INSUFFICIENTMEMORY;

	std::wstring progId = ServiceManagerObj::ProgID;

	std::wstring key = L"CLSID\\" + CLSID;
	LONG error;
	error = RegDeleteKey(HKEY_CLASSES_ROOT, (progId + L"\\CLSID").c_str());
	if (error != ERROR_SUCCESS) return TYPE_E_REGISTRYACCESS;
	error = RegDeleteKey(HKEY_CLASSES_ROOT, progId.c_str());
	if (error != ERROR_SUCCESS) return TYPE_E_REGISTRYACCESS;
	error = RegDeleteKey(HKEY_CLASSES_ROOT, (key + L"\\InprocServer32").c_str());
	if (error != ERROR_SUCCESS) return TYPE_E_REGISTRYACCESS;
	error = RegDeleteKey(HKEY_CLASSES_ROOT, (key + L"\\ProgId").c_str());
	if (error != ERROR_SUCCESS) return TYPE_E_REGISTRYACCESS;
	error = RegDeleteKey(HKEY_CLASSES_ROOT, key.c_str());
	if (error != ERROR_SUCCESS) return TYPE_E_REGISTRYACCESS;

	return S_OK;
}