//
// Created by acoulombe on 4/13/24.
//

#ifndef ASM_WINDOW_H
#define ASM_WINDOW_H

#include <SDL.h>
#include <iostream>

class Window {
public:
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static int width, height;
};

#endif //ASM_WINDOW_H
