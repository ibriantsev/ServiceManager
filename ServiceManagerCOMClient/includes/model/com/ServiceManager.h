#pragma once

#include <vector>
#include <string>
#include <objbase.h>
#include <atlbase.h>
#include <atlsafe.h>

#include "IServiceManager.h"
#include "GUIDS.c"

//class __declspec(uuid("{4fa8f5b0-f690-4152-90c4-32d67c26e4a8}")) ServiceManagerObj;

namespace com {
	class ServiceManager {
	public:
		ServiceManager(void) = default;
		~ServiceManager(void);
		
		HRESULT init(void);
		HRESULT enumerateServiceNames(std::vector<std::wstring>& serviceNames) const;
	private:
		IServiceManager* m_Manager;
	};
} // namespace com