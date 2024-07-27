#include "MenuPlayScreen.h"
#include "../../../../engine/utility/Asset.h"
#include "../../../../engine/Audio.h"
#include <cstdint>

bool canShowPopup = false;

MenuPlayScreen::MenuPlayScreen() : GenericScreen() {
  background = Asset::loadTexture((char *)"assets/menu/background.png");
  backgroundBlack = Asset::loadTexture((char *)"assets/menu/background_black.png");

  flashingNeon = new Sound(Asset::loadSound((char *)"assets/sound/flashing_neon.mp3"));
  backgroundBuzz = new Music(Asset::loadMusic((char *)"assets/sound/electric_transformer_loop.mp3"));

  screenContainer = new Container(Bounds2(0, 0, std::min(Window::width, 1920), std::min(Window::height, 1080)));
  popupContainer = new Container(Bounds2((Window::width / 2) - 500, (Window::height / 2) - 350, 1000, 700));

  closePopupButton = new ClosePopupButton(popupContainer,
										  Bounds2((int)popupContainer->bounds.size.x - 40, 0, 40, 40),
										  Asset::loadTexture((char *)"assets/menu/new_game.png"),
										  Color::WHITE,
										  1);
  headButton = new HeadButton(screenContainer,
							  Bounds2(40, 40, 40, 40),
							  Asset::loadTexture((char *)"assets/menu/new_game.png"));
}

uint8_t backgroundBuzzTimeout = 10;
bool buzzPlaying = false;

void MenuPlayScreen::init() {
  headButton->linkPopup(&canShowPopup);
  closePopupButton->linkPopup(&canShowPopup);
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
  screenContainer->render();

  if (canShowPopup) {
	showPopup();
  }
}

void MenuPlayScreen::onWindowResized() {
  popupContainer->setBounds(Bounds2((Window::width / 2) - 500, (Window::height / 2) - 350, 1000, 700));
  screenContainer->setBounds(Bounds2(0, 0, std::min(Window::width, 1920), std::min(Window::height, 1080)));

  closePopupButton->setBounds(Bounds2((int)popupContainer->bounds.size.x - 40, 0, 40, 40));
}

void MenuPlayScreen::showPopup() {
  Graphics::drawTexture(backgroundBlack, Vector2(0, 0), Color::TRANSPARENT_HALF, Vector2(Window::width, Window::height));
  popupContainer->render();
  closePopupButton->render();
}