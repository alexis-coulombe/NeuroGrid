//
// Created by acoulombe on 4/12/24.
//

#ifndef ASM_VECTOR2_H
#define ASM_VECTOR2_H

#include <string>

class Vector2 {
public:
    float x;
    float y;

    Vector2(float x, float y);
    float Dot(const Vector2& vector);
    float Cross(const Vector2& vector);
    std::string toString();

    Vector2 operator+(const Vector2& vector);
    Vector2 operator-(const Vector2& vector);
    Vector2 operator*(const Vector2& vector);
    Vector2 operator/(const Vector2& vector);
    Vector2 operator*(float scalar);
    Vector2 operator/(float scalar);
    bool operator==(const Vector2& vector);
    bool operator!=(const Vector2& vector);

};


#endif //ASM_VECTOR2_H
