#ifndef ASM_VECTOR2F_H
#define ASM_VECTOR2F_H

#include <string>

class Vector2f {
 public:
	float x;
	float y;

	Vector2f();
	Vector2f(float x, float y);
	float Dot(const Vector2f &vector);
	float Cross(const Vector2f &vector);
	std::string toString() const;

	Vector2f operator+(const Vector2f &vector);
	Vector2f operator-(const Vector2f &vector);
	Vector2f operator*(const Vector2f &vector);
	Vector2f operator/(const Vector2f &vector);
	Vector2f operator*(float scalar);
	Vector2f operator/(float scalar);
	bool operator==(const Vector2f &vector);
	bool operator!=(const Vector2f &vector);
};

#endif //ASM_VECTOR2F_H
