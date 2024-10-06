#include "PlayButton.h"
#include "../../../../AssetLibrary.h"
#include "../../../../MissionManager.h"

PlayButton::PlayButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {
}

void PlayButton::onRender() {
	Mission *mission = MissionManager::getInstance()->currentMission;

	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_AUTOPLAY_IDLE), bounds.position, color, bounds.size);

	disabled = (mission->getNano(Mission::NANO1)->code->error.type != ParserError::NONE ||
			mission->getNano(Mission::NANO2)->code->error.type != ParserError::NONE ||
			mission->getNano(Mission::NANO3)->code->error.type != ParserError::NONE) ||
			mission->getAutoStep();
}

void PlayButton::onPress() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_AUTOPLAY_PRESS), bounds.position, color, bounds.size);
}

void PlayButton::onClick() {
	Mission *mission = MissionManager::getInstance()->currentMission;

	if (!mission->getParsing()) {
		mission->setParsing(true);
	}

	mission->setAutoStep(true);
}

void PlayButton::onHover() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_AUTOPLAY_HOVER), bounds.position, color, bounds.size);
}