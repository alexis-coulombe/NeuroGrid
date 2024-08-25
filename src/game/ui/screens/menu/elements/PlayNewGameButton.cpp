#include "PlayNewGameButton.h"
#include "../../../../GameState.h"
#include "../../../../../engine/fileIO/SaveFileManager.h"

PlayNewGameButton::PlayNewGameButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {
}

void PlayNewGameButton::onRender() {
	//Graphics::drawTexture(const_cast<Texture *>(texture), bounds.position, color, bounds.size);
}

void PlayNewGameButton::onPress() {
	//Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_ROUNDED_OPENED), bounds.position, color, bounds.size);
}

void PlayNewGameButton::onClick() {
	if (!SaveFileManager::hasSaveFile()) {
		GameState::getInstance()->currentState = GameState::sIntro;
	} else {
		GameState::getInstance()->currentState = GameState::sMenuPlay;
	}
}

void PlayNewGameButton::onHover() {
	Graphics::drawRectSolid(bounds, Color::RED);
}
