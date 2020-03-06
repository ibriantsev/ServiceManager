#pragma once

#include <optional>
#include <vector>
#include <windows.h>
#include <winsvc.h>

#include "ServiceResult.h"

namespace ServiceManagement {
	/**
	 * Stores service configuration parameters using constants specified in ServiceConstants.h
	 *
	 * Passing nullptr as parameter to constuctor creates configuration,
	 * which does not change existing service configuration.
	 */
	struct ServiceConfig {
		ServiceConfig(LPQUERY_SERVICE_CONFIG lpConfig = nullptr) noexcept;
		
		ServiceType                  m_Type;
		ServiceStartType             m_StartType;
		ServiceErrorControl          m_ErrorControl;
		std::optional<ServiceString> m_BinaryPathName;
		std::optional<ServiceString> m_LoadOrderGroup;
		std::optional<DWORD>         m_TagId;
		std::vector<ServiceString>   m_Dependencies;
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
			
			ServiceResult getType(ServiceType &type);
			ServiceResult getStartType(ServiceStartType &startType);
			ServiceResult getErrorControl(ServiceErrorControl &errorControl);
			ServiceResult getBinaryPathName(ServiceString &binaryPathName);
			ServiceResult getLoadOrderGroup(ServiceString &loadOrderGroup);
			ServiceResult getTagId(DWORD &tagId);
			ServiceResult getDependencies(std::vector<ServiceString> &dependencies);
			ServiceResult getStartName(ServiceString &startName);
			ServiceResult getDisplayName(ServiceString &displayName);
		private:
			ServiceResult try_refresh(void);
			
			SC_HANDLE const m_Handle;
			std::optional<ServiceConfig> m_Config;
	};
} // namespace ServiceManagement