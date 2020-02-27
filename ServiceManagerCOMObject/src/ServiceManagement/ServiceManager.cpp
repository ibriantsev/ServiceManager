#include "ServiceManager.h"

namespace ServiceManagement {
	ServiceResult ServiceManager::enumerateServices(std::vector<ServiceString> &services) const {
		std::vector<ServiceString> temp;
		
		LPENUM_SERVICE_STATUS_PROCESS lpServices = nullptr;
		DWORD cbBufSize = 0, dwBytesNeeded = 0, dwServiceReturned = 0, dwResumeHandle = 0, dwError;
		
		do {
			if(!EnumServicesStatusEx(m_MgrHandle, SC_ENUM_PROCESS_INFO, SERVICE_TYPE_ALL, SERVICE_STATE_ALL, 
															 nullptr, 0, &dwBytesNeeded, &dwServiceReturned, &dwResumeHandle, nullptr)) {
				dwError = GetLastError();
				if(ERROR_MORE_DATA == dwError) {
					cbBufSize = dwBytesNeeded;
					lpServices = (LPENUM_SERVICE_STATUS_PROCESS) LocalAlloc(LMEM_FIXED, cbBufSize);
				} else {
					return ServiceResult(TEXT("Error: enumerating services failed: "), dwError);
				}
			}
			
			if(!EnumServicesStatusEx(m_MgrHandle, SC_ENUM_PROCESS_INFO, SERVICE_TYPE_ALL, SERVICE_STATE_ALL, 
															 reinterpret_cast<LPBYTE>(lpServices), cbBufSize, &dwBytesNeeded, &dwServiceReturned, nullptr, nullptr)) {
				LocalFree(lpServices);
				return ServiceResult(TEXT("Error: enumerating services failed: "), GetLastError());
			}
			
			for (DWORD i = 0; i < dwServiceReturned; ++i) {
				temp.push_back(lpServices[i].lpServiceName);
			}
			
			LocalFree(lpServices);
		} while (dwResumeHandle);
		
		services = std::move(temp);
		return ServiceResult();
	}
} // namespace ServiceManagement