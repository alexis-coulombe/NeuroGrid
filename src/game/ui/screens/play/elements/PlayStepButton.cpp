#include "PlayStepButton.h"
#include "../../../../AssetLibrary.h"

PlayStepButton::PlayStepButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {
}

void PlayStepButton::linkMission(Mission *mission) {
	this->mission = mission;
}

void PlayStepButton::onRender() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_PLAY_CODE_IDLE), bounds.position, color, bounds.size);

	disabled = mission->getNano(Mission::NANO1)->code->error.type != ParserError::NONE ||
			 	     mission->getNano(Mission::NANO2)->code->error.type != ParserError::NONE ||
						 mission->getNano(Mission::NANO3)->code->error.type != ParserError::NONE;	;
}

void PlayStepButton::onPress() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_PLAY_CODE_PRESS), bounds.position, color, bounds.size);
}

void PlayStepButton::onClick() {
	if(!mission->getParsing()) {
		mission->setParsing(true);
	}

	mission->nanoParser.step();
}

void PlayStepButton::onHover() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_PLAY_CODE_HOVER), bounds.position, color, bounds.size);
}