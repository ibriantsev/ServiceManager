#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#include "ServiceManager.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main(void) {
	HRESULT hr = E_UNEXPECTED;
	{
		model::com::ServiceManager m;
		hr = m.init();
		assert(SUCCEEDED(hr));

		std::vector<model::ServiceInfo> result;
		hr = m.enumerateServicesInfo(result);
		assert(SUCCEEDED(hr));

		for (auto s : result)
			std::wcout << s.m_ServiceName << '\t' << s.m_DisplayName << '\t' << s.m_ProcessId << std::endl;
	}
	_CrtDumpMemoryLeaks();
	return hr;
}