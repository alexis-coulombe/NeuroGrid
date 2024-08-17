#include "Game.h"
#include "AssetLibrary.h"

Game::Game() {
	state = GameState::getInstance();
}

void Game::init() {
	AssetLibrary::init();

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