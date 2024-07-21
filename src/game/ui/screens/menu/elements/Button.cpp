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
    if (Input::getInstance()->mouseInBounds(bounds) && Input::getInstance()->getMouseButtonDown(Input::MouseButton::LEFT)) {
        if(true) { // if game played once
			GameState::getInstance()->currentState = GameState::INTRO;
		} else {
			GameState::getInstance()->currentState = GameState::MENU_PLAY;
		}
    }
}

void Button::onHover() {
    if (Input::getInstance()->mouseInBounds(bounds)) {
        Graphics::drawRectSolid(bounds, Color::RED);
        //Graphics::drawTexture(texture, bounds.position, Color::WHITE, bounds.size);
    }
}
