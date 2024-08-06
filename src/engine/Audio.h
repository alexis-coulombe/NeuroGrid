#ifndef ASM_AUDIO_H
#define ASM_AUDIO_H

#include "utility/Sound.h"
#include "utility/Music.h"
#include "../Config.h"
#include <SDL_mixer.h>

class SoundInstance {
 public:
	int channel = -1;
};

class Audio {
 public:
	static inline SoundInstance soundInstances[AUDIO_CHANNEL_COUNT] = {};
	static int getFadeTimeMs(float fadeTime);
	static SoundInstance playSound(Sound *sound, bool repeat = false, float fadeTime = 0.0f);
	static void stopSound(SoundInstance soundInstance, float fadeTime = 0.0f);
	static void playMusic(Music *music, bool repeat = true, float volume = 1.0f, float fadeTime = 0.0f);
	static void stopMusic(float fadeTime = 0.0f);
};

#endif //ASM_AUDIO_H
