#include "Vector2f.h"

Vector2f::Vector2f() {
		x = 0;
		y = 0;
}

Vector2f::Vector2f(float x, float y) {
    this->x = x;
    this->y = y;
}

std::string Vector2f::toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vector2f Vector2f::operator+(const Vector2f& vector) {
    return {x + vector.x, y + vector.y};
}

Vector2f Vector2f::operator-(const Vector2f& vector) {
    return {x - vector.x, y - vector.y};
}

Vector2f Vector2f::operator*(const Vector2f& vector) {
    return {x * vector.x, y * vector.y};
}

Vector2f Vector2f::operator/(const Vector2f& vector) {
    return {x / vector.x, y / vector.y};
}

Vector2f Vector2f::operator*(float scalar) {
    return {x * scalar, y * scalar};
}

Vector2f Vector2f::operator/(float scalar) {
    return {x / scalar, y / scalar};
}

bool Vector2f::operator==(const Vector2f& vector) {
    return x == vector.x && y == vector.y;
}

bool Vector2f::operator!=(const Vector2f& vector) {
    return x != vector.x || y != vector.y;
}

float Vector2f::Dot(const Vector2f& vector) {
    return x * vector.x + y * vector.y;
}

float Vector2f::Cross(const Vector2f& vector) {
    return x * vector.y - y * vector.x;
}

