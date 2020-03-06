#pragma once

#include "ServiceManager.h"
#include "ServiceTableView.h"

namespace controller {
	class ServiceTableController {
	public:
		ServiceTableController(view::ServiceTableView* const view);
		void refresh(void);
	private:

		model::com::ServiceManager m_ServiceManager;
		view::ServiceTableView* const m_ServiceTableView;
	};
} // namespace controller