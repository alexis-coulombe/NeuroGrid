#ifndef ASM_SOUND_H
#define ASM_SOUND_H

#include <SDL_mixer.h>

class Sound {
 public:
	Mix_Chunk *handle;

	Sound(Mix_Chunk *handle);
};

#endif //ASM_SOUND_H
