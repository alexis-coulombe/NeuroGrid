#include "GenericPopup.h"
#include "../../engine/Input.h"

GenericPopup::GenericPopup(Bounds2 bounds): bounds(bounds) {
    popupContainer = Container(nullptr, bounds);
    backgroundOverlay = Asset::loadTexture((char *)"assets/menu/background_black.png");
}

void GenericPopup::show() {
    isVisible = true;
    Input::getInstance()->mouseZLevel++;
    zLevel = Input::getInstance()->mouseZLevel;

    closeButton = CloseButton(popupContainer, Bounds2((uint32_t) popupContainer->bounds.size.x - 40, 0, 40, 40), Asset::loadTexture((char *)"assets/menu/new_game.png"), Color::WHITE, zLevel);

    onShow();
}

void GenericPopup::render() {
    if(!isVisible) {
        return;
    }

    Graphics::drawTexture(backgroundOverlay, Vector2f(0, 0), Color::BLACK_TRANSPARENT_HALF, Vector2f(Window::width, Window::height));    
    popupContainer.render();
    closeButton.render();
    
    renderPopup();
}

void GenericPopup::hide() {
    isVisible = false;
    Input::getInstance()->mouseZLevel--;
    zLevel = 0;

    onHide();
}