#pragma once

#include <winsvc.h>

#include "ServiceResult.h"

namespace ServiceManagement {
	class ServiceManager {
		public:
			~ServiceManager(void) {
				::CloseServiceHandle(m_MgrHandle);
			}
			
			static ServiceManager create(ServiceResult &sr) {
				ServiceManager created;
				created.m_MgrHandle = ::OpenSCManager(nullptr, nullptr, GENERIC_READ);
				
				sr = created.m_MgrHandle ? ServiceResult() : ServiceResult(TEXT("Error: opening service manager failed: "), GetLastError());
				return created;
			}
			
		private:
			ServiceManager(void) noexcept = default;
			
			SC_HANDLE m_MgrHandle;
	};
} // namespace ServiceManagement