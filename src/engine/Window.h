#ifndef ASM_WINDOW_H
#define ASM_WINDOW_H

#include <SDL.h>
#include <iostream>
#include "utility/Vector2.h"

class Window {
public:
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static int width, height;

	static Vector2 getWindowSize();
};

#endif //ASM_WINDOW_H
