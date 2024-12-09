#ifndef ASM_GAME_H
#define ASM_GAME_H

#include <SDL_render.h>
#include "GameState.h"

class Game {
 private:
	GameState *state;
	SaveFileManager saveFileManager;
 public:
	Game();
	void init();
	void update();
	void render();
	void onWindowResized();
};

#endif //ASM_GAME_H
