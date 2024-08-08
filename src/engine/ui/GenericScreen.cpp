#include "GenericScreen.h"

GenericScreen::GenericScreen() {
    screenContainer = Container(nullptr, Bounds2((Window::width / 2) - (std::min((int) Window::width, 1920) / 2), 0, std::min((int) Window::width, 1920), std::min((int) Window::height, 1080)));
}

GenericScreen::~GenericScreen() = default;

void GenericScreen::setBackgroundTexture(Texture *texture) {
    screenContainer.texture = texture;
}