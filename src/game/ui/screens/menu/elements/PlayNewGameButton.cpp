#include "PlayNewGameButton.h"
#include "../../../../GameState.h"
#include "../../../../../engine/fileIO/SaveFileManager.h"
#include "../../../../mission/Mission1-7/Mission1.h"
#include "../../../../MissionManager.h"

PlayNewGameButton::PlayNewGameButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {
	saveFileManager = SaveFileManager();
}

void PlayNewGameButton::onRender() {
	MissionManager::getInstance()->updateCurrentMission(Mission1::ID);
	//GameState::getInstance()->currentState = GameState::sPlay;
	//Graphics::drawTexture(const_cast<Texture *>(texture), bounds.position, color, bounds.size);
}

void PlayNewGameButton::onPress() {
	//Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_ROUNDED_OPENED), bounds.position, color, bounds.size);
}

void PlayNewGameButton::onClick() {
	if (saveFileManager.firstPlay) {
		GameState::getInstance()->currentState = GameState::sIntro;
	} else {
		GameState::getInstance()->currentState = GameState::sMenuPlay;
	}
}

void PlayNewGameButton::onHover() {
	Graphics::drawRectSolid(bounds, Color::RED);
}
