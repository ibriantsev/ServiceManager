#include <string>
#include <sstream>
#include <comutil.h>

#include "ServiceManagerObjFactory.h"

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

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

LONG writeRegKey(const std::wstring& key, const std::wstring &value) {
	LONG error;
	HKEY hkResult;
	
	error = RegCreateKey(HKEY_CLASSES_ROOT, key.c_str(), &hkResult);
	if (error != ERROR_SUCCESS)
		return error;
	
	CONST BYTE* data = reinterpret_cast<const BYTE*>(value.c_str());
	DWORD dataSize = value.size() * sizeof(std::wstring::traits_type::char_type);

	error = RegSetValueEx(hkResult, nullptr, 0, REG_SZ, data, dataSize);
	if (error != ERROR_SUCCESS) {
		RegCloseKey(hkResult);
		return error;
	}
	return RegCloseKey(hkResult);
}

STDAPI __stdcall DllRegisterServer(void) {
	std::wstring CLSID;
	HRESULT rs = convertCLSID(CLSID_ServiceManagerObj, CLSID);
	if (FAILED(rs)) return STG_E_INSUFFICIENTMEMORY;
	
	wchar_t temp[MAX_PATH];
	GetModuleFileName((HINSTANCE)&__ImageBase, temp, MAX_PATH);
	std::wstring moduleName(temp);

	std::wstring progId = ServiceManagerObj::ProgID;
	std::wstring descrition = L"COM Object implementing Windows Service Management";

	std::wstring key = L"CLSID\\" + CLSID;
	LONG error;
	error = writeRegKey(key, descrition);
	if (error != ERROR_SUCCESS) return TYPE_E_REGISTRYACCESS;
	error = writeRegKey(key + L"\\InprocServer32", moduleName);
	if (error != ERROR_SUCCESS) return TYPE_E_REGISTRYACCESS;
	error = writeRegKey(key + L"\\ProgId", progId);
	if (error != ERROR_SUCCESS) return TYPE_E_REGISTRYACCESS;
	error = writeRegKey(progId, descrition);
	if (error != ERROR_SUCCESS) return TYPE_E_REGISTRYACCESS;
	error = writeRegKey(progId + L"\\CLSID", CLSID);
	if (error != ERROR_SUCCESS) return TYPE_E_REGISTRYACCESS;
	
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