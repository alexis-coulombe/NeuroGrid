#include "GameState.h"
#include <functional>
#include "ui/screens/intro/IntroScreen.h"
#include "ui/screens/menu/MenuScreen.h"
#include "ui/screens/menu_play/MenuPlayScreen.h"

GameState *GameState::getInstance() {
	if (instance == nullptr) {
		instance = new GameState();
	}
	return instance;
}

void GameState::init() {
	lastState = 0xFF;
}

void GameState::update() {
	if (currentState == lastState) {
		return;
	}

	Input::getInstance()->mouseZLevel = 0;

	switch (currentState) {
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

	lastState = currentState;
}

void GameState::render() {
	switch (currentState) {
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
	switch (currentState) {
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
