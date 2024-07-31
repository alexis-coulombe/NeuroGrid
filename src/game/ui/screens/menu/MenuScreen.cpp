#include "MenuScreen.h"
#include "elements/PlayNewGameButton.h"
#include "../../../../engine/utility/Asset.h"

MenuScreen::MenuScreen() : GenericScreen() {
	playNewButton = new PlayNewGameButton(nullptr, Bounds2(Window::width / 2, 100, 200, 100), Asset::loadTexture((char *)"assets/menu/new_game.png"));
	background = Asset::loadTexture((char *)"assets/menu/background.png");
}

MenuScreen::~MenuScreen() {
	delete playNewButton;
	delete background;
}

void MenuScreen::init() {
}

void MenuScreen::render() {
	Graphics::drawTexture(background, Vector2(0, 0), Color::WHITE, Vector2(Window::width, Window::height));
	playNewButton->render();
}

void MenuScreen::onWindowResized() {

}