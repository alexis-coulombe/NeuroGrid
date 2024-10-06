#include "ContinueButton.h"
#include "../../../../../AssetLibrary.h"
#include "../../../../../GameState.h"

ContinueButton::ContinueButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {
}

void ContinueButton::onRender() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_AUTOPLAY_IDLE), bounds.position, color, bounds.size);
}

void ContinueButton::onPress() {

}

void ContinueButton::onClick() {
	popup->hide();
}

void ContinueButton::onHover() {

}

void ContinueButton::linkPopup(GenericPopup *popup) {
	this->popup = popup;
}