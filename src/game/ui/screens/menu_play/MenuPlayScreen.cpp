#include "MenuPlayScreen.h"
#include "../../../../engine/utility/Asset.h"
#include "../../../../engine/Audio.h"
#include "../../../mission/Mission1.h"

MenuPlayScreen::MenuPlayScreen() : GenericScreen() {
	backgroundBlack = Asset::loadTexture((char *)"assets/menu/background_black.png");
	flashingNeon = new Sound(Asset::loadSound((char *)"assets/sound/flashing_neon.mp3"));
	backgroundBuzz = new Music(Asset::loadMusic((char *)"assets/sound/electric_transformer_loop.mp3"));

  headPopup = new HeadPopup(Bounds2((Window::width / 2) - 500, (Window::height / 2) - 350, 1000, 700));
	headButton = new HeadButton(screenContainer,
															Bounds2(40, 40, 40, 40),
															Asset::loadTexture((char *)"assets/menu/new_game.png"));
}

uint8_t backgroundBuzzTimeout = TARGET_FPS; // 1 sec
bool buzzPlaying = false;

void MenuPlayScreen::init() {
	headButton->linkPopup(headPopup);
	Audio::playSound(flashingNeon, false, 0.5f);
}

void MenuPlayScreen::render() {
	if (backgroundBuzzTimeout <= 0 && !buzzPlaying) {
		Audio::playMusic(backgroundBuzz, false, 0.5f);
		Audio::stopMusic(5.0f);
		buzzPlaying = true;
	} else if (backgroundBuzzTimeout > 0) {
		backgroundBuzzTimeout--;
		Graphics::drawTexture(backgroundBlack, Vector2f(0, 0), Color::BLACK, Vector2f(Window::width, Window::height));
	}

	if (!buzzPlaying) {
		return;
	}

	screenContainer->render();
	headButton->render();
  headPopup->render();
}

void MenuPlayScreen::onWindowResized() {
}