#pragma once
#include <QWindow>
#include <QKeyEvent>
#include <functional>
#include "Renderer.h"
#include "Camera.hpp"

class Renderer;
class VulkanWindow : public QWindow
{
public:
	VulkanWindow (int _width = 800, int _height = 600);
	~VulkanWindow ();
	void GetFramebufferSize(int* width, int* height);
	void SetRenderer(Renderer* _renderer);
	void SetKeyProcessCallback(std::function<void(Qt::Key, float)>_func);
	void SetMouseCallback(std::function<void(Qt::MouseButton, float, float)>_func);
	Camera* mainCamera = nullptr;
	bool initialized = false;
protected:
	bool event(QEvent* event) override;
	void exposeEvent(QExposeEvent* event) override;
	void resizeEvent(QResizeEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;
	void keyReleaseEvent(QKeyEvent* event)override;
	void mouseMoveEvent(QMouseEvent* event)override;
	void mouseReleaseEvent(QMouseEvent* event)override;
	void mousePressEvent(QMouseEvent* event)override;
private:
	Renderer* renderer = nullptr;
	std::function<void(Qt::Key, float)>keyProcessCallbackFunc = nullptr;
	std::function<void(Qt::MouseButton, float, float)>mouseCallBackFunc = nullptr;
	int pressedKey = 0;
	int pressedMouseBtn = 0;
};
