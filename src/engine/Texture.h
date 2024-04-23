//
// Created by acoulombe on 4/12/24.
//

#ifndef ASM_TEXTURE_H
#define ASM_TEXTURE_H

#include <SDL_render.h>
#include "utility/Vector2.h"

class Texture {
public:
    SDL_Texture *handle;
    int width;
    int height;
    Vector2 size = Vector2(0, 0);

    Texture(SDL_Texture *handle, int width, int height);
};


#endif //ASM_TEXTURE_H
