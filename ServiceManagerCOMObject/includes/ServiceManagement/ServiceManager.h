#pragma once

#include <vector>
#include <windows.h>
#include <winsvc.h>

#include "Service.h"
#include "ServiceResult.h"

namespace ServiceManagement {
	class ServiceManager {
		public:
			ServiceManager(void) noexcept = default;
			~ServiceManager(void) {
				::CloseServiceHandle(m_MgrHandle);
			}
			
			ServiceResult init(void) {
				m_MgrHandle = ::OpenSCManager(nullptr, nullptr, GENERIC_READ);
				return m_MgrHandle ? ServiceResult() : ServiceResult(TEXT("Error: opening service manager failed: "), GetLastError());
			}
			
			ServiceResult enumerateServicesInfo(std::vector<ServiceInfo> &services) const;
		private:
			SC_HANDLE m_MgrHandle;
	};
} // namespace ServiceManagement