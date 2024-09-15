#include "Mission1Button.h"
#include "../../../../mission/Mission1-7/Mission1.h"
#include "../../../../AssetLibrary.h"
#include "../../../../MissionManager.h"

Mission1Button::Mission1Button(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {
}

void Mission1Button::onRender() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_MISSION1_IDLE), bounds.position, color, bounds.size);
}

void Mission1Button::onClick() {
	MissionManager::getInstance()->updateCurrentMission(Mission1::ID);
	*missionDescription = MissionManager::getInstance()->currentMission->getIntro();
}

void Mission1Button::onPress() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_MISSION1_PRESS), bounds.position, color, bounds.size);
}

void Mission1Button::onHover() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_MISSION1_HOVER), bounds.position, color, bounds.size);
}

void Mission1Button::linkMissionDescription(std::vector<std::string> *missionDescription) {
	this->missionDescription = missionDescription;
}
