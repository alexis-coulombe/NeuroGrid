#include "FinishedWinPopup.h"

FinishedWinPopup::FinishedWinPopup(Bounds2 bounds) : GenericPopup(bounds) {
	graphContainer = new Container(popupContainer, Bounds2(Vector2f(0, 0), Vector2f(popupContainer->bounds.size.x, popupContainer->bounds.size.y / 4 * 3)));

	buttonContainer = new Container(popupContainer, Bounds2(Vector2f(0, popupContainer->bounds.size.y / 4 * 3), Vector2f(popupContainer->bounds.size.x, popupContainer->bounds.size.y / 4)));
	continueButtonContainer = new Container(buttonContainer, Bounds2(Vector2f(0, 0), Vector2f(buttonContainer->bounds.size.x / 2, buttonContainer->bounds.size.y)));
	quitButtonContainer = new Container(buttonContainer, Bounds2(Vector2f(buttonContainer->bounds.size.x / 2, 0), Vector2f(buttonContainer->bounds.size.x / 2, buttonContainer->bounds.size.y)));
}

void FinishedWinPopup::onShow() {

}

void FinishedWinPopup::renderPopup() {
	graphContainer->render(true);
	buttonContainer->render(true);
	continueButtonContainer->render(true);
	quitButtonContainer->render(true);
}

void FinishedWinPopup::onHide() {

}