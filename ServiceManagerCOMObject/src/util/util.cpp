#include "util.h"

namespace util {
	EXTERN_C IMAGE_DOS_HEADER __ImageBase;
	
	HRESULT getCurrentModuleName(std::wstring& moduleName) {
		HRESULT hr;

		wchar_t temp[MAX_PATH];
		hr = GetModuleFileName((HINSTANCE)&__ImageBase, temp, MAX_PATH);
		if (FAILED(hr)) return hr;

		moduleName = std::move(temp);
		return S_OK;
	}
	
	HRESULT writeRegKey(const std::wstring& key, const std::wstring& value) {
		LONG error;
		HKEY hkResult;

		error = RegCreateKey(HKEY_CLASSES_ROOT, key.c_str(), &hkResult);
		if (error != ERROR_SUCCESS)
			return TYPE_E_REGISTRYACCESS;

		CONST BYTE* data = reinterpret_cast<const BYTE*>(value.c_str());
		DWORD dataSize = value.size() * sizeof(std::wstring::traits_type::char_type);

		error = RegSetValueEx(hkResult, nullptr, 0, REG_SZ, data, dataSize);
		if (error != ERROR_SUCCESS) {
			RegCloseKey(hkResult);
			return TYPE_E_REGISTRYACCESS;
		}

		error = RegCloseKey(hkResult);
		return error != ERROR_SUCCESS ? TYPE_E_REGISTRYACCESS : S_OK;
	}
} // namespace util