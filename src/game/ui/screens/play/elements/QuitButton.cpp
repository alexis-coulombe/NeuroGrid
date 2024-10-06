#include "QuitButton.h"
#include "../../../../AssetLibrary.h"

QuitButton::QuitButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {
	quitPopup = new QuitPopup(Bounds2((Window::width / 2) - 300, (Window::height / 2) - 125, 600, 250));
}

void QuitButton::onRender() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_POPUP_CLOSE_IDLE), bounds.position, color, bounds.size);

	quitPopup->render(true);
}

void QuitButton::onPress() {

}

void QuitButton::onClick() {
	quitPopup->show();
}

void QuitButton::onHover() {

}