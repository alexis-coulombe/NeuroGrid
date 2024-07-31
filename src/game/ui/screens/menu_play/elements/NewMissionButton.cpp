#include "NewMissionButton.h"
#include "../../../../GameState.h"

NewMissionButton::NewMissionButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {

}

void NewMissionButton::render() {
  Graphics::drawTexture(texture, bounds.position, color, bounds.size);

  onHover();
  onClick();
}

void NewMissionButton::onClick() {
  if (zLevel != Input::getInstance()->getMouseZLevel()) {
	return;
  }

	if (Input::getInstance()->mouseInBounds(bounds) && Input::getInstance()->getMouseButtonDown(Input::MouseButton::LEFT)) {
		*GameState::getInstance()->currentState = GameState::sPlay;
	}
}

void NewMissionButton::onHover() {
  if (zLevel != Input::getInstance()->getMouseZLevel()) {
	return;
  }

  if (Input::getInstance()->mouseInBounds(bounds)) {
	Graphics::drawRectSolid(bounds, Color::RED);
  }
}

