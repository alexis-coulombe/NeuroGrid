#include "PlayNewGameButton.h"
#include "../../../../GameState.h"

PlayNewGameButton::PlayNewGameButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {
}

void PlayNewGameButton::onRender() {
	Graphics::drawTexture(texture, bounds.position, color, bounds.size);
}

void PlayNewGameButton::onClick() {
	if (false) { // if game played once
		GameState::getInstance()->currentState = GameState::sIntro;
	} else {
		GameState::getInstance()->currentState = GameState::sMenuPlay;
	}
}

void PlayNewGameButton::onHover() {
	Graphics::drawRectSolid(bounds, Color::RED);
}
