#pragma once

#include <optional>
#include <windows.h>
#include <winsvc.h>

#include "ServiceResult.h"

namespace ServiceManagement {
	/**
	 * Stores service configuration parameters using constants specified in ServiceConstants.h
	 * 
	 * Can be used by ServiceConfigBuilder to build required configuration.
	 * Passing nullptr as parameter to constuctor creates configuration,
	 * which does not change existing service configuration.
	 */
	struct ServiceConfig {
		ServiceConfig(LPQUERY_SERVICE_CONFIG config = nullptr) noexcept;
		
		ServiceType m_Type;
		ServiceStartType m_StartType;
		ServiceErrorControl m_ErrorControl;
		std::optional<ServiceString> m_StartName;
		std::optional<ServiceString> m_DisplayName;
	};
	
	/**
	 * Manages service configuration using native functions
	 * 
	 * Initially stores empty configuration. Configuration can be refreshed to current state manually 
	 * or when reading one of its parameters.
	 */
	class ServiceConfigController {
		public:
			ServiceConfigController(SC_HANDLE const handle) noexcept: m_Handle(handle) {
			}
			
			ServiceResult refresh(void);
			ServiceResult getStartName(ServiceString &startName);
			ServiceResult getDisplayName(ServiceString &displayName);
		private:
			SC_HANDLE const m_Handle;
			std::optional<ServiceConfig> m_Config;
	};
} // namespace ServiceManagement