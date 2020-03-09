#include <QApplication>
#include <QVBoxLayout>

#include "ServiceTableModel.h"
#include "ServiceTableView.h"
#include "ServiceTableController.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  QWidget mainWindow;
  mainWindow.setMinimumSize(800, 450);

  view::ServiceTableView* table = new view::ServiceTableView(&mainWindow);
  model::ServiceTableModel* model = new model::ServiceTableModel(&mainWindow);
  controller::ServiceTableController serviceTableController(model, table);
  
  QVBoxLayout* layout = new QVBoxLayout();
  layout->addWidget(table);
  mainWindow.setLayout(layout);
  
  serviceTableController.refresh();
  mainWindow.show();

  return app.exec();
}