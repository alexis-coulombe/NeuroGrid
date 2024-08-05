#include "HeadButton.h"

HeadButton::HeadButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {
}

void HeadButton::render() {
  Graphics::drawTexture(texture, bounds.position, color, bounds.size);

  onHover();
  onClick();
}

void HeadButton::onClick() {
  if(zLevel != Input::getInstance()->getMouseZLevel()){
	return;
  }

	if (Input::getInstance()->mouseInBounds(bounds) && Input::getInstance()->getMouseButtonDown(Input::MouseButton::LEFT)) {
		*showPopupTrigger = true;
		Input::getInstance()->setMouseZLevel(Input::getInstance()->getMouseZLevel() + 1);
	}
}

void HeadButton::onHover() {
  if(zLevel != Input::getInstance()->getMouseZLevel()){
	return;
  }

  if (Input::getInstance()->mouseInBounds(bounds)) {
	Graphics::drawRectSolid(bounds, Color::RED);
  }
}

void HeadButton::linkPopup(bool *popUpShowPtr) {
  showPopupTrigger = popUpShowPtr;
}
