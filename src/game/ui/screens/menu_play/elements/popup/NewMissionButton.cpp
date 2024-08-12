#include "NewMissionButton.h"
#include "../../../../../GameState.h"
#include "../../../../../MissionManager.h"
#include "../../../../../mission/Mission1.h"

NewMissionButton::NewMissionButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {

}

void NewMissionButton::onRender() {
	Graphics::drawTexture(texture, bounds.position, color, bounds.size);
}

void NewMissionButton::onClick() {
	MissionManager::getInstance()->updateCurrentMission(Mission1::ID);
	GameState::getInstance()->currentState = GameState::sPlay;
}

void NewMissionButton::onHover() {
	Graphics::drawRectSolid(bounds, Color::RED);
}

