#include "ClosePopupButton.h"

ClosePopupButton::ClosePopupButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {

}

void ClosePopupButton::render() {
  Graphics::drawTexture(texture, bounds.position, color, bounds.size);

  onHover();
  onClick();
}

void ClosePopupButton::onClick() {
  if(zLevel != Input::getInstance()->getMouseZLevel()){
	return;
  }

  if (Input::getInstance()->mouseInBounds(bounds) && Input::getInstance()->getMouseButtonDown(Input::MouseButton::LEFT)) {
	*showPopupTrigger = false;
	Input::getInstance()->setMouseZLevel(Input::getInstance()->getMouseZLevel() - 1);
  }
}

void ClosePopupButton::onHover() {
  if(zLevel != Input::getInstance()->getMouseZLevel()){
	return;
  }

  if (Input::getInstance()->mouseInBounds(bounds)) {
	Graphics::drawRectSolid(bounds, Color::RED);
  }
}

void ClosePopupButton::linkPopup(bool *popUpShowPtr) {
  showPopupTrigger = popUpShowPtr;
}
