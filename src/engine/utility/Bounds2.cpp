#include "Bounds2.h"

Bounds2::Bounds2(Vector2f position, Vector2f size) {
	this->position = position;
	this->size = size;
}

Bounds2::Bounds2(Vector2i position, Vector2i size) {
	this->position = Vector2f((float)position.x, (float)position.y);
	this->size = Vector2f((float)size.x, (float)size.y);
}

Bounds2::Bounds2(float x, float y, float width, float height) {
	this->position = Vector2f(x, y);
	this->size = Vector2f(width, height);
}

Bounds2::Bounds2(int32_t x, int32_t y, int32_t width, int32_t height) {
	this->position = Vector2f((float)x, (float)y);
	this->size = Vector2f((float)width, (float)height);
}

std::string Bounds2::toString() {
	return "(" + position.toString() + ", " + size.toString() + ")";
}

bool Bounds2::contains(Vector2f point) const {
	return point.x >= position.x && point.x <= position.x + size.x && point.y >= position.y && point.y <= position.y + size.y;
}

bool Bounds2::overlaps(Bounds2 bounds) const {
	return position.x < bounds.position.x + bounds.size.x && position.x + size.x > bounds.position.x && position.y < bounds.position.y + bounds.size.y && position.y + size.y > bounds.position.y;
}