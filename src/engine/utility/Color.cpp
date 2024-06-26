//
// Created by acoulombe on 4/12/24.
//

#include "Color.h"

const Color Color::TRANSPARENT = Color(0, 0, 0, 0);
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

std::string Color::toString() {
    return std::to_string(R) + ", " + std::to_string(G) + ", " + std::to_string(B) + ", " + std::to_string(A);
}

Color Color::withAlpha(float a) {
    return {R, G, B, (uint8_t)(a * 255)};
}