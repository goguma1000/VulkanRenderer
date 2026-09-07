#pragma once
#include<QWidget>
#include <QVBoxLayout>
#include<QFormLayout>
#include<QMenubar>
#include <QSlider>
#include<QMainWindow>
#include"VulkanWindow.h"
class MainWindow : public QMainWindow
{
#pragma region constructor
public:
	MainWindow(VulkanWindow* vulkanWindow);
	~MainWindow();
	void AddFSlider(const char* title, float* value, float min, float max, int precision = 3);
private:
	QMenuBar* menu = nullptr;
	QDockWidget* inspectorWidget = nullptr;
	QVBoxLayout* contentLayout = nullptr;
	QWidget* inspectorContents = nullptr;
#pragma endregion
};
