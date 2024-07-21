#ifndef ASM_FONT_H
#define ASM_FONT_H

#include "SDL_ttf.h"

class Font {
public:
    TTF_Font *handle;

    explicit Font(TTF_Font *handle);
};

#endif //ASM_FONT_H
