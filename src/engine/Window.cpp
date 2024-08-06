#include "Window.h"

Vector2i Window::getWindowSize() {
	return {static_cast<int32_t>(Window::width), static_cast<int32_t>(Window::height)};
}
