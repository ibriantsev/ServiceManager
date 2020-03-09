#pragma once

#include <QMainWindow>
#include <QAction>
#include <QMenu>

#include "ServiceTableModel.h"
#include "ServiceTableView.h"
#include "ServiceTableController.h"

namespace view {
	class MainView : public QMainWindow {
		Q_OBJECT
	public:
		MainView(void);
		~MainView(void) {
			delete m_ServiceTableController;
		}
	private slots:
		void refresh(void) {
			m_ServiceTableController->refresh();
		}
	private:
		void createActions(void);
		void createMenus(void);
		
		QMenu* fileMenu;
		QMenu* actionMenu;
		QAction* exitAct;
		QAction* refreshAct;
		
		controller::ServiceTableController* m_ServiceTableController;
	};
} // namespace view