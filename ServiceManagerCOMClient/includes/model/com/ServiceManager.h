#pragma once

#include <vector>
#include <string>
#include <objbase.h>
#include <atlbase.h>
#include <atlsafe.h>

#include "ServiceInfo.h"
#include "IServiceManager.h"
#include "GUIDS.c"

//class __declspec(uuid("{4fa8f5b0-f690-4152-90c4-32d67c26e4a8}")) ServiceManagerObj;
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