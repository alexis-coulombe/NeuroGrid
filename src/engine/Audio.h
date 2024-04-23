//
// Created by acoulombe on 4/22/24.
//

#ifndef ASM_AUDIO_H
#define ASM_AUDIO_H

#include "utility/Sound.h"
#include "utility/Music.h"
#include <SDL_mixer.h>
#include <iostream>

class SoundInstance {
public:
    int channel = -1;
};

class Audio {
public:
    const static int AUDIO_CHANNEL_COUNT = 8;
    static SoundInstance soundInstances[AUDIO_CHANNEL_COUNT];

    static int getFadeTimeMs(float fadeTime);

    static SoundInstance playSound(Sound *sound, bool repeat = false, float fadeTime = 0.0f);

    static void stopSound(SoundInstance soundInstance, float fadeTime = 0.0f);

    static void playMusic(Music *music, bool repeat = true, float volume = 1.0f, float fadeTime = 0.0f);

    static void stopMusic(float fadeTime = 0.0f);
};


#endif //ASM_AUDIO_H
