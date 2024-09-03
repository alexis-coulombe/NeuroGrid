#ifndef ASM_FONT_H
#define ASM_FONT_H

#include "SDL_ttf.h"

class Font {
public:
    TTF_Font *handle;
		uint8_t pointSize;
		uint8_t textWidth;
	uint8_t textHeight;

    explicit Font(TTF_Font *handle, uint8_t pointSize);
};

#endif //ASM_FONT_H
