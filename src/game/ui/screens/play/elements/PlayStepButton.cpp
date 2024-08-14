#include "PlayStepButton.h"

PlayStepButton::PlayStepButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {
}

void PlayStepButton::linkMission(Mission *mission) {
	this->mission = mission;
}

void PlayStepButton::onRender() {
	Graphics::drawTexture(texture, bounds.position, color, bounds.size);
}

void PlayStepButton::onClick() {
	if(!mission->getParsing()) {
		mission->setParsing(true);
	}

	mission->nanoParser.step();
}

void PlayStepButton::onHover() {
	Graphics::drawRectSolid(bounds, Color::RED);
}