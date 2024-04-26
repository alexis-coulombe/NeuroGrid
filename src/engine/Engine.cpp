//
// Created by acoulombe on 4/12/24.
//

#include "Engine.h"
#include <iostream>

void Engine::start() {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        throw;
    }

    if(TTF_Init() < 0) {
        std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
        throw;
    }

    MIX_InitFlags maxInitFlags = MIX_INIT_MP3;

    if(Mix_Init(maxInitFlags) < 0) {
        std::cout << "Error initializing SDL_mixer: " << Mix_GetError() << std::endl;
        throw;
    }

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) != 0) {
        std::cout << "Error initializing SDL_mixer: " << Mix_GetError() << std::endl;
        throw;
    }

    Mix_AllocateChannels(64);

    Window::window = SDL_CreateWindow("game", SDL_WINDOWPOS_CENTERED_DISPLAY(0), SDL_WINDOWPOS_CENTERED_DISPLAY(0), (int) windowResolution.x, (int) windowResolution.y, 0);
    Window::width = (int) windowResolution.x;
    Window::height = (int) windowResolution.y;

    if(!Window::window) {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        throw;
    }

    Window::renderer = SDL_CreateRenderer(Window::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

    if(!Window::renderer) {
        std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
        throw;
    }

    game = Game();
}

void Engine::run() {
    uint32_t frameStart = 0;
    uint32_t frameTime = 0;

    game.init();

    while(true) {
        frameStart = SDL_GetTicks();

        input->pollEvents();

        if(input->getKeyDown(Input::Key::Return) && input->getKeyHeld(Input::Key::LeftAlt) || input->getKeyHeld(Input::Key::RightAlt)) {
            fullscreen = !fullscreen;
            SDL_SetWindowFullscreen(Window::window, fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);

            if (!fullscreen) {
                Window::width = (int) windowResolution.x;
                Window::height = (int) windowResolution.y;
            } else {
                SDL_GetWindowSize(Window::window, &Window::width, &Window::height);
            }
        }

        game.update();

        SDL_SetRenderDrawColor(Window::renderer,  0, 0, 0, 255);
        SDL_RenderClear(Window::renderer);

        game.render();

        SDL_RenderPresent(Window::renderer);

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

Engine::Engine() = default;
