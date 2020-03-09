#pragma once

#include <QTableWidget>

#include "ServiceInfo.h"

namespace view {
	class ServiceTableView : public QTableView {
	Q_OBJECT
	public:
		explicit ServiceTableView(QWidget* parent);
	private slots:
		void onRowClicked(const QModelIndex& index) const;
	};
} // namespace view