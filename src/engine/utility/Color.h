#ifndef ASM_COLOR_H
#define ASM_COLOR_H

#include <string>

class Color {
 public:
	uint8_t R;
	uint8_t G;
	uint8_t B;
	uint8_t A;

	Color(uint8_t r, uint8_t g, uint8_t b);
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	std::string toString() const;
	Color withAlpha(uint8_t a) const;

	static const Color TRANSPARENT;
	static const Color BLACK_TRANSPARENT_HALF;
	static const Color BLACK_TRANSPARENT_THIRD;
	static const Color WHITE;
	static const Color BLACK;
	static const Color RED;
	static const Color GREEN;
	static const Color BLUE;
};

#endif //ASM_COLOR_H
