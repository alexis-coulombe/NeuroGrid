#include "HeadMission1Button.h"

HeadMission1Button::HeadMission1Button(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {

}

void HeadMission1Button::render() {
	Graphics::drawTexture(texture, bounds.position, color, bounds.size);

	onHover();
	onClick();
}

void HeadMission1Button::onClick() {
	if (zLevel != Input::getInstance()->getMouseZLevel()) {
		return;
	}

	if (Input::getInstance()->mouseInBounds(bounds) && Input::getInstance()->getMouseButtonDown(Input::MouseButton::LEFT)) {
		*showMissionInfoTrigger = ID;
	}
}

void HeadMission1Button::onHover() {
	if (zLevel != Input::getInstance()->getMouseZLevel()) {
		return;
	}

	if (Input::getInstance()->mouseInBounds(bounds)) {
		Graphics::drawRectSolid(bounds, Color::RED);
	}
}

void HeadMission1Button::linkMissionInfo(uint8_t *missionInfoShowPtr) {
	showMissionInfoTrigger = missionInfoShowPtr;
}

