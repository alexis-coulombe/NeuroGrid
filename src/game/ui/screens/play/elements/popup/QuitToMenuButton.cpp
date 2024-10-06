#include "QuitToMenuButton.h"
#include "../../../../../AssetLibrary.h"
#include "../../../../../GameState.h"

QuitToMenuButton::QuitToMenuButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {
}

void QuitToMenuButton::onRender() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_AUTOPLAY_IDLE), bounds.position, color, bounds.size);
}

void QuitToMenuButton::onPress() {

}

void QuitToMenuButton::onClick() {
	GameState::getInstance()->currentState = GameState::sMenu;
	popup->hide();
}

void QuitToMenuButton::onHover() {

}

void QuitToMenuButton::linkPopup(GenericPopup *popup) {
	this->popup = popup;
}