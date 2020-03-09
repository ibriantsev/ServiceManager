#include "ServiceTableView.h"

#include <QHeaderView>
#include <QTextEdit>

namespace view {
	ServiceTableView::ServiceTableView(QWidget* parent = 0): QTableView(parent) {
		horizontalHeader()->setStretchLastSection(true);
		setSortingEnabled(true);

		connect(this, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(onRowClicked(const QModelIndex&)));
	}

	void ServiceTableView::onRowClicked(const QModelIndex& index) const {
		QVariant serviceName = model()->data(index.sibling(index.row(), 0));
		QString t = serviceName.toString();

		QTextEdit* tmp = new QTextEdit(t);
		tmp->show();
	}

	#include "moc_ServiceTableView.cpp"
} // namespace view