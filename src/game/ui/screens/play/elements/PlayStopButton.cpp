#include "PlayStopButton.h"
#include "../../../../AssetLibrary.h"

PlayStopButton::PlayStopButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {
	disabled = true;
}

void PlayStopButton::linkMission(Mission *mission) {
	this->mission = mission;
}

void PlayStopButton::onRender() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_STOP_CODE_IDLE), bounds.position, color, bounds.size);

	disabled = !mission->getParsing();
}

void PlayStopButton::onPress() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_STOP_CODE_PRESS), bounds.position, color, bounds.size);
}

void PlayStopButton::onClick() {
	mission->setParsing(false);
}

void PlayStopButton::onHover() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_STOP_CODE_HOVER), bounds.position, color, bounds.size);
}
