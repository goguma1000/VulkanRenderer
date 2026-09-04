#include<QDockWidget>
#include <QVBoxLayout>
#include <QSlider>
#include"MainWindow.h"
#include<QMenubar>
#include<QSplitter>
#include<QTimer>

#pragma endregion constructor

MainWindow::MainWindow(VulkanWindow* vulkanwindow) {
	QWidget* wrapper = createWindowContainer(vulkanwindow);
	wrapper->setAttribute(Qt::WA_NativeWindow);
	wrapper->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
	setCentralWidget(wrapper);
	
	

	QMenuBar* menu = menuBar();

	menu->addMenu(tr("File"));
	menu->addMenu(tr("Edit"));
	menu->addMenu(tr("View"));

	


	QDockWidget* inspectorWidget = new QDockWidget(tr("inspector"), this);
	inspectorWidget->setAllowedAreas(Qt::DockWidgetArea::RightDockWidgetArea);
	QLayout* inspectorLayout = new QVBoxLayout();
	inspectorWidget->setLayout(inspectorLayout);
	addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, inspectorWidget);
}

MainWindow::~MainWindow() {
	
}

#pragma endregion
