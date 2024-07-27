#ifndef ASM_ENGINE_H
#define ASM_ENGINE_H

#include "../game/Game.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "Texture.h"
#include "Input.h"
#include "Graphics.h"
#include "Window.h"

class Engine {
public:
    Vector2 windowResolution = Vector2(1600, 900);
    const int targetFps = 10;
    const int frameDelay = 1000 / targetFps;

    bool fullscreen = false;
    Game game;
    Input* input = Input::getInstance();
    SDL_Renderer* renderer{};

    Engine();
    void start();
    void run();
};

#endif //ASM_ENGINE_H
