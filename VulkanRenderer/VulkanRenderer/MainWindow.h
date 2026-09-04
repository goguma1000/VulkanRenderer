#pragma once
#include<QWidget>

#include<QMainWindow>
#include"VulkanWindow.h"
class MainWindow : public QMainWindow
{
#pragma region constructor
public:
	MainWindow(VulkanWindow* vulkanWindow);
	~MainWindow();

private:

#pragma endregion
};
