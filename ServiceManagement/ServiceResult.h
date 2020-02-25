#pragma once

#include <sstream>

#include "ServiceConstants.h"

namespace ServiceManagement {
	/**
	 * Returned by service management functions to detect successful completion of any read/write
	 * operation, which has been done. If the operation has failed, provides message to describe an error
	 */
	class ServiceResult {
		public:
			ServiceResult(void): m_Success(true) {
			}
			ServiceResult(const ServiceString &message, DWORD errorCode)
			: m_Success(false), m_Message(message + std::to_string(errorCode)), m_ErrorCode(errorCode) {
			}
			
			operator bool() const {
				return m_Success;
			}
			ServiceString message(void) const {
				return m_Message;
			}
		private:
			bool m_Success;
			ServiceString m_Message;
			DWORD m_ErrorCode;
	};
} // namespace ServiceManagement