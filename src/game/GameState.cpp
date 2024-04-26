//
// Created by acoulombe on 4/13/24.
//

#include "GameState.h"

void GameState::init() {
    menuBackground = Asset::loadTexture((char *) "assets/menu/background.png");
    buttonHead = new ButtonHead(Bounds2(0, 0, 100, 50), Asset::loadTexture((char *) "assets/menu/background.png"));
    menuMusic = new Music(Asset::loadMusic((char *) "assets/music/menu.mp3"));
    gameTextarea = new GameTextarea(0, Vector2(100, 100), 10, 4, Color::WHITE, Color::WHITE, Color::WHITE);
    font = Asset::loadFont((char *) "assets/ModernDOS.ttf", 12);
}

void GameState::update() {
    if (currentState != lastState) {
        switch (currentState) {
            case MENU:
                //Audio::playMusic(menuMusic, true, 0.4f);
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
    Graphics::drawTexture(menuBackground, Vector2(0, 0), Color::WHITE, Vector2(Window::width, Window::height));
    buttonHead->render();

    gameTextarea->render(font);
}