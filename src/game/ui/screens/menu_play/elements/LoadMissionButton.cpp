#include "LoadMissionButton.h"

LoadMissionButton::LoadMissionButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {

}

void LoadMissionButton::render() {
  Graphics::drawTexture(texture, bounds.position, color, bounds.size);

  onHover();
  onClick();
}

void LoadMissionButton::onClick() {
  if (zLevel != Input::getInstance()->getMouseZLevel()) {
	return;
  }

	if (Input::getInstance()->mouseInBounds(bounds) && Input::getInstance()->getMouseButtonDown(Input::MouseButton::LEFT)) {
		printf("NewMissionButton clicked\n");
	}
}

void LoadMissionButton::onHover() {
  if (zLevel != Input::getInstance()->getMouseZLevel()) {
	return;
  }

  if (Input::getInstance()->mouseInBounds(bounds)) {
	Graphics::drawRectSolid(bounds, Color::RED);
  }
}

