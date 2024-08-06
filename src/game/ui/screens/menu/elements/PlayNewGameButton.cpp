#include "PlayNewGameButton.h"
#include "../../../../GameState.h"

PlayNewGameButton::PlayNewGameButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {
}

void PlayNewGameButton::render() {
	Graphics::drawTexture(texture, bounds.position, color, bounds.size);

	onHover();
	onClick();
}

void PlayNewGameButton::onClick() {
	if (Input::getInstance()->mouseInBounds(bounds) && Input::getInstance()->getMouseButtonDown(Input::MouseButton::LEFT)) {
		if (false) { // if game played once
			*GameState::getInstance()->currentState = GameState::sIntro;
		} else {
			*GameState::getInstance()->currentState = GameState::sMenuPlay;
		}
	}
}

void PlayNewGameButton::onHover() {
	if (Input::getInstance()->mouseInBounds(bounds)) {
		Graphics::drawRectSolid(bounds, Color::RED);
	}
}
