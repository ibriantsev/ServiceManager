#include "ServiceConfig.h"

#include <iostream>

namespace ServiceManagement {
	ServiceConfig::ServiceConfig(LPQUERY_SERVICE_CONFIG config) noexcept {
		if (config) {
			m_StartName = config->lpServiceStartName;
			m_DisplayName = config->lpDisplayName;
		} else {
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
	
	ServiceResult ServiceConfigController::getStartName(ServiceString &startName) {
		if (!m_Config) {
			ServiceResult sr = refresh();
			if (!sr) return sr;
		}
		
		startName = m_Config.value().m_StartName.value_or(ServiceString());
		return ServiceResult();
	}
	ServiceResult ServiceConfigController::getDisplayName(ServiceString &displayName) {
		if (!m_Config) {
			ServiceResult sr = refresh();
			if (!sr) return sr;
		}
		
		displayName = m_Config.value().m_DisplayName.value_or(ServiceString());
		return ServiceResult();
	}
} // namespace ServiceManagement