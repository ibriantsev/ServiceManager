	/**
	 * Includes all constants and enumerations used to manage services
	 */
#pragma once

#include <string>
#include <windows.h>
#include <winsvc.h>

#ifdef UNICODE
	#define _ServiceString std::wstring
	#define to_tstring std::to_wstring
#else
	#define _ServiceString std::string
	#define to_tstring std::to_string
#endif

namespace ServiceManagement {
	typedef _ServiceString ServiceString;
	
	enum class ServiceType : DWORD {
		KernelDriver       = SERVICE_KERNEL_DRIVER,
		FileSystemDriver   = SERVICE_FILE_SYSTEM_DRIVER,
		Win32OwnProcess    = SERVICE_WIN32_OWN_PROCESS,
		Win32ShareProcess  = SERVICE_WIN32_SHARE_PROCESS,
		UserOwnProcess     = SERVICE_USER_OWN_PROCESS,
		UserShareProcess   = SERVICE_USER_SHARE_PROCESS,
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
	
	enum class ServiceState : DWORD {
		Stopped = SERVICE_STOPPED,
		StartPending = SERVICE_START_PENDING,
		StopPending = SERVICE_STOP_PENDING,
		Running = SERVICE_RUNNING,
		ContinuePending = SERVICE_CONTINUE_PENDING,
		PausePending = SERVICE_PAUSE_PENDING,
		Paused = SERVICE_PAUSED
	};
} // namespace ServiceManagement