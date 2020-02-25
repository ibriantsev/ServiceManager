#include "ServiceConfig.h"

#include <iostream>

namespace ServiceManagement {
	ServiceConfig::ServiceConfig(LPQUERY_SERVICE_CONFIG config) noexcept {
		if (config) {
			m_Type = (ServiceType) config->dwServiceType;
			m_StartType = (ServiceStartType) config->dwStartType;
			m_ErrorControl = (ServiceErrorControl) config->dwErrorControl;
			m_StartName = config->lpServiceStartName;
			m_DisplayName = config->lpDisplayName;
		} else {
			m_Type = ServiceType::NoChange;
			m_StartType = ServiceStartType::NoChange;
			m_ErrorControl = ServiceErrorControl::NoChange;
			m_StartName = nullptr;
			m_DisplayName = nullptr;
		}
	}
	
	ServiceResult ServiceConfigController::refresh(void) {
		LPQUERY_SERVICE_CONFIG lpCurrentConfig;
		DWORD dwBytesNeeded, cbBufSize, dwError;
		
		if(!QueryServiceConfig(m_Handle, nullptr, 0, &dwBytesNeeded)) {
			dwError = GetLastError();
			if(ERROR_INSUFFICIENT_BUFFER == dwError) {
				cbBufSize = dwBytesNeeded;
				lpCurrentConfig = (LPQUERY_SERVICE_CONFIG) LocalAlloc(LMEM_FIXED, cbBufSize);
			} else {
				return ServiceResult(L"Error: reading service configuration failed: ", dwError);
			}
		}
		
		if(!QueryServiceConfig(m_Handle, lpCurrentConfig, cbBufSize, &dwBytesNeeded)) {
				LocalFree(lpCurrentConfig);
				return ServiceResult(L"Error: reading service configuration failed: ", GetLastError());
		}
		
		m_Config = ServiceConfig(lpCurrentConfig);
		LocalFree(lpCurrentConfig); 
		
		return ServiceResult();
	}
	
	// aux function to avoid code duplicates
	ServiceResult ServiceConfigController::try_refresh(void) {
		if (!m_Config)
			return refresh();
		
		return ServiceResult();
	}
	
	ServiceResult ServiceConfigController::getType(ServiceType &type) {
		ServiceResult sr = try_refresh();
		if (!sr)
			return sr;
		
		type = m_Config.value().m_Type;
		return ServiceResult();
	}
	ServiceResult ServiceConfigController::getStartType(ServiceStartType &startType) {
		ServiceResult sr = try_refresh();
		if (!sr)
			return sr;
		
		startType = m_Config.value().m_StartType;
		return ServiceResult();
	}
	ServiceResult ServiceConfigController::getErrorControl(ServiceErrorControl &errorControl) {
		ServiceResult sr = try_refresh();
		if (!sr)
			return sr;
		
		errorControl = m_Config.value().m_ErrorControl;
		return ServiceResult();
	}
	ServiceResult ServiceConfigController::getStartName(ServiceString &startName) {
		ServiceResult sr = try_refresh();
		if (!sr)
			return sr;
		
		startName = m_Config.value().m_StartName.value_or(ServiceString());
		return ServiceResult();
	}
	ServiceResult ServiceConfigController::getDisplayName(ServiceString &displayName) {
		ServiceResult sr = try_refresh();
		if (!sr)
			return sr;
		
		displayName = m_Config.value().m_DisplayName.value_or(ServiceString());
		return ServiceResult();
	}
} // namespace ServiceManagement