#pragma once

#include <vector>
#include <windows.h>
#include <winsvc.h>

#include "ServiceResult.h"
#include "Service.h"

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
			
			ServiceResult enumerateServices(std::vector<ServiceInfo> &services) const;
		private:
			SC_HANDLE m_MgrHandle;
	};
} // namespace ServiceManagement