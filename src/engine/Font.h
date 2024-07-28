#ifndef ASM_FONT_H
#define ASM_FONT_H

#include "SDL_ttf.h"

class Font {
public:
    TTF_Font *handle;
		uint8_t pointsize;

    explicit Font(TTF_Font *handle, int pointsize);
};

#endif //ASM_FONT_H
