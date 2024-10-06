#include "QuitPopup.h"

QuitPopup::QuitPopup(Bounds2 bounds) : GenericPopup(bounds) {
	popupContainer = new Container(nullptr, bounds);
	textContainer = new Container(popupContainer, Bounds2(0, 0, (int32_t) bounds.size.x, (int32_t) bounds.size.y / 4 * 3));
	buttonContainer = new Container(popupContainer, Bounds2(0, (int32_t) bounds.size.y / 4 * 3, (int32_t) bounds.size.x, (int32_t) bounds.size.y / 4));
	quitButtonContainer = new Container(buttonContainer, Bounds2(0, 0, (int32_t) bounds.size.x / 2, (int32_t) bounds.size.y / 4));
	continueButtonContainer = new Container(buttonContainer, Bounds2((int32_t) bounds.size.x / 2, 0, (int32_t) bounds.size.x / 2, (int32_t) bounds.size.y / 4));
}

void QuitPopup::onShow() {
	quitButton = new QuitToMenuButton(quitButtonContainer, Bounds2(0, 0, (int32_t) quitButtonContainer->bounds.size.x, (int32_t) quitButtonContainer->bounds.size.y), Color(Color::WHITE, 0xFF), zLevel);
	quitButton->linkPopup(this);

	continueButton = new ContinueButton(continueButtonContainer, Bounds2(0, 0, (int32_t) continueButtonContainer->bounds.size.x, (int32_t) continueButtonContainer->bounds.size.y), Color(Color::WHITE, 0xFF), zLevel);
	continueButton->linkPopup(this);
}

void QuitPopup::renderPopup() {
	textContainer->render(true);
	buttonContainer->render(true);
	quitButtonContainer->render(true);
	continueButtonContainer->render(true);

	quitButton->render();
	continueButton->render();
}

void QuitPopup::onHide() {

}