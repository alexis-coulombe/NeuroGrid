#include "GenericPopup.h"
#include "../utility/Asset.h"
#include "../../game/AssetLibrary.h"

GenericPopup::GenericPopup(Bounds2 bounds) : bounds(bounds) {
	popupContainer = new Container(nullptr, bounds);
	backgroundOverlay = Asset::loadTexture((char *)"assets/menu/background_black.png");
}

void GenericPopup::show() {
	isVisible = true;
	Input::getInstance()->mouseZLevel++;
	zLevel = Input::getInstance()->mouseZLevel;
	closeButton = new CloseButton(popupContainer, Bounds2((uint32_t)popupContainer->bounds.size.x - 40, 0, 40, 40), Color::WHITE, zLevel);
	closeButton->linkPopup(this);

	onShow();
}

void GenericPopup::render(bool showBounds) {
	if (!isVisible) {
		return;
	}

	if(showBounds) {
		Graphics::drawRectEmpty(bounds, Color::YELLOW);
	}

	if(Input::getInstance()->getKeyDown(Input::Escape)) {
		hide();
	}

	Graphics::drawTexture(backgroundOverlay, Vector2f(0, 0), Color::BLACK_TRANSPARENT_HALF, Vector2f(Window::width, Window::height));
	popupContainer->render();

	renderPopup();
	closeButton->render();
}

void GenericPopup::hide() {
	isVisible = false;
	Input::getInstance()->mouseZLevel--;
	zLevel = 0;

	onHide();
}

CloseButton::CloseButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {

}

void CloseButton::linkPopup(GenericPopup *linkPopup) {
	this->popup = linkPopup;
}

void CloseButton::onRender() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_POPUP_CLOSE_IDLE), bounds.position, color, bounds.size);
}

void CloseButton::onPress() {

}

void CloseButton::onClick() {
	popup->hide();
}

void CloseButton::onHover() {

}