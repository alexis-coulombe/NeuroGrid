//
// Created by acoulombe on 4/13/24.
//

#include "Window.h"

SDL_Window* Window::window = nullptr;
SDL_Renderer* Window::renderer = nullptr;

int Window::width = 0;
int Window::height = 0;
