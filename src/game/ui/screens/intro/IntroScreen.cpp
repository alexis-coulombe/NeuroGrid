#include "IntroScreen.h"
#include <functional>
#include "../../../GameState.h"
#include "../../../../engine/Graphics.h"
#include "../../../../engine/utility/Asset.h"
#include "../../../../engine/Audio.h"

enum IntroState {
  FIRST_SCREEN,
  SECOND_SCREEN
};

IntroState introScene = FIRST_SCREEN;

enum FSMStates {
  sStart
};

enum FSMEvents {
  eDrawBackground,
  eDrawText,
  eDrawForeground
};

enum FSMConditions {
  cIsFirstScreen,
  cIsSecondScreen,
  cAlways
};

enum FSMActions {
  aDrawFirstScreen,
  aDrawSecondScreen,
  aDrawFirstScreenText,
  aDrawSecondScreenText,
  aDrawForeground,
};

FSM_Transition_t transitions[] = {
	FSM_STATE(sStart, eDrawBackground, 0),
	FSM_EVENT(eDrawBackground, cIsFirstScreen, aDrawFirstScreen, FSM_SAME_STATE),
	FSM_EVENT(eDrawBackground, cIsSecondScreen, aDrawSecondScreen, FSM_SAME_STATE),
	FSM_EVENT(eDrawText, cIsFirstScreen, aDrawFirstScreenText, FSM_SAME_STATE),
	FSM_EVENT(eDrawText, cIsSecondScreen, aDrawSecondScreenText, FSM_SAME_STATE),
	FSM_EVENT(eDrawForeground, cAlways, aDrawForeground, FSM_SAME_STATE),
};
FSM_state_t *initialState = new FSM_state_t{sStart};
FSM_Object_t *fsmObject;
FSM *fsm;

IntroScreen::IntroScreen() : GenericScreen() {
  backgroundBlack = Asset::loadTexture((char *)"assets/menu/background_black.png");
  backgroundIntro1 = Asset::loadTexture((char *)"assets/menu/background_intro_1.png");
  backgroundIntro2 = Asset::loadTexture((char *)"assets/menu/background_intro_2.png");
  font = Asset::loadFont((char *)"assets/ModernDOS.ttf", 12);
  backgroundMusic = new Music(Asset::loadMusic((char *)"assets/music/intro_ambient.mp3"));
};

void IntroScreen::init() {
  fsmObject = new FSM_Object_t{transitions, FSM_GET_TABLE_SIZE(transitions), std::bind(&IntroScreen::checkCondition, this, std::placeholders::_1), std::bind(&IntroScreen::checkAction, this, std::placeholders::_1)};
  fsm = new FSM(fsmObject, initialState, sStart);

  Audio::playMusic(backgroundMusic, false, 0.5f);
}

void IntroScreen::render() {
  fsm->processEvent(fsmObject, initialState, eDrawBackground);
  fsm->processEvent(fsmObject, initialState, eDrawText);
  fsm->processEvent(fsmObject, initialState, eDrawForeground);
}

bool IntroScreen::checkCondition(FSM_condition_t condition) {
  switch (condition) {
	case cIsFirstScreen: return introScene == FIRST_SCREEN;
	case cIsSecondScreen: return introScene == SECOND_SCREEN;
	case cAlways: return true;
	default: return false;
  }
}

void IntroScreen::checkAction(FSM_action_t action) {
  switch (action) {
	case aDrawFirstScreen:
	  renderFirstScreen();
	  break;
	case aDrawSecondScreen:
	  renderSecondScreen();
	  break;
	case aDrawFirstScreenText:
	  renderFirstScreenText();
	  break;
	case aDrawSecondScreenText:
	  renderSecondScreenText();
	  break;
	case aDrawForeground:
	  renderForeground();
	  break;
  }
}

Vector2 firstScreenPosition = Vector2(0, 0);
void IntroScreen::renderFirstScreen() {
  Graphics::drawTexture(backgroundIntro1, Vector2(0, 0) + firstScreenPosition, Color::TRANSPARENT_THIRD, Window::getWindowSize() * 1.6);
  firstScreenPosition.y -= 1;
}

void IntroScreen::renderFirstScreenText() {
  Graphics::drawString(font, (char *)"-    \"Flesh is weak, a frail disguise", Vector2(Window::width / 2 - 250, Window::height / 3), Color::WHITE);
  Graphics::drawString(font, (char *)"     In steel and wire, salvation lies", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 1), Color::WHITE);
  Graphics::drawString(font, (char *)"     The heart, it falters, blood runs cold", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 2), Color::WHITE);
  Graphics::drawString(font, (char *)"     In copper veins, life's strength is bold.\"", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 3), Color::WHITE);
  Graphics::drawString(font, (char *)"Oren 12:5", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 5), Color::WHITE);
}

Vector2 secondScreenPosition = Vector2(0, 0);
void IntroScreen::renderSecondScreen() {
  Graphics::drawTexture(backgroundIntro2, Vector2(0, -100) + secondScreenPosition, Color::TRANSPARENT_THIRD, Window::getWindowSize() * 1.6);
  secondScreenPosition.x -= 1;
}

void IntroScreen::renderSecondScreenText() {
  Graphics::drawString(font, (char *)"-    \"Veins of oil, a heart of steel", Vector2(Window::width / 2 - 250, Window::height / 3), Color::WHITE);
  Graphics::drawString(font, (char *)"     No pulsing blood, no pain to feel", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 1), Color::WHITE);
  Graphics::drawString(font, (char *)"     The path is clear, the choice is plain", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 2), Color::WHITE);
  Graphics::drawString(font, (char *)"     Leave behind this world of pain.\"", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 3), Color::WHITE);
  Graphics::drawString(font, (char *)"Oren 23:12", Vector2(Window::width / 2 - 250, Window::height / 3 + 30 * 5), Color::WHITE);
}

float foregroundFading = 255;
float standbyFading = 40;
bool fading = true;
void IntroScreen::renderForeground() {
  if (fading) {
	foregroundFading -= 5;

	if (foregroundFading <= 0) {
	  fading = false;
	}
  }

  if (!fading && standbyFading > 0) {
	standbyFading -= 1;
  }

  if (!fading && standbyFading <= 0) {
	foregroundFading += 5;

	if (foregroundFading >= 255) {
	  if(introScene == SECOND_SCREEN) {
		GameState::getInstance()->currentState = GameState::MENU_PLAY;
		fsm->terminate(fsmObject, initialState);
	  }
	  fading = true;
	  introScene = SECOND_SCREEN;
	  foregroundFading = 255;
	  standbyFading = 40;
	}
  }

  Graphics::drawTexture(backgroundBlack, Vector2(0, 0), Color(255, 255, 255, std::min(255, (int)(foregroundFading))), Vector2(Window::width, Window::height));}