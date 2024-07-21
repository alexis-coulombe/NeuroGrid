#ifndef ASM_BOUNDS2_H
#define ASM_BOUNDS2_H

#include "Vector2.h"
#include <string>

class Bounds2 {
public:
    Vector2 position = Vector2(0, 0);
    Vector2 size = Vector2(0, 0);

    Bounds2(Vector2 position, Vector2 size);

    Bounds2(float x, float y, float width, float height);

    std::string toString();

    [[nodiscard]] bool contains(Vector2 point) const;

    [[nodiscard]] bool overlaps(Bounds2 bounds) const;
};

#endif //ASM_BOUNDS2_H
