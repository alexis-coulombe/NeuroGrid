#include "Color.h"

const Color Color::TRANSPARENT = Color(0, 0, 0, 0);
const Color Color::TRANSPARENT_HALF = Color(255, 255, 255, 255 / 2);
const Color Color::TRANSPARENT_THIRD = Color(255, 255, 255, 255 / 3);
const Color Color::WHITE = Color(255, 255, 255);
const Color Color::BLACK = Color(0, 0, 0);
const Color Color::RED = Color(255, 0, 0);
const Color Color::GREEN = Color(0, 255, 0);
const Color Color::BLUE = Color(0, 0, 255);

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

std::string Color::toString() const {
	return std::to_string(R) + ", " + std::to_string(G) + ", " + std::to_string(B) + ", " + std::to_string(A);
}

Color Color::withAlpha(uint8_t a) const {
	return {R, G, B, a};
}