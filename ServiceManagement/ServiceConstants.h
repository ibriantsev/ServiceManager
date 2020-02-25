	/**
	 * Includes all constants and enumerations used to manage services
	 */
#pragma once

#include <string>
#include <winsvc.h>

#ifdef UNICODE
	#define _ServiceString std::wstring
	#define to_string to_wstring
#else
	#define _ServiceString std::string
#endif

namespace ServiceManagement {
	typedef _ServiceString ServiceString;
	
	enum class ServiceType : DWORD {
		KernelDriver       = SERVICE_KERNEL_DRIVER,
		FileSystemDriver   = SERVICE_FILE_SYSTEM_DRIVER,
		Win32OwnProcess    = SERVICE_WIN32_OWN_PROCESS,
		Win32ShareProcess  = SERVICE_WIN32_SHARE_PROCESS,
		InteractiveProcess = SERVICE_INTERACTIVE_PROCESS,
		NoChange           = SERVICE_NO_CHANGE,
	};
	
	enum class ServiceStartType : DWORD {
		Boot     = SERVICE_BOOT_START,
		System   = SERVICE_SYSTEM_START,
		Auto     = SERVICE_AUTO_START,
		Demand   = SERVICE_DEMAND_START,
		Disabled = SERVICE_DISABLED,
		NoChange = SERVICE_NO_CHANGE,
	};
	
	enum class ServiceErrorControl : DWORD {
		Ignore   = SERVICE_ERROR_IGNORE,
		Normal   = SERVICE_ERROR_NORMAL,
		Severe   = SERVICE_ERROR_SEVERE,
		Critical = SERVICE_ERROR_CRITICAL,
		NoChange = SERVICE_NO_CHANGE,
	};
} // namespace ServiceManagement