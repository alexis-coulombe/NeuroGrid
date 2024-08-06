#ifndef ASM_MUSIC_H
#define ASM_MUSIC_H

#include <SDL_mixer.h>

class Music {
 public:
	Mix_Music *handle;

	Music(Mix_Music *handle);
};

#endif //ASM_MUSIC_H
