#include "Mission1Button.h"
#include "../../../../mission/Mission1.h"
#include "../../../../GameState.h"

Mission1Button::Mission1Button(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {

}

void Mission1Button::render() {
	Graphics::drawTexture(texture, bounds.position, color, bounds.size);

	onHover();
	onClick();
}

void Mission1Button::onClick() {
	if (zLevel != Input::getInstance()->getMouseZLevel()) {
		return;
	}

	if (Input::getInstance()->mouseInBounds(bounds) && Input::getInstance()->getMouseButtonDown(Input::MouseButton::LEFT)) {
		*showMissionInfoTrigger = Mission1::ID;
	}
}

void Mission1Button::onHover() {
	if (zLevel != Input::getInstance()->getMouseZLevel()) {
		return;
	}

	if (Input::getInstance()->mouseInBounds(bounds)) {
		Graphics::drawRectSolid(bounds, Color::RED);
	}
}

void Mission1Button::linkMissionInfo(uint8_t *missionInfoShowPtr) {
	showMissionInfoTrigger = missionInfoShowPtr;
}

