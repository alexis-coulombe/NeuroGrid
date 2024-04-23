//
// Created by acoulombe on 4/13/24.
//

#include "ButtonHead.h"

ButtonHead::ButtonHead(Bounds2 bounds, Texture *texture, Color color) : Button(bounds, texture, color) {

}

void ButtonHead::render() {
    Graphics::drawRectSolid(bounds, color);

    onHover();
    onClick();
}

void ButtonHead::onClick() {
    if (Input::getInstance()->mouseInBounds(bounds) && Input::getInstance()->getMouseButtonDown(Input::MouseButton::LEFT)) {
        printf("ButtonHead clicked\n");
    }
}

void ButtonHead::onHover() {
    if (Input::getInstance()->mouseInBounds(bounds)) {
        Graphics::drawRectSolid(bounds, Color::RED);
        //Graphics::drawTexture(texture, bounds.position, Color::WHITE, bounds.size);
    }
}
