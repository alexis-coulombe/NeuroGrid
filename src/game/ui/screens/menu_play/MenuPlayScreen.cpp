#include "MenuPlayScreen.h"
#include "../../../../engine/utility/Asset.h"
#include "../../../../engine/Audio.h"
#include "../../../../engine/Graphics.h"
#include "elements/Button.h"
#include <cstdint>

MenuPlayScreen::MenuPlayScreen() : GenericScreen() {
  background = Asset::loadTexture((char *)"assets/menu/background.png");
  backgroundBlack = Asset::loadTexture((char *)"assets/menu/background_black.png");

  flashingNeon = new Sound(Asset::loadSound((char *)"assets/sound/flashing_neon.mp3"));
  backgroundBuzz = new Music(Asset::loadMusic((char *)"assets/sound/electric_transformer_loop.mp3"));

  headButton = new Button(Bounds2(40, 40, 40, 40), Asset::loadTexture((char *)"assets/menu/new_game.png"));
}

uint8_t backgroundBuzzTimeout = 10;
bool buzzPlaying = false;

void MenuPlayScreen::init() {
  Audio::playSound(flashingNeon, false, 0.5f);
}

void MenuPlayScreen::render() {
  if (backgroundBuzzTimeout <= 0 && !buzzPlaying) {
	Audio::playMusic(backgroundBuzz, false, 0.5f);
	Audio::stopMusic(5.0f);
	buzzPlaying = true;
  } else if (backgroundBuzzTimeout > 0) {
	backgroundBuzzTimeout--;
	Graphics::drawTexture(backgroundBlack, Vector2(0, 0), Color::BLACK, Vector2(Window::width, Window::height));
  }

  if (!buzzPlaying) {
	return;
  }

  Graphics::drawTexture(background, Vector2(0, 0), Color::WHITE, Vector2(Window::width, Window::height));

  headButton->render();
}