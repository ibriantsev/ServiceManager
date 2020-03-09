#include "ServiceTableModel.h"

#include <QString>

#include "ServiceConstantConverter.h"

namespace model {
	ServiceTableModel::ServiceTableModel(QObject* parent): QAbstractTableModel(parent) {
	}

	QVariant ServiceTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
		if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
			switch (section) {
			case 0:
				return QString("Name");
			case 1:
				return QString("Display Name");
			case 2:
				return QString("Current State");
			case 3:
				return QString("PID");
			case 4:
				return QString("Type");
			}
		}
		return QVariant();
	}

	int ServiceTableModel::rowCount(const QModelIndex& parent) const {
		return m_Data.size();
	}
	int ServiceTableModel::columnCount(const QModelIndex& parent) const {
		return 5;
	}
	QVariant ServiceTableModel::data(const QModelIndex& index, int role) const {
		if (role == Qt::DisplayRole) {
			ServiceInfo info = m_Data[index.row()];

			std::wstring serviceStateWStr;
			std::wstring serviceTypeWStr;
			switch (index.column()) {
			case 0:
				return QString::fromStdWString(info.m_ServiceName);
			case 1:
				return QString::fromStdWString(info.m_ServiceName);
			case 2:
				serviceStateWStr = model::ServiceConstantConverter::convertServiceStateToString(info.m_CurrentState);
				return QString::fromStdWString(serviceStateWStr);
			case 3:
				return qulonglong(info.m_ProcessId);
			case 4:
				serviceTypeWStr = model::ServiceConstantConverter::convertServiceTypeToString(info.m_Type);
				return QString::fromStdWString(serviceTypeWStr);
			default:
				return QVariant();
			}
		}
		if (role == Qt::TextAlignmentRole) {
			return index.column() == 1 || index.column() == 4 ? Qt::AlignVCenter : Qt::AlignCenter;
		}

		return QVariant();
	}
	void ServiceTableModel::setData(const std::vector<ServiceInfo>& data) {
		layoutAboutToBeChanged();
		m_Data = data;
		layoutChanged();
	}

	#include "moc_ServiceTableModel.cpp"
}