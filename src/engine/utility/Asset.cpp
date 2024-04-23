//
// Created by acoulombe on 4/13/24.
//

#include "Asset.h"

Texture *Asset::loadTexture(char *path) {
    SDL_Texture *handle = IMG_LoadTexture(Window::renderer, path);

    if (handle == nullptr) {
        std::cout << "Failed to load texture: " + std::string(path) << std::endl;
        throw;
    }

    Uint32 format;
    int access, width, height;
    SDL_QueryTexture(handle, &format, &access, &width, &height);

    return new Texture(handle, width, height);
}

Font *Asset::loadFont(char *path, int pointSize) {
    TTF_Font *handle = TTF_OpenFont(path, pointSize);

    if (handle == nullptr) {
        std::cout << "Failed to load font: " + std::string(path) << std::endl;
        throw;
    }

    return new Font(handle);
}

Mix_Music *Asset::loadMusic(char *path) {
    Mix_Music *handle = Mix_LoadMUS(path);

    if (handle == nullptr) {
        std::cout << "Failed to load music: " + std::string(path) << std::endl;
        throw;
    }

    return handle;
}
