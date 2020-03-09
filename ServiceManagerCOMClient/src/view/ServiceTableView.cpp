#include "ServiceTableView.h"

#include <QHeaderView>

namespace view {
	ServiceTableView::ServiceTableView(QWidget* parent = 0): QTableView(parent) {
		horizontalHeader()->setStretchLastSection(true);
		setSortingEnabled(true);
	}
} // namespace view