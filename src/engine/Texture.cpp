//
// Created by acoulombe on 4/12/24.
//

#include "Texture.h"

Texture::Texture(SDL_Texture *handle, int width, int height) {
    this->handle = handle;
    this->width = width;
    this->height = height;
    this->size = Vector2((float) width, (float) height);
}