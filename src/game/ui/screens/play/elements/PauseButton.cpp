#include "PauseButton.h"
#include "../../../../AssetLibrary.h"
#include "../../../../MissionManager.h"

PauseButton::PauseButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {
}

void PauseButton::onRender() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_PAUSE_IDLE), bounds.position, color, bounds.size);

	// TODO: disabled if not in autoplay
}

void PauseButton::onPress() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_PAUSE_PRESS), bounds.position, color, bounds.size);
}

void PauseButton::onClick() {
	// TODO: pause at current line
}

void PauseButton::onHover() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_PAUSE_HOVER), bounds.position, color, bounds.size);
}