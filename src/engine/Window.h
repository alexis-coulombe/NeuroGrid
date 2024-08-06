#ifndef ASM_WINDOW_H
#define ASM_WINDOW_H

#include <SDL.h>
#include "utility/Vector2i.h"

class Window {
 public:
	static inline SDL_Window *window = nullptr;
	static inline SDL_Renderer *renderer = nullptr;
	static inline uint32_t width = 0;
	static inline uint32_t height = 0;

	static Vector2i getWindowSize();
};

#endif //ASM_WINDOW_H
