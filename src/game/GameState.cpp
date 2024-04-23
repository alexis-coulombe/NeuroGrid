//
// Created by acoulombe on 4/13/24.
//

#include "GameState.h"

void GameState::init() {
    menuBackground = Asset::loadTexture((char *) "assets/menu/background.png");
    buttonHead = new ButtonHead(Bounds2(0, 0, 100, 50), Asset::loadTexture((char *) "assets/menu/background.png"));
    menuMusic = new Music(Asset::loadMusic((char *) "assets/music/menu.mp3"));
    gameTextarea = new GameTextarea(0, Bounds2(200, 200, 100, 50), Color::WHITE, Color::WHITE, Color::WHITE);
}

void GameState::update() {
    if (currentState != lastState) {
        switch (currentState) {
            case MENU:
                Audio::playMusic(menuMusic, true, 0.4f);
                break;
            case INTRO:
                break;
            case PAUSE:
                break;
            case PLAY:
                break;
            case END:
                break;
        }

        lastState = currentState;
    }
}

void GameState::render() {
    switch (currentState) {
        case MENU:
            renderMenu();
            break;
        case INTRO:
            break;
        case PAUSE:
            break;
        case PLAY:
            break;
        case END:
            break;
    }
}

void GameState::renderMenu() {
    int w, h;
    SDL_GetWindowSize(Window::window, &w, &h);

    Graphics::drawTexture(menuBackground, Vector2(0, 0), Color::WHITE, Vector2(w, h));
    buttonHead->render();

    gameTextarea->render();

    //Font *font = Asset::loadFont((char*)"assets/ModernDOS.ttf", 24);
}