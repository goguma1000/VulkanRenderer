#include<QDockWidget>
#include"UI/FloatSlider.h"
#include"MainWindow.h"

#pragma endregion constructor

MainWindow::MainWindow(VulkanWindow* vulkanwindow) {
	QWidget* wrapper = createWindowContainer(vulkanwindow);
	wrapper->setAttribute(Qt::WA_NativeWindow);
	wrapper->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
	setCentralWidget(wrapper);
	
	
	menu = menuBar();
	menu->addMenu(tr("File"));
	menu->addMenu(tr("Edit"));
	menu->addMenu(tr("View"));


	inspectorWidget = new QDockWidget(tr("inspector"), this);
	inspectorWidget->setAllowedAreas(Qt::DockWidgetArea::RightDockWidgetArea);
	addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, inspectorWidget);

	inspectorContents = new QWidget();
	contentLayout = new QVBoxLayout(inspectorContents);
	contentLayout->setAlignment(Qt::AlignmentFlag::AlignTop);

	inspectorWidget->setWidget(inspectorContents);
}


MainWindow::~MainWindow() {
	
}

#pragma endregion

#pragma region public function
void MainWindow::AddFSlider(const char* title, float* value, float min, float max, int precision) {
	QFormLayout* layout = new QFormLayout();
	FloatSlider* slider = new FloatSlider(value, min, max, precision);
	layout->addRow(tr(title), slider);
	contentLayout->addLayout(layout);
}
#pragma endregion

#pragma region private function

#pragma endregion

