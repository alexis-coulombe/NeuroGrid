//
// Created by acoulombe on 4/12/24.
//

#include "Vector2.h"

Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
}

std::string Vector2::toString() {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vector2 Vector2::operator+(const Vector2& vector) {
    return Vector2(x + vector.x, y + vector.y);
}

Vector2 Vector2::operator-(const Vector2& vector) {
    return Vector2(x - vector.x, y - vector.y);
}

Vector2 Vector2::operator*(const Vector2& vector) {
    return Vector2(x * vector.x, y * vector.y);
}

Vector2 Vector2::operator/(const Vector2& vector) {
    return Vector2(x / vector.x, y / vector.y);
}

Vector2 Vector2::operator*(float scalar) {
    return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(float scalar) {
    return Vector2(x / scalar, y / scalar);
}

bool Vector2::operator==(const Vector2& vector) {
    return x == vector.x && y == vector.y;
}

bool Vector2::operator!=(const Vector2& vector) {
    return x != vector.x || y != vector.y;
}

float Vector2::Dot(const Vector2& vector) {
    return x * vector.x + y * vector.y;
}

float Vector2::Cross(const Vector2& vector) {
    return x * vector.y - y * vector.x;
}

