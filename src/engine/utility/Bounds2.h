#ifndef ASM_BOUNDS2_H
#define ASM_BOUNDS2_H

#include "Vector2f.h"
#include "Vector2i.h"
#include <string>

class Bounds2 {
 public:
	Vector2f position = Vector2f(0, 0);
	Vector2f size = Vector2f(0, 0);

	Bounds2(Vector2f position, Vector2f size);
	Bounds2(Vector2i position, Vector2i size);
	Bounds2(float x, float y, float width, float height);
	Bounds2(int32_t x, int32_t y, int32_t width, int32_t height);

	std::string toString();
	bool contains(Vector2f point) const;
	bool overlaps(Bounds2 bounds) const;
};

#endif //ASM_BOUNDS2_H
