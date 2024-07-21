#include "IntroScreen.h"
#include "../../../GameState.h"
#include "../../../../engine/Graphics.h"
#include "../../../../engine/utility/Asset.h"
#include "../../../../engine/Audio.h"

enum IntroState {
  FIRST_SCREEN,
  SECOND_SCREEN
};

IntroState introScene = FIRST_SCREEN;
float backgroundTransition = 255;
float standbyTransition = 40;
bool fadingSide = false;

IntroScreen::IntroScreen() : GenericScreen() {
  backgroundBlack = Asset::loadTexture((char *)"assets/menu/background_black.png");
  backgroundIntro1 = Asset::loadTexture((char *)"assets/menu/background_intro_1.png");
  backgroundIntro2 = Asset::loadTexture((char *)"assets/menu/background_intro_2.png");
  font = Asset::loadFont((char *)"assets/ModernDOS.ttf", 12);
  backgroundMusic = new Music(Asset::loadMusic((char *)"assets/music/intro_ambient.mp3"));
};

void IntroScreen::init() {
  Audio::playMusic(backgroundMusic, false, 0.5f);
}

void IntroScreen::render() {
  if (introScene == FIRST_SCREEN) {
	Graphics::drawTexture(backgroundIntro1, Vector2(0, 0), Color::TRANSPARENT_THIRD, Window::getWindowSize());
	Graphics::drawString(font, (char *)"-    Flesh is weak, a frail disguise", Vector2(Window::width / 2 - 250, Window::height / 3), Color::WHITE);
	Graphics::drawString(font, (char *)"     In steel and wire, salvation lies", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 1), Color::WHITE);
	Graphics::drawString(font, (char *)"     The heart, it falters, blood runs cold", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 2), Color::WHITE);
	Graphics::drawString(font, (char *)"     In copper veins, life's strength is bold", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 3), Color::WHITE);
	Graphics::drawString(font, (char *)"Oren 12:5", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 5), Color::WHITE);
  }

  if (introScene == SECOND_SCREEN) {
	Graphics::drawTexture(backgroundIntro2, Vector2(0, 0), Color::TRANSPARENT_THIRD, Window::getWindowSize());
	Graphics::drawString(font, (char *)"-    Veins of oil, a heart of steel", Vector2(Window::width / 2 - 250, Window::height / 3), Color::WHITE);
	Graphics::drawString(font, (char *)"     No pulsing blood, no pain to feel", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 1), Color::WHITE);
	Graphics::drawString(font, (char *)"     The path is clear, the choice is plain", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 2), Color::WHITE);
	Graphics::drawString(font, (char *)"     Leave behind this world of pain", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 3), Color::WHITE);
	Graphics::drawString(font, (char *)"Oren 23:12", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 5), Color::WHITE);
  }

  Graphics::drawTexture(backgroundBlack, Vector2(0, 0), Color(255, 255, 255, std::min(255, (int)(backgroundTransition))), Vector2(Window::width, Window::height));

  if (fadingSide == false) {
	backgroundTransition -= 5;

	if (backgroundTransition <= 0) {
	  fadingSide = true;
	}
  }

  if (fadingSide == true && standbyTransition > 0) {
	standbyTransition -= 1;
  }

  if (fadingSide == true && standbyTransition <= 0) {
	backgroundTransition += 5;

	if (backgroundTransition >= 255) {
	  if (introScene == 1) {
		GameState::getInstance()->currentState = GameState::MENU_PLAY;
	  }
	  fadingSide = false;
	  introScene = SECOND_SCREEN;
	  backgroundTransition = 255;
	  standbyTransition = 40;
	}
  }
}