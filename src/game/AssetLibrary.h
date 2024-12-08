#ifndef ASM_SRC_ENGINE_ASSETLIBRARY_H_
#define ASM_SRC_ENGINE_ASSETLIBRARY_H_

#include "../engine/utility/Texture.h"
#include "../engine/utility/Asset.h"
#include "../engine/utility/Music.h"
#include "../engine/utility/Sound.h"

class AssetLibrary {
 public:
	static void init();

	static inline const Music *MUSIC_1 = nullptr;
	static inline const Music *MUSIC_2 = nullptr;
	static inline const Music *MUSIC_3 = nullptr;
	static inline const Music *MUSIC_4 = nullptr;
	static inline const Music *MUSIC_5 = nullptr;
	static inline const Music *MUSIC_6 = nullptr;
	static inline const Music *MUSIC_7 = nullptr;
	static inline const Music *MUSIC_8 = nullptr;
	static inline const Music *MUSIC_9 = nullptr;
	static inline const Music *MUSIC_10 = nullptr;
	static inline const Music *MUSIC_11 = nullptr;
	static inline const Music *MUSIC_12 = nullptr;

	static inline const Texture *BUTTON_POPUP_CLOSE_IDLE = nullptr;
	static inline const Texture *BUTTON_POPUP_CLOSE_HOVER = nullptr;
	static inline const Texture *BUTTON_POPUP_CLOSE_PRESS = nullptr;

	static inline const Texture *BUTTON_LOAD_GAME_IDLE = nullptr;
	static inline const Texture *BUTTON_LOAD_GAME_HOVER = nullptr;
	static inline const Texture *BUTTON_LOAD_GAME_PRESS = nullptr;

	static inline const Texture *BUTTON_NEW_GAME_IDLE = nullptr;
	static inline const Texture *BUTTON_NEW_GAME_HOVER = nullptr;
	static inline const Texture *BUTTON_NEW_GAME_PRESS = nullptr;

	static inline const Texture *BUTTON_PLAY_CODE_IDLE = nullptr;
	static inline const Texture *BUTTON_PLAY_CODE_HOVER = nullptr;
	static inline const Texture *BUTTON_PLAY_CODE_PRESS = nullptr;

	static inline const Texture *BUTTON_STOP_CODE_IDLE = nullptr;
	static inline const Texture *BUTTON_STOP_CODE_HOVER = nullptr;
	static inline const Texture *BUTTON_STOP_CODE_PRESS = nullptr;

	static inline const Texture *BUTTON_AUTOPLAY_IDLE = nullptr;
	static inline const Texture *BUTTON_AUTOPLAY_HOVER = nullptr;
	static inline const Texture *BUTTON_AUTOPLAY_PRESS = nullptr;

	static inline const Texture *BUTTON_PAUSE_IDLE = nullptr;
	static inline const Texture *BUTTON_PAUSE_HOVER = nullptr;
	static inline const Texture *BUTTON_PAUSE_PRESS = nullptr;

	static inline const Texture *BUTTON_MISSION1_IDLE = nullptr;
	static inline const Texture *BUTTON_MISSION1_HOVER = nullptr;
	static inline const Texture *BUTTON_MISSION1_PRESS = nullptr;

	static inline const Texture *CONTAINER_MISSION_INTRO = nullptr;
	static inline const Texture *CONTAINER_MISSIONS = nullptr;

	static inline const Texture *CONTAINER_MISSION_PLAY = nullptr;
	static inline const Texture *CONTAINER_MISSION_PLAY_BRIEF = nullptr;
	static inline const Texture *CONTAINER_MISSION_PLAY_IO_A = nullptr;
	static inline const Texture *CONTAINER_MISSION_PLAY_IO_B = nullptr;
	static inline const Texture *CONTAINER_MISSION_PLAY_IO_C = nullptr;
	static inline const Texture *CONTAINER_MISSION_PLAY_IO_D = nullptr;
	static inline const Texture *CONTAINER_MISSION_PLAY_IO_E = nullptr;
	static inline const Texture *CONTAINER_MISSION_PLAY_IO_F = nullptr;

	static inline const Sound   *ERROR_SOUND = nullptr;
	static inline const Sound   *SUCCESS_SOUND = nullptr;
};

#endif //ASM_SRC_ENGINE_ASSETLIBRARY_H_
