#include "MenuScreen.h"
#include "elements/Button.h"
#include "../../../../engine/utility/Asset.h"

MenuScreen::MenuScreen(): GenericScreen() {
	playNewButton = new Button(Bounds2(Window::width / 2, 100, 200, 100), Asset::loadTexture((char *)"assets/menu/new_game.png"));
}

void MenuScreen::init() {
}

void MenuScreen::render() {
	playNewButton->render();
}