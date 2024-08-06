#include "Vector2i.h"

Vector2i::Vector2i() {
	x = 0;
	y = 0;
}

Vector2i::Vector2i(int32_t x, int32_t y) {
	this->x = x;
	this->y = y;
}

std::string Vector2i::toString() const {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vector2i Vector2i::operator+(const Vector2i& vector) {
	return {x + vector.x, y + vector.y};
}

Vector2i Vector2i::operator-(const Vector2i& vector) {
	return {x - vector.x, y - vector.y};
}

Vector2i Vector2i::operator*(const Vector2i& vector) {
	return {x * vector.x, y * vector.y};
}

Vector2i Vector2i::operator/(const Vector2i& vector) {
	return {x / vector.x, y / vector.y};
}

Vector2i Vector2i::operator*(int32_t scalar) {
	return {x * scalar, y * scalar};
}

Vector2i Vector2i::operator/(int32_t scalar) {
	return {x / scalar, y / scalar};
}

bool Vector2i::operator==(const Vector2i& vector) {
	return x == vector.x && y == vector.y;
}

bool Vector2i::operator!=(const Vector2i& vector) {
	return x != vector.x || y != vector.y;
}

float Vector2i::Dot(const Vector2i& vector) {
	return x * vector.x + y * vector.y;
}

float Vector2i::Cross(const Vector2i& vector) {
	return x * vector.y - y * vector.x;
}

