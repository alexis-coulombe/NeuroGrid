#ifndef ASM_VECTOR2I_H
#define ASM_VECTOR2I_H

#include <string>

class Vector2i {
 public:
	int32_t x;
	int32_t y;

	Vector2i();
	Vector2i(int32_t x, int32_t y);
	float Dot(const Vector2i &vector);
	float Cross(const Vector2i &vector);
	std::string toString() const;

	Vector2i operator+(const Vector2i &vector);
	Vector2i operator-(const Vector2i &vector);
	Vector2i operator*(const Vector2i &vector);
	Vector2i operator/(const Vector2i &vector);
	Vector2i operator*(int32_t scalar);
	Vector2i operator/(int32_t scalar);
	bool operator==(const Vector2i &vector);
	bool operator!=(const Vector2i &vector);
};

#endif //ASM_VECTOR2I_H
