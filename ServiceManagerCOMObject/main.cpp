//#pragma comment(lib,"advapi32.lib") 

#include <iostream>
#include <windows.h>
#include <winsvc.h>

#include <cassert>

#include "ServiceManager.h"
#include "Service.h"

using namespace ServiceManagement;

void testServiceManager(void) {
	ServiceManager mgr;
	ServiceResult res;
	std::vector<ServiceInfo> servicesInfo;
	
	res = mgr.init();
	assert(res);
	
	res = mgr.enumerateServicesInfo(servicesInfo);
	assert(res);
	assert(servicesInfo.size() > 0);
	std::cout << servicesInfo.size() << std::endl;

	for (auto& x : servicesInfo) {
		std::wcout << x.m_ServiceName << '\t' << x.m_DisplayName << '\t' << x.m_ProcessId << std::endl;
	}
}

void testService(void) {
	SC_HANDLE mgrHandle = ::OpenSCManager(nullptr, nullptr, GENERIC_READ);
	assert(mgrHandle != nullptr);
	
	SC_HANDLE srvHandle = ::OpenService(mgrHandle, TEXT("Dhcp"), GENERIC_READ);
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
	assert(str == TEXT("C:\\Windows\\system32\\svchost.exe -k LocalServiceNetworkRestricted -p"));
	
	res = testService.getLoadOrderGroup(str);
	assert(res);
	assert(str == TEXT("TDI"));
	
	res = testService.getTagId(tagId);
	assert(res);
	assert(tagId == 0);
	
	res = testService.getDependencies(dependencies);
	assert(res);
	assert(dependencies.size() > 0);
	
	res = testService.getStartName(str);
	assert(res);
	assert(str == TEXT("NT Authority\\LocalService"));
	
	res = testService.getDisplayName(str);
	assert(res);
	assert(str == TEXT("DHCP Client"));
	
	::CloseServiceHandle(mgrHandle);
}

int main(void) {
	testService();
	testServiceManager();
	
	return EXIT_SUCCESS;
}