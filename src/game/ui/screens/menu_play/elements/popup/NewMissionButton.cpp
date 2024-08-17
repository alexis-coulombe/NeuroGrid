#include "NewMissionButton.h"
#include "../../../../../GameState.h"
#include "../../../../../MissionManager.h"
#include "../../../../../mission/Mission1.h"
#include "../../../../../AssetLibrary.h"

NewMissionButton::NewMissionButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {

}

void NewMissionButton::onRender() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_NEW_GAME_IDLE), bounds.position, color, bounds.size);
}

void NewMissionButton::onPress() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_NEW_GAME_PRESS), bounds.position, color, bounds.size);
}

void NewMissionButton::onClick() {
	MissionManager::getInstance()->updateCurrentMission(Mission1::ID);
	GameState::getInstance()->currentState = GameState::sPlay;
}

void NewMissionButton::onHover() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_NEW_GAME_HOVER), bounds.position, color, bounds.size);
}

