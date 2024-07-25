#include "Button.h"
#include "../../../../GameState.h"

Button::Button(Bounds2 bounds, Texture *texture, Color color) : GenericButton(bounds, texture, color) {

}

void Button::render() {
    Graphics::drawTexture(texture, bounds.position, color, bounds.size);

    onHover();
    onClick();
}

void Button::onClick() {

}

void Button::onHover() {
    if (Input::getInstance()->mouseInBounds(bounds)) {
        Graphics::drawRectSolid(bounds, Color::RED);
    }
}
