#include "ServiceConstantConverter.h"

#include <winsvc.h>
#include <vector>
#include <string>

namespace view {
	QString ServiceConstantConverter::convertServiceTypeToString(ULONG type) {
		std::vector<std::string> acc;
		
		if (!type || (type | SERVICE_TYPE_ALL) != SERVICE_TYPE_ALL)
			return "Invalid";
		
		if (type & SERVICE_ADAPTER)
			acc.push_back("Adapter");
		
		if (type & SERVICE_RECOGNIZER_DRIVER)
			acc.push_back("Recognizer Driver");
		
		if (type & SERVICE_KERNEL_DRIVER)
			acc.push_back("Kernel Driver");
		
		if (type & SERVICE_FILE_SYSTEM_DRIVER)
			acc.push_back("File System Driver");
		
		if (type & SERVICE_WIN32_OWN_PROCESS)
			acc.push_back("Win32 Own Process");

		if (type & SERVICE_WIN32_SHARE_PROCESS)
			acc.push_back("Win32 Share Process");

		if (type & SERVICE_INTERACTIVE_PROCESS)
			acc.push_back("Interactive Process");

		if (type & SERVICE_USER_OWN_PROCESS)
			acc.push_back("User Own Process");

		if (type & SERVICE_USER_SHARE_PROCESS)
			acc.push_back("User Share Process");
		
		QString result = QString::fromStdString(acc[0]);
		acc.erase(acc.begin());
		
		for (auto& x : acc)
			result += ", " + QString::fromStdString(x);
		return result;
	}
	QString ServiceConstantConverter::convertServiceStateToString(EServiceState state) {
		switch (state) {
		case Stopped:         return "Stopped";
		case StartPending:    return "Starting";
		case StopPending:     return "Stopping";
		case Running:         return "Running";
		case ContinuePending: return "Continuing";
		case PausePending:    return "Pausing";
		case Paused:          return "Paused";
		}
	}
} // namespace view