#pragma once

#include "ServiceManager.h"
#include "ServiceTableModel.h"
#include "ServiceTableView.h"

namespace controller {
	class ServiceTableController {
	public:
		ServiceTableController(model::ServiceTableModel* const model, view::ServiceTableView* const view);
		void refresh(void);
	private:

		model::com::ServiceManager m_ServiceManager;
		model::ServiceTableModel* const m_ServiceTableModel;
		view::ServiceTableView* const m_ServiceTableView;
	};
} // namespace controller