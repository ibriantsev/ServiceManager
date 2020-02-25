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
} // ServiceManagements