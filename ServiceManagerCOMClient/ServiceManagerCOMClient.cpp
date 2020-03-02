#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#include "ServiceManager.h"
/*
#define _CRTDBG_MAP_ALLOC
#define _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#include <stdlib.h>
#include <crtdbg.h>
*/

int main(void) {
	com::ServiceManager m;
	
	HRESULT hr = m.init();
	assert(SUCCEEDED(hr));

	std::vector<std::wstring> result;
	hr = m.enumerateServiceNames(result);
	assert(SUCCEEDED(hr));

	for (auto s : result)
		std::wcout << s << std::endl;

	//_CrtDumpMemoryLeaks();
	return hr;
}