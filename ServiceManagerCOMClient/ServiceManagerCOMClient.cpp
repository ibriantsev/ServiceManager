#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#include "ServiceManager.h"

int main(void) {
	com::ServiceManager m;
	
	HRESULT hr = m.init();
	assert(SUCCEEDED(hr));

	std::vector<std::wstring> result;
	hr = m.enumerateServiceNames(result);
	assert(SUCCEEDED(hr));

	for (auto s : result)
		std::wcout << s << std::endl;

	return hr;
}