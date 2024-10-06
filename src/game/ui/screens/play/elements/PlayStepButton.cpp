#include "PlayStepButton.h"
#include "../../../../AssetLibrary.h"
#include "../../../../MissionManager.h"

PlayStepButton::PlayStepButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {
}

void PlayStepButton::onRender() {
	Mission *mission = MissionManager::getInstance()->currentMission;

	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_PLAY_CODE_IDLE), bounds.position, color, bounds.size);

	disabled = (mission->getNano(Mission::NANO1)->code->error.type != ParserError::NONE ||
			mission->getNano(Mission::NANO2)->code->error.type != ParserError::NONE ||
			mission->getNano(Mission::NANO3)->code->error.type != ParserError::NONE) ||
			mission->getAutoStep();
}

void PlayStepButton::onPress() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_PLAY_CODE_PRESS), bounds.position, color, bounds.size);
}

void PlayStepButton::onClick() {
	Mission *mission = MissionManager::getInstance()->currentMission;

	mission->nanoParser.step();
}

void PlayStepButton::onHover() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_PLAY_CODE_HOVER), bounds.position, color, bounds.size);
}