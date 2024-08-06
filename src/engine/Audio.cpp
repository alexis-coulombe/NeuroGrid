#include "Audio.h"

int Audio::getFadeTimeMs(float fadeTime) {
	return (int)(fadeTime * 1000);
}

SoundInstance Audio::playSound(Sound *sound, bool repeat, float fadeTime) {
	int channel = Mix_FadeInChannel(-1, sound->handle, repeat ? -1 : 0, getFadeTimeMs(fadeTime));
	SoundInstance soundInstance;

	// silently fail if no channel is available
	if (channel == -1) {
		return SoundInstance();
	}

	for (size_t i = 0; i < AUDIO_CHANNEL_COUNT; i++) {
		if (soundInstances[i].channel == channel) {
			soundInstances[i].channel = -1;
		}
	}

	for (size_t i = 0; i < AUDIO_CHANNEL_COUNT; ++i) {
		if (soundInstances[i].channel == -1) {
			soundInstances[i].channel = channel;
			soundInstance = soundInstances[i];
		}
	}

	return soundInstance;
}

void Audio::stopSound(SoundInstance soundInstance, float fadeTime) {
	for (size_t i = 0; i < AUDIO_CHANNEL_COUNT; i++) {
		if (soundInstances[i].channel == soundInstance.channel) {
			Mix_FadeOutChannel(soundInstance.channel, getFadeTimeMs(fadeTime));
			soundInstances[i].channel = -1;
			break;
		}
	}
}

void Audio::playMusic(Music *music, bool repeat, float volume, float fadeTime) {
	stopMusic(1.0f);

	Mix_VolumeMusic((int)(volume * MIX_MAX_VOLUME));
	Mix_FadeInMusic(music->handle, repeat ? -1 : 0, getFadeTimeMs(fadeTime));
}

void Audio::stopMusic(float fadeTime) {
	Mix_FadeOutMusic(getFadeTimeMs(fadeTime));
}
