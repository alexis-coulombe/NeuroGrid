#ifndef ASM_ENGINE_H
#define ASM_ENGINE_H

#include "../Config.h"
#include "../game/Game.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "utility/Texture.h"
#include "Input.h"
#include "Graphics.h"
#include "Window.h"

class Engine {
public:
    Vector2f windowResolution = Vector2f(WINDOW_WIDTH_RESOLUTION, WINDOW_HEIGHT_RESOLUTION);
    const int frameDelay = 1000 / TARGET_FPS;
    bool fullscreen = WINDOW_FULLSCREEN;
		bool running = false;

    Game game;
    SDL_Renderer* renderer;

    Engine();
    void start();
    void run();
};

#endif //ASM_ENGINE_H
