#pragma once

#include <vector>
#include <string>
#include <objbase.h>
#include <atlbase.h>
#include <atlsafe.h>

#include "ServiceInfo.h"
#include "IServiceManager.h"
#include "GUIDS.c"

namespace model {
	namespace com {
		class ServiceManager {
		public:
			ServiceManager(void) : m_Manager(nullptr) {
			}
			~ServiceManager(void);

			HRESULT init(void);
			HRESULT enumerateServicesInfo(std::vector<ServiceInfo>& result) const;
		private:
			IServiceManager* m_Manager;
		};
	} // namespace com
} // namespace model