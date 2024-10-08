#include "MenuScreen.h"
#include "elements/PlayNewGameButton.h"
#include "../../../../engine/utility/Asset.h"

MenuScreen::MenuScreen() : GenericScreen() {
	playNewButton = new PlayNewGameButton(nullptr, Bounds2(Window::width / 2, 100, 200, 100));
	background = Asset::loadTexture((char *)"assets/menu/background.png");
}

MenuScreen::~MenuScreen() {
	delete playNewButton;
	delete background;
}

void MenuScreen::init() {
}

void MenuScreen::render() {
	Graphics::drawTexture(background, Vector2f(0, 0), Color::WHITE, Vector2f(Window::width, Window::height));
	playNewButton->render();
}

void MenuScreen::onWindowResized() {

}