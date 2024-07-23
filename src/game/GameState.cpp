#include "GameState.h"
#include "ui/screens/intro/IntroScreen.h"
#include "ui/screens/menu/MenuScreen.h"
#include "ui/screens/menu_play/MenuPlayScreen.h"

GameState *GameState::instance = nullptr;

GameState *GameState::getInstance() {
  if (instance == nullptr) {
	instance = new GameState();
  }
  return instance;
}

void GameState::init() {
  menuScreen = new MenuScreen();
  menuPlayScreen = new MenuPlayScreen();
}

void GameState::update() {
  if (currentState != lastState) {
	switch (currentState) {
	  case MENU: {
		menuScreen->init();
		break;
	  }
	  case INTRO: {
		introScreen = new IntroScreen();
		introScreen->init();
		break;
	  }
	  case MENU_PLAY: {
		menuPlayScreen->init();
		break;
	  }
	  case PAUSE:break;
	  case PLAY:break;
	  case END:break;
	}

	lastState = currentState;
  }
}

void GameState::render() {
  switch (currentState) {
	case MENU: {
	  menuScreen->render();
	  break;

	}
	case INTRO: {
	  introScreen->render();
	  break;
	}
	case MENU_PLAY: {
	  menuPlayScreen->render();
	  break;
	}
	case PLAY:break;
	case END:break;
	case PAUSE:break;
  }
}