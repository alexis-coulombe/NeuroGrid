#include "Engine.h"
#include <iostream>

Engine::Engine() {
	renderer = nullptr;
}

void Engine::start() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
		throw;
	}

	if (TTF_Init() < 0) {
		std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
		throw;
	}

	MIX_InitFlags maxInitFlags = MIX_INIT_MP3;

	if (Mix_Init(maxInitFlags) < 0) {
		std::cout << "Error initializing SDL_mixer: " << Mix_GetError() << std::endl;
		throw;
	}

	if (Mix_OpenAudio(AUDIO_FREQUENCY, MIX_DEFAULT_FORMAT, AUDIO_CHANNELS, AUDIO_CHUNKSIZE) != 0) {
		std::cout << "Error initializing SDL_mixer: " << Mix_GetError() << std::endl;
		throw;
	}

	Mix_AllocateChannels(AUDIO_CHANNEL_COUNT);

	Window::window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED_DISPLAY(0), SDL_WINDOWPOS_CENTERED_DISPLAY(0), (int)windowResolution.x, (int)windowResolution.y, 0);
	Window::width = (int)windowResolution.x;
	Window::height = (int)windowResolution.y;

	if (!Window::window) {
		std::cout << "Error creating window: " << SDL_GetError() << std::endl;
		throw;
	}

	Window::renderer = SDL_CreateRenderer(Window::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	SDL_RenderSetLogicalSize(renderer, (int) Window::width, (int) Window::height);
	SDL_SetWindowFullscreen(Window::window, fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
	SDL_SetRenderDrawColor(Window::renderer, 0, 0, 0, 255);

	if (!Window::renderer) {
		std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
		throw;
	}

	game = Game();
}

void Engine::run() {
	uint32_t frameStart = 0;
	uint32_t frameTime = 0;
	Vector2i lastWindowSize = Window::getWindowSize();

	game.init();
	running = true;

	while (running) {
		SDL_GetWindowSize(Window::window, reinterpret_cast<int *>(&Window::width), reinterpret_cast<int *>(&Window::height));
		frameStart = SDL_GetTicks();

		Input::getInstance()->pollEvents();

		if (Input::getInstance()->getKeyDown(Input::Key::RightAlt)) {
			fullscreen = !fullscreen;
			SDL_SetWindowFullscreen(Window::window, fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);

			if (!fullscreen) {
				Window::width = (int)windowResolution.x;
				Window::height = (int)windowResolution.y;
			}
		}

		if (lastWindowSize.x != Window::width || lastWindowSize.y != Window::height) {
			lastWindowSize = Vector2i((int32_t) Window::width, (int32_t) Window::height);
			game.onWindowResized();
		}

		if (Input::getInstance()->getKeyDown(Input::Key::Escape)) {
			running = false;
		}

		game.update();
		SDL_RenderClear(Window::renderer);
		game.render();
		SDL_RenderPresent(Window::renderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}
