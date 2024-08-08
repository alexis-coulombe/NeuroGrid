#include "CloseButton.h"

CloseButton::CloseButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {
}

void CloseButton::onRender() {
    Graphics::drawTexture(bounds.position, texture, color, zLevel);
}

void CloseButton::onClick() {
    popup->hide();
}

void CloseButton::onHover() {

}

void CloseButton::linkPopup(GenericPopup *popup) {
    this->popup = popup;
}