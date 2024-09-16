#include "Color.h"

const Color Color::TRANSPARENT = Color(0, 0, 0, 0);
const Color Color::BLACK_TRANSPARENT_HALF = Color(255, 255, 255, 255 / 2);
const Color Color::BLACK_TRANSPARENT_THIRD = Color(255, 255, 255, 255 / 3);
const Color Color::WHITE = Color(255, 255, 255);
const Color Color::BLACK = Color(0, 0, 0);
const Color Color::RED = Color(255, 0, 0);
const Color Color::GREEN = Color(0, 255, 0);
const Color Color::BLUE = Color(0, 0, 255);
const Color Color::YELLOW = Color(255, 255, 0);
const Color Color::ORANGE = Color(255, 165, 0);
const Color Color::PURPLE = Color(128, 0, 128);
const Color Color::CYAN = Color(0, 255, 255);
const Color Color::MAGENTA = Color(255, 0, 255);
const Color Color::GRAY = Color(128, 128, 128);
const Color Color::LIGHT_GRAY = Color(192, 192, 192);
const Color Color::DARK_GRAY = Color(64, 64, 64);
const Color Color::BROWN = Color(165, 42, 42);
const Color Color::PINK = Color(255, 192, 203);
const Color Color::OLIVE = Color(128, 128, 0);
const Color Color::TEAL = Color(0, 128, 128);
const Color Color::NAVY = Color(0, 0, 128);
const Color Color::MAROON = Color(128, 0, 0);
const Color Color::AQUA = Color(0, 255, 255);

Color::Color(uint8_t r, uint8_t g, uint8_t b) {
	R = r;
	G = g;
	B = b;
	A = 255;
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	R = r;
	G = g;
	B = b;
	A = a;
}

Color::Color(const Color &color, uint8_t a) {
	R = color.R;
	G = color.G;
	B = color.B;
	A = a;
}

std::string Color::toString() const {
	return std::to_string(R) + ", " + std::to_string(G) + ", " + std::to_string(B) + ", " + std::to_string(A);
}

Color Color::withAlpha(uint8_t a) const {
	return {R, G, B, a};
}