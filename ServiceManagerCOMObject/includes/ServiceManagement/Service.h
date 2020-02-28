#pragma once

#include <windows.h>

#include "ServiceConfig.h"

namespace ServiceManagement {
	/**
	 * Wrapper for the native Windows Service
	 * 
	 * Provides access for reading and changing service configuration
	 * depending on provided rights. Manages service handle.
	 */
	class Service {
		public:
			Service(SC_HANDLE const handle) noexcept: m_Handle(handle), m_Config(handle) {
			}
			~Service(void) {
				::CloseServiceHandle(m_Handle);
			}
			
			ServiceResult getType(ServiceType &type) {
				return m_Config.getType(type);
			}
			ServiceResult getStartType(ServiceStartType &startType) {
				return m_Config.getStartType(startType);
			}
			ServiceResult getErrorControl(ServiceErrorControl &errorControl) {
				return m_Config.getErrorControl(errorControl);
			}
			ServiceResult getBinaryPathName(ServiceString &binaryPathName) {
				return m_Config.getBinaryPathName(binaryPathName);
			}
			ServiceResult getLoadOrderGroup(ServiceString &loadOrderGroup) {
				return m_Config.getLoadOrderGroup(loadOrderGroup);
			}
			ServiceResult getTagId(DWORD &tagId) {
				return m_Config.getTagId(tagId);
			}
			ServiceResult getDependencies(std::vector<ServiceString> &dependencies) {
				return m_Config.getDependencies(dependencies);
			}
			ServiceResult getStartName(ServiceString &startName) {
				return m_Config.getStartName(startName);
			}
			ServiceResult getDisplayName(ServiceString &displayName) {
				return m_Config.getDisplayName(displayName);
			}
		private:
			SC_HANDLE const m_Handle;
			ServiceConfigController m_Config;
	};
	
	/**
	 * Stores basic service information
	 * 
	 * Used for enumarating services.
	 */
	struct ServiceInfo {
		ServiceInfo(const ServiceString &serviceName, 
								const ServiceString &displayName, 
								DWORD type,
								DWORD processId, 
								DWORD currentState) noexcept
		: m_ServiceName(serviceName), 
			m_DisplayName(displayName), 
			m_Type(type),
			m_CurrentState(currentState),
			m_ProcessId(processId) {
		}
		
		ServiceString m_ServiceName;
		ServiceString m_DisplayName;
		DWORD m_Type;
		DWORD m_CurrentState;
		DWORD m_ProcessId;
	};
} // ServiceManagements