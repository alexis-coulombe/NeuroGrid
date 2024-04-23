//
// Created by acoulombe on 4/13/24.
//

#ifndef ASM_ASSET_H
#define ASM_ASSET_H

#include <iostream>
#include <SDL_mixer.h>
#include "../Texture.h"
#include "SDL_image.h"
#include "../Font.h"
#include "SDL_ttf.h"
#include "../Window.h"

class Asset {
public:
    static Texture *loadTexture(char *path);

    static Font *loadFont(char *path, int pointSize);

    static Mix_Chunk *loadSound(char *path);

    static Mix_Music *loadMusic(char *path);
};


#endif //ASM_ASSET_H
