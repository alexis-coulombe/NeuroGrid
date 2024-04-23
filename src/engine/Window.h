//
// Created by acoulombe on 4/13/24.
//

#ifndef ASM_WINDOW_H
#define ASM_WINDOW_H

#include <SDL.h>

class Window {
public:
    static SDL_Window* window;
    static SDL_Renderer* renderer;
};

#endif //ASM_WINDOW_H
