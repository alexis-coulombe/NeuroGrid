#include "HeadButton.h"

HeadButton::HeadButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {
}

void HeadButton::onRender() {
  Graphics::drawTexture(texture, bounds.position, color, bounds.size);
}

void HeadButton::onClick() {
		popup->show();
}

void HeadButton::onHover() {
	  Graphics::drawRectSolid(bounds, Color::RED);
}

void HeadButton::linkPopup(HeadPopup *popup) {
  this->popup = popup;
}
