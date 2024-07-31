#include "Game.h"

Game::Game() {
	state = GameState::getInstance();
}

void Game::init() {
	state->init();
}

void Game::update() {
	state->update();
}

void Game::render() {
	state->render();
}

void Game::onWindowResized() {
	state->onWindowResized();
}