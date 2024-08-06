#include "GameState.h"
#include <functional>
#include "ui/screens/intro/IntroScreen.h"
#include "ui/screens/menu/MenuScreen.h"
#include "ui/screens/menu_play/MenuPlayScreen.h"

FSM_Transition_t stateTransitions[] = {
		FSM_STATE(GameState::sMenu, 0, 0),

		FSM_STATE(GameState::sIntro, 0, 0),

		FSM_STATE(GameState::sMenuPlay, 0, 0),

		FSM_STATE(GameState::sPlay, 0, 0),

		FSM_STATE(GameState::sEnd, 0, 0),
};
//FSM_Object_t *fsmObject;
//FSM *fsm;

GameState *GameState::getInstance() {
	if (instance == nullptr) {
		instance = new GameState();
	}
	return instance;
}

void GameState::init() {
	//fsmObject = new FSM_Object_t{transitions, FSM_GET_TABLE_SIZE(transitions), std::bind(&GameState::checkCondition, this, std::placeholders::_1), std::bind(&GameState::checkAction, this, std::placeholders::_1)};
	//fsm = new FSM(fsmObject, currentState, sMenu);
	lastState = -1;
}

void GameState::update() {
	if (*currentState == lastState) {
		return;
	}

	switch (*currentState) {
		case sMenu: {
			menuScreen = new MenuScreen();
			menuScreen->init();
			break;
		}
		case sIntro: {
			introScreen = new IntroScreen();
			introScreen->init();
			break;
		}
		case sMenuPlay: {
			menuPlayScreen = new MenuPlayScreen();
			menuPlayScreen->init();
			break;
		}
		case sPlay: {
			playScreen = new PlayScreen();
			playScreen->init();
			break;
		}
		case sEnd:break;
	}

	lastState = *currentState;
}

void GameState::render() {
	switch (*currentState) {
		case sMenu: {
			menuScreen->render();
			break;
		}
		case sIntro: {
			introScreen->render();
			break;
		}
		case sMenuPlay: {
			menuPlayScreen->render();
			break;
		}
		case sPlay: {
			playScreen->render();
			break;
		}
		case sEnd:break;
	}
}

void GameState::onWindowResized() {
	switch (*currentState) {
		case sMenu: {
			menuScreen->onWindowResized();
			break;
		}
		case sIntro: {
			introScreen->onWindowResized();
			break;
		}
		case sMenuPlay: {
			menuPlayScreen->onWindowResized();
			break;
		}
		case sPlay: {
			playScreen->onWindowResized();
			break;
		}
		case sEnd:break;
	}
}

bool checkCondition(FSM_condition_t condition) {
	return true;
}

void checkAction(FSM_action_t action) {

}