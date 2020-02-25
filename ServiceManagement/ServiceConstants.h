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
} // namespace ServiceManagement