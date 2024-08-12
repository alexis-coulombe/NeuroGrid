#ifndef ASM_GAMESTATE_H
#define ASM_GAMESTATE_H

#include "../engine/Window.h"
#include "../engine/ui/GenericScreen.h"
#include "ui/screens/intro/IntroScreen.h"
#include "ui/screens/menu/MenuScreen.h"
#include "ui/screens/menu_play/MenuPlayScreen.h"
#include "ui/screens/play/PlayScreen.h"

class GameState {
 private:
	uint8_t lastState;
	IntroScreen *introScreen;
	MenuScreen *menuScreen;
	MenuPlayScreen *menuPlayScreen;
	PlayScreen *playScreen;

 protected:
	static inline GameState *instance = nullptr;

	GameState() = default;
	~GameState() = default;

 public:
	enum FSMStates {
		sMenu,
		sIntro,
		sMenuPlay,
		sPlay,
		sEnd
	};

	uint8_t currentState = sMenu;

	GameState(GameState &other) = delete;

	void operator=(const GameState &) = delete;
	static GameState *getInstance();
	void init();
	void update();
	void render();
	void onWindowResized();
};

#endif //ASM_GAMESTATE_H
