#include <iostream>
#include "Asset.h"
#include "../Window.h"
#include "SDL_image.h"

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

	return new Font(handle, pointSize);
}

Mix_Chunk *Asset::loadSound(char *path) {
	Mix_Chunk *handle = Mix_LoadWAV(path);

	if (handle == nullptr) {
		std::cout << "Failed to load music: " + std::string(path) << std::endl;
		throw;
	}

	return handle;
}

Mix_Music *Asset::loadMusic(char *path) {
	Mix_Music *handle = Mix_LoadMUS(path);

	if (handle == nullptr) {
		std::cout << "Failed to load music: " + std::string(path) << std::endl;
		throw;
	}

	return handle;
}
