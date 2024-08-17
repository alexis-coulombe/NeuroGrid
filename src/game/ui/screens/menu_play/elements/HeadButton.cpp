#include "HeadButton.h"

HeadButton::HeadButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {
}

void HeadButton::onRender() {
  //Graphics::drawTexture(const_cast<Texture *>(texture), bounds.position, color, bounds.size);
}

void HeadButton::onPress() {
	//Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_ROUNDED_OPENED), bounds.position, color, bounds.size);
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
