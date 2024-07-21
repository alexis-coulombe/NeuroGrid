#include "Window.h"

SDL_Window* Window::window = nullptr;
SDL_Renderer* Window::renderer = nullptr;

int Window::width = 0;
int Window::height = 0;
Vector2 Window::getWindowSize() {
  return {(float) Window::width, (float) Window::height};
}
