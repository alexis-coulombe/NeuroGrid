#include "Font.h"

Font::Font(TTF_Font *handle, int pointsize) {
	this->handle = handle;
	this->pointsize = pointsize;
}