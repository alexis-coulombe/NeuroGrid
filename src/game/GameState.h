#ifndef ASM_GAMESTATE_H
#define ASM_GAMESTATE_H

#include "../engine/Window.h"
#include "../engine/ui/GenericScreen.h"

class GameState {
protected:
  static GameState *instance;

  GameState() = default;
  ~GameState() = default;

public:
  enum State {
	PAUSE,
	MENU,
	INTRO,
	MENU_PLAY,
	PLAY,
	END
  };

  GameState(GameState &other) = delete;

  void operator=(const GameState &) = delete;

  static GameState *getInstance();

private:
  State lastState;
  GenericScreen *introScreen;
  GenericScreen *menuScreen;
  GenericScreen *menuPlayScreen;

public:
  State currentState = MENU;

  void init();

  void update();

  void render();

  void onWindowResized();
};

#endif //ASM_GAMESTATE_H
