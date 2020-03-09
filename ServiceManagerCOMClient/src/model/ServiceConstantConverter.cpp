#include "ServiceConstantConverter.h"

#include <winsvc.h>
#include <vector>
#include <QString>

namespace view {
	std::wstring ServiceConstantConverter::convertServiceTypeToString(ULONG type) {
		std::vector<std::wstring> acc;
		
		if (!type || (type | SERVICE_TYPE_ALL) != SERVICE_TYPE_ALL)
			return TEXT("Invalid");
		
		if (type & SERVICE_ADAPTER)
			acc.push_back(TEXT("Adapter"));
		
		if (type & SERVICE_RECOGNIZER_DRIVER)
			acc.push_back(TEXT("Recognizer Driver"));
		
		if (type & SERVICE_KERNEL_DRIVER)
			acc.push_back(TEXT("Kernel Driver"));
		
		if (type & SERVICE_FILE_SYSTEM_DRIVER)
			acc.push_back(TEXT("File System Driver"));
		
		if (type & SERVICE_WIN32_OWN_PROCESS)
			acc.push_back(TEXT("Win32 Own Process"));

		if (type & SERVICE_WIN32_SHARE_PROCESS)
			acc.push_back(TEXT("Win32 Share Process"));

		if (type & SERVICE_INTERACTIVE_PROCESS)
			acc.push_back(TEXT("Interactive Process"));

		if (type & SERVICE_USER_OWN_PROCESS)
			acc.push_back(TEXT("User Own Process"));

		if (type & SERVICE_USER_SHARE_PROCESS)
			acc.push_back(TEXT("User Share Process"));
		
		std::wstring result = acc[0];
		acc.erase(acc.begin());
		
		for (auto& x : acc)
			result += TEXT(", ") + x;
		return result;
	}
	std::wstring ServiceConstantConverter::convertServiceStateToString(EServiceState state) {
		switch (state) {
		case Stopped:         return TEXT("Stopped");
		case StartPending:    return TEXT("Starting");
		case StopPending:     return TEXT("Stopping");
		case Running:         return TEXT("Running");
		case ContinuePending: return TEXT("Continuing");
		case PausePending:    return TEXT("Pausing");
		case Paused:          return TEXT("Paused");
		}
	}
} // namespace view