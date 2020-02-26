#pragma comment(lib,"advapi32.lib") 

#include <iostream>
#include <windows.h>
#include <winsvc.h>

#include <cassert>

#include "ServiceManagement/Service.h"

using namespace ServiceManagement;

void testExistingService(void) {
	SC_HANDLE mgrHandle = ::OpenSCManager(nullptr, nullptr, GENERIC_READ);
	assert(mgrHandle != nullptr);
	
	SC_HANDLE srvHandle = ::OpenService(mgrHandle, L"Dhcp", GENERIC_READ);
	assert(srvHandle != nullptr);
	
	Service testService(srvHandle);
	ServiceType type;
	ServiceStartType startType;
	ServiceErrorControl errorControl;
	ServiceString str;
	DWORD tagId;
	std::vector<ServiceString> dependencies;
	ServiceResult res;
	
	res = testService.getType(type);
	assert(res);
	assert(type == ServiceType::Win32ShareProcess);
	
	res = testService.getStartType(startType);
	assert(res);
	assert(startType == ServiceStartType::Auto);
	
	res = testService.getErrorControl(errorControl);
	assert(res);
	assert(errorControl == ServiceErrorControl::Normal);
	
	res = testService.getBinaryPathName(str);
	assert(res);
	assert(str == L"C:\\Windows\\system32\\svchost.exe -k LocalServiceNetworkRestricted -p");
	
	res = testService.getLoadOrderGroup(str);
	assert(res);
	assert(str == L"TDI");
	
	res = testService.getTagId(tagId);
	assert(res);
	assert(tagId == 0);
	
	res = testService.getDependencies(dependencies);
	assert(res);
	assert(dependencies.size() == 2);
	assert(dependencies[0] == L"NSI");
	assert(dependencies[1] == L"Afd");
	
	res = testService.getStartName(str);
	assert(res);
	assert(str == L"NT Authority\\LocalService");
	
	res = testService.getDisplayName(str);
	assert(res);
	assert(str == L"DHCP Client");
	
	::CloseServiceHandle(mgrHandle);
}

int main(void) {
	testExistingService();
	
	return EXIT_SUCCESS;
}