//
// Created by acoulombe on 4/13/24.
//

#ifndef ASM_GAMESTATE_H
#define ASM_GAMESTATE_H

#include <SDL_render.h>
#include "../engine/Texture.h"
#include "../engine/utility/Asset.h"
#include "../engine/Graphics.h"
#include "../engine/Window.h"
#include "../engine/ui/Button.h"
#include "ui/menu/ButtonHead.h"
#include "../engine/utility/Music.h"
#include "../engine/Audio.h"
#include "ui/menu/GameTextarea.h"

class GameState {
private:
    Texture *menuBackground;
    ButtonHead *buttonHead;
    Music *menuMusic;
    GameTextarea *gameTextarea;
    enum State {
        INTRO,
        PAUSE,
        MENU,
        PLAY,
        END
    };

    void renderIntro();

    void renderPause();

    void renderMenu();

    void renderPlay();

    void renderEnd();

public:
    State currentState = MENU;
    State lastState;

    GameState() = default;

    void init();

    void update();

    void render();
};

#endif //ASM_GAMESTATE_H
