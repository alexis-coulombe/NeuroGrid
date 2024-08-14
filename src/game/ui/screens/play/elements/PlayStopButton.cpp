#include "PlayStopButton.h"

PlayStopButton::PlayStopButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {
	disabled = true;
}

void PlayStopButton::linkMission(Mission *mission) {
	this->mission = mission;
}

void PlayStopButton::onRender() {
	Graphics::drawTexture(texture, bounds.position, color, bounds.size);

	disabled = !mission->getParsing();
}

void PlayStopButton::onClick() {
	mission->setParsing(false);
}

void PlayStopButton::onHover() {
	Graphics::drawRectSolid(bounds, Color::RED);
}
