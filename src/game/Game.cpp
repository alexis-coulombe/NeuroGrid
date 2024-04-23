//
// Created by acoulombe on 4/12/24.
//

#include "Game.h"

void Game::init() {
    state.init();
}

void Game::update() {
    state.update();
}


void Game::render() {
    state.render();
}
