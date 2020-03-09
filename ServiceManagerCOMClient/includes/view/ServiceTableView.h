#pragma once

#include <QTableWidget>

#include "ServiceInfo.h"

namespace view {
	class ServiceTableView : public QTableView {
	public:
		explicit ServiceTableView(QWidget* parent);
	};
} // namespace view