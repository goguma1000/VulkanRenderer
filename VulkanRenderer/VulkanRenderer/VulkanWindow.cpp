#include <VulkanWindow.h>

VulkanWindow::VulkanWindow::VulkanWindow(int _width, int _height)
{
	resize(_width, _height);
	this->setSurfaceType(QSurface::VulkanSurface);
}

VulkanWindow::VulkanWindow ::~VulkanWindow()
{

}
#pragma region public func
void VulkanWindow::GetFramebufferSize(int* width, int* height) {
	*width = this->width();
	*height = this->height();
}

void VulkanWindow::SetRenderer(Renderer* _renderer) {
	renderer = _renderer;
}

void VulkanWindow::SetKeyProcessCallback(std::function<void(Qt::Key, float)>_func) {
	if (_func != nullptr) keyProcessCallbackFunc = _func;
	else std::cout << "KeyProcessCallback function is nullptr!\n";
	return;
}

void VulkanWindow::SetMouseCallback(std::function<void(Qt::MouseButton, float, float)>_func) {
	if (_func != nullptr) mouseCallBackFunc = _func;
	else std::cout << "Mouse Callback function is nullptr! \n";
	return;
}
#pragma endregion

#pragma region private function
void VulkanWindow::renderScene() {
	float deltatime = renderer->GetDeltaTime();
	if (keyProcessCallbackFunc != nullptr) {
		keyProcessCallbackFunc(Qt::Key(pressedKey), deltatime);
	}
	renderer->Render();
	requestUpdate();
}
#pragma endregion


#pragma region override functions
bool VulkanWindow::event(QEvent* event) {
	switch (event->type()) {
	case QEvent::UpdateRequest: {
		if (isExposed()) {
			renderScene();
		}
		break;
	}
	case QEvent::FocusOut: {
		pressedKey = 0;
		pressedMouseBtn = 0;
		break;
	}
	default:
		break;
	}
	return QWindow::event(event);
}

void VulkanWindow::exposeEvent(QExposeEvent* event) {
	if (isExposed()) {
		renderer->ResetTimer();
		//first frame render
		renderScene();
	}
}

void VulkanWindow::resizeEvent(QResizeEvent* event) {
	if (renderer == nullptr) return;
	renderer->FramebufferResizeCallback();
}

void VulkanWindow::keyPressEvent(QKeyEvent* event) {
	if (windowState() & Qt::WindowState::WindowMinimized) return;
	pressedKey = event->key();
}

void VulkanWindow::keyReleaseEvent(QKeyEvent* event) {
	if (event->key() == pressedKey) pressedKey = 0;
}

void VulkanWindow::mousePressEvent(QMouseEvent* event) {
	if (pressedMouseBtn == Qt::MouseButton::NoButton) pressedMouseBtn = event->button();
}

void VulkanWindow::mouseReleaseEvent(QMouseEvent* event) {
	if (event->button() == pressedMouseBtn) pressedMouseBtn = 0;
}

void VulkanWindow::mouseMoveEvent(QMouseEvent* event) {
	if (mouseCallBackFunc != nullptr) mouseCallBackFunc(Qt::MouseButton(pressedMouseBtn), event->globalPosition().x(), event->globalPosition().y());
}
#pragma endregion