#include "Font.h"

Font::Font(TTF_Font *handle, uint8_t pointSize) : handle(handle), pointSize(pointSize) {
	TTF_SizeText(handle, "A", reinterpret_cast<int *>(&textWidth), reinterpret_cast<int *>(&textHeight));
}