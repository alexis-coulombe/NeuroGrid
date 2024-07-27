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
		menuPlayScreen = new MenuPlayScreen();
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

void GameState::onWindowResized() {
  switch (currentState) {
	case MENU: {
	  menuScreen->onWindowResized();
	  break;
	}
	case INTRO: {
	  introScreen->onWindowResized();
	  break;
	}
	case MENU_PLAY: {
	  menuPlayScreen->onWindowResized();
	  break;
	}
	case PLAY:break;
	case END:break;
	case PAUSE:break;
  }
}