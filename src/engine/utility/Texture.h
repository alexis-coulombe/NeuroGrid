#ifndef ASM_TEXTURE_H
#define ASM_TEXTURE_H

#include <SDL_render.h>
#include "Vector2f.h"

class Texture {
 public:
	SDL_Texture *handle;
	uint32_t width;
	uint32_t height;

	Texture(SDL_Texture *handle, uint32_t width, uint32_t height);
};

#endif //ASM_TEXTURE_H
