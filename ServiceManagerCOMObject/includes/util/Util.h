#pragma once

#include <string>
#include <windows.h>

namespace util {
	HRESULT getCurrentModuleName(std::wstring& moduleName);
	LONG writeRegKey(const std::wstring& key, const std::wstring& value);
} // namespace util