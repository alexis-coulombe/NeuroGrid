#include "Font.h"

Font::Font(TTF_Font *handle, uint8_t pointSize) : handle(handle), pointSize(pointSize) {
	pxSize = (float) (pointSize * 1.33);
}