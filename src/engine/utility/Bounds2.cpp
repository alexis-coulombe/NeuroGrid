#include "Bounds2.h"

Bounds2::Bounds2(Vector2 position, Vector2 size) {
    this->position = position;
    this->size = size;
}

Bounds2::Bounds2(float x, float y, float width, float height) {
    this->position = Vector2(x, y);
    this->size = Vector2(width, height);
}

Bounds2::Bounds2(int x, int y, int width, int height) {
  this->position = Vector2(x, y);
  this->size = Vector2(width, height);
}

std::string Bounds2::toString() {
    return "(" + position.toString() + ", " + size.toString() + ")";
}

bool Bounds2::contains(Vector2 point) const {
    return point.x >= position.x && point.x <= position.x + size.x && point.y >= position.y && point.y <= position.y + size.y;
}

bool Bounds2::overlaps(Bounds2 bounds) const {
    return position.x < bounds.position.x + bounds.size.x && position.x + size.x > bounds.position.x && position.y < bounds.position.y + bounds.size.y && position.y + size.y > bounds.position.y;
}