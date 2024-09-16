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
	Color(const Color &color, uint8_t a);
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
	static const Color YELLOW;
	static const Color ORANGE;
	static const Color PURPLE;
	static const Color CYAN;
	static const Color MAGENTA;
	static const Color GRAY;
	static const Color LIGHT_GRAY;
	static const Color DARK_GRAY;
	static const Color BROWN;
	static const Color PINK;
	static const Color OLIVE;
	static const Color TEAL;
	static const Color NAVY;
	static const Color MAROON;
	static const Color AQUA;
};

#endif //ASM_COLOR_H
