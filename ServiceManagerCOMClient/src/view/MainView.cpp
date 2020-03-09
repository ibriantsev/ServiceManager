#include "MainView.h"

#include <QVBoxLayout>
#include <QMenuBar>

#include "ServiceManager.h"

namespace view {
  MainView::MainView(void) {
    QWidget* widget = new QWidget;
    setCentralWidget(widget);

    view::ServiceTableView* table = new view::ServiceTableView(widget);
    model::ServiceTableModel* model = new model::ServiceTableModel(this);
    m_ServiceTableController = new controller::ServiceTableController(model, table);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(table);
    widget->setLayout(layout);

    createActions();
    createMenus();

    setMinimumSize(600, 300);
    resize(800, 450);
    refresh();
  }

  void MainView::createActions(void) {
    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    refreshAct = new QAction(tr("&Refresh"), this);
    refreshAct->setShortcuts(QKeySequence::Refresh);
    refreshAct->setStatusTip(tr("Refresh service list"));
    connect(refreshAct, &QAction::triggered, this, &MainView::refresh);
  }

  void MainView::createMenus(void) {
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAct);

    actionMenu = menuBar()->addMenu(tr("&Action"));
    actionMenu->addAction(refreshAct);
  }

  #include "moc_MainView.cpp"
} // namespace view