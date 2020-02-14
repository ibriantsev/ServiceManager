#pragma once

#include <windows.h>

namespace ServiceManagement {
	
	/**
	 * Wrapper for the native Windows Service
	 * 
	 * Provides access for reading and changing service configuration
	 * depending on provided rights. Manages service handle.
	 */
	class Service {
		public:
			Service(SC_HANDLE const handle) noexcept: m_Handle(handle) {
			}
			~Service(void) {
				::CloseServiceHandle(m_Handle);
			}
		private:
			SC_HANDLE const m_Handle;
	};
} // ServiceManagement