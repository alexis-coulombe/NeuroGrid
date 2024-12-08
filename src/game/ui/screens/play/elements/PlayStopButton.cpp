#include "PlayStopButton.h"
#include "../../../../AssetLibrary.h"
#include "../../../../MissionManager.h"

PlayStopButton::PlayStopButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {
	disabled = true;
}

void PlayStopButton::onRender() {
	Mission *mission = MissionManager::getInstance()->currentMission;

	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_STOP_CODE_IDLE), bounds.position, color, bounds.size);

	disabled = (mission->getNano(Mission::NANO1)->code->error.type != ParserError::NONE ||
			mission->getNano(Mission::NANO2)->code->error.type != ParserError::NONE ||
			mission->getNano(Mission::NANO3)->code->error.type != ParserError::NONE) ||
			!mission->getParsing();
}

void PlayStopButton::onPress() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_STOP_CODE_PRESS), bounds.position, color, bounds.size);
}

void PlayStopButton::onClick() {
	Mission *mission = MissionManager::getInstance()->currentMission;

	mission->nanoParser.stop();
}

void PlayStopButton::onHover() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_STOP_CODE_HOVER), bounds.position, color, bounds.size);
}
