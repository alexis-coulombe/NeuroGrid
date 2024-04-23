//
// Created by acoulombe on 4/12/24.
//

#ifndef ASM_GAME_H
#define ASM_GAME_H

#include <SDL_render.h>
#include "GameState.h"

class Game {
private:
    GameState state = GameState();
public:
    Game() = default;
    void init();
    void update();
    void render();
};


#endif //ASM_GAME_H
