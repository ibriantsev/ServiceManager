#define UNICODE
#pragma comment(lib,"advapi32.lib") 

#include <iostream>
#include <windows.h>
#include <winsvc.h>

#include "ServiceManagement/Service.h"

int main(void) {
	SC_HANDLE mgrHandle = ::OpenSCManager(nullptr, nullptr, GENERIC_READ);
	
	if (mgrHandle) {
		SC_HANDLE srvHandle = ::OpenService(mgrHandle, L"DellClientManagementService", GENERIC_READ);
		std::cout << (srvHandle == nullptr) << std::endl;
		
		ServiceManagement::Service testService(srvHandle);
		
		::CloseServiceHandle(mgrHandle);
	}
	
	return EXIT_SUCCESS;
}