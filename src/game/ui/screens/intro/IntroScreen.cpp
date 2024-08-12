#include "IntroScreen.h"
#include <functional>
#include "../../../GameState.h"
#include "../../../../engine/Graphics.h"
#include "../../../../engine/utility/Asset.h"
#include "../../../../engine/Audio.h"
#include "../../../../Config.h"

enum IntroState {
	FIRST_SCREEN,
	SECOND_SCREEN
};

IntroState introScene = FIRST_SCREEN;

enum FSMStates {
	sFirstScreen,
	sSecondScreen
};

enum FSMEvents {
	eDrawBackground,
	eDrawText,
	eDrawForeground,
	eNextScreen,
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
	aSwitchScreen,
	aQuit,
	aNone
};

FSM_Transition_t introTransitions[] = {
		FSM_STATE(sFirstScreen, aDrawForeground, aSwitchScreen),
		FSM_EVENT(eDrawBackground, cIsFirstScreen, aDrawFirstScreen, FSM_SAME_STATE),
		FSM_EVENT(eDrawText, cIsFirstScreen, aDrawFirstScreenText, FSM_SAME_STATE),
		FSM_EVENT(eDrawForeground, cAlways, aDrawForeground, FSM_SAME_STATE),
		FSM_EVENT(eNextScreen, cIsSecondScreen, aNone, sSecondScreen),

		FSM_STATE(sSecondScreen, aDrawForeground, aQuit),
		FSM_EVENT(eDrawBackground, cIsSecondScreen, aDrawSecondScreen, FSM_SAME_STATE),
		FSM_EVENT(eDrawText, cIsSecondScreen, aDrawSecondScreenText, FSM_SAME_STATE),
		FSM_EVENT(eDrawForeground, cAlways, aDrawForeground, FSM_SAME_STATE),
};
FSM_state_t *currentState = new FSM_state_t{sFirstScreen};
FSM_Object_t *fsmObject;
FSM *fsm;

IntroScreen::IntroScreen() : GenericScreen() {
	backgroundBlack = Asset::loadTexture((char *)"assets/menu/background_black.png");
	backgroundIntro1 = Asset::loadTexture((char *)"assets/menu/background_intro_1.png");
	backgroundIntro2 = Asset::loadTexture((char *)"assets/menu/background_intro_2.png");
	font = Asset::loadFont((char *)"assets/ModernDOS.ttf", 12);
	backgroundMusic = new Music(Asset::loadMusic((char *)"assets/music/intro_ambient.mp3"));
};

IntroScreen::~IntroScreen() {
	delete backgroundBlack;
	delete backgroundIntro1;
	delete backgroundIntro2;
	delete font;
	delete backgroundMusic;

	delete fsmObject;
	delete fsm;
}

void IntroScreen::init() {
	fsmObject = new FSM_Object_t{introTransitions, FSM_GET_TABLE_SIZE(introTransitions), std::bind(&IntroScreen::checkCondition, this, std::placeholders::_1), std::bind(&IntroScreen::checkAction, this, std::placeholders::_1)};
	fsm = new FSM(fsmObject, currentState, sFirstScreen);

	Audio::playMusic(backgroundMusic, false, 0.5f);
}

void IntroScreen::render() {
	fsm->processEvent(fsmObject, currentState, eDrawBackground);
	fsm->processEvent(fsmObject, currentState, eDrawText);
	fsm->processEvent(fsmObject, currentState, eDrawForeground);
	fsm->processEvent(fsmObject, currentState, eNextScreen);
}

void IntroScreen::onWindowResized() {
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
		case aDrawFirstScreen: renderFirstScreen();
			break;
		case aDrawSecondScreen: renderSecondScreen();
			break;
		case aDrawFirstScreenText: renderFirstScreenText();
			break;
		case aDrawSecondScreenText: renderSecondScreenText();
			break;
		case aDrawForeground: renderForeground();
			break;
		case aQuit: Audio::stopMusic(0.2f);
			GameState::getInstance()->currentState = GameState::sMenuPlay;
			break;
		case aSwitchScreen: introScene = SECOND_SCREEN;
			break;
		default: break;
	}
}

Vector2f firstScreenPosition = Vector2f(0, 0);
void IntroScreen::renderFirstScreen() {
	Graphics::drawTexture(backgroundIntro1, Vector2f(0, 0) + firstScreenPosition, Color::BLACK_TRANSPARENT_THIRD, Vector2f(Window::width, Window::height));
	firstScreenPosition.y -= 1 / TARGET_FPS;
}

void IntroScreen::renderFirstScreenText() {
	Graphics::drawString(font, (char *)"-    \"Flesh is weak, a frail disguise", Vector2f(Window::width / 2 - 250, Window::height / 3), Color::WHITE);
	Graphics::drawString(font, (char *)"     In steel and wire, salvation lies", Vector2f(Window::width / 2 - 250, Window::height / 3 + 30 * 1), Color::WHITE);
	Graphics::drawString(font, (char *)"     The heart, it falters, blood runs cold", Vector2f(Window::width / 2 - 250, Window::height / 3 + 30 * 2), Color::WHITE);
	Graphics::drawString(font, (char *)"     In copper veins, life's strength is bold.\"", Vector2f(Window::width / 2 - 250, Window::height / 3 + 30 * 3), Color::WHITE);
	Graphics::drawString(font, (char *)"Oren 12:5", Vector2f(Window::width / 2 - 250, Window::height / 3 + 30 * 5), Color::WHITE);
}

Vector2f secondScreenPosition = Vector2f(0, 0);
void IntroScreen::renderSecondScreen() {
	Graphics::drawTexture(backgroundIntro2, Vector2f(0, -100) + secondScreenPosition, Color::BLACK_TRANSPARENT_THIRD, Vector2f(Window::width, Window::height) * 1.6);
	secondScreenPosition.x -= 1 / TARGET_FPS;
}

void IntroScreen::renderSecondScreenText() {
	Graphics::drawString(font, (char *)"-    \"Veins of oil, a heart of steel", Vector2f(Window::width / 2 - 250, Window::height / 3), Color::WHITE);
	Graphics::drawString(font, (char *)"     No pulsing blood, no pain to feel", Vector2f(Window::width / 2 - 250, Window::height / 3 + 30 * 1), Color::WHITE);
	Graphics::drawString(font, (char *)"     The path is clear, the choice is plain", Vector2f(Window::width / 2 - 250, Window::height / 3 + 30 * 2), Color::WHITE);
	Graphics::drawString(font, (char *)"     Leave behind this world of pain.\"", Vector2f(Window::width / 2 - 250, Window::height / 3 + 30 * 3), Color::WHITE);
	Graphics::drawString(font, (char *)"Oren 23:12", Vector2f(Window::width / 2 - 250, Window::height / 3 + 30 * 5), Color::WHITE);
}

float foregroundFading = 255;
float standbyFading = 40;
bool fading = true;
void IntroScreen::renderForeground() {
	if (fading) {
		foregroundFading -= (255.0 / 2) / TARGET_FPS;
		printf("foregroundFading: %f\n", foregroundFading);
		if ((uint8_t) foregroundFading == 0) {
			fading = false;
			standbyFading = (TARGET_FPS * 10.0); // Reset standby fading when transition starts, 10 secs
		}
	} else {
		if (standbyFading > 0) {
			standbyFading -= 1.0;
			printf("standbyFading: %f\n", standbyFading);
		} else {
			foregroundFading += (255.0 / 2) / TARGET_FPS;
			printf("foregroundFading: %f\n", foregroundFading);
			if ((uint8_t) foregroundFading == 255) {
				fsm->terminate(fsmObject, currentState); // Terminate FSM state once fully faded in
				fading = true; // Reset for next fade cycle
			}
		}
	}

	Graphics::drawTexture(backgroundBlack, Vector2f(0, 0), Color(255, 255, 255, std::min(255, (int)foregroundFading)), Vector2f(Window::width, Window::height));
}