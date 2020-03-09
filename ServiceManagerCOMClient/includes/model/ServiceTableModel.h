#pragma once

#include "ServiceInfo.h"

#include <vector>
#include <string>
#include <QAbstractTableModel>

namespace model {
  class ServiceTableModel : public QAbstractTableModel {
    Q_OBJECT
  public:
    ServiceTableModel(QObject* parent = nullptr);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    void setData(const std::vector<ServiceInfo>& data);
  private:
    std::vector<ServiceInfo> m_Data;
  };
}