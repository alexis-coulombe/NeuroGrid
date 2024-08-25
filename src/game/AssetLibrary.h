#ifndef ASM_SRC_ENGINE_ASSETLIBRARY_H_
#define ASM_SRC_ENGINE_ASSETLIBRARY_H_

#include "../engine/utility/Texture.h"
#include "../engine/utility/Asset.h"

class AssetLibrary {
 public:
	static void init();

	static inline const Texture *BUTTON_POPUP_CLOSE_IDLE = nullptr;
	static inline const Texture *BUTTON_POPUP_CLOSE_HOVER = nullptr;
	static inline const Texture *BUTTON_POPUP_CLOSE_PRESS = nullptr;

	static inline const Texture *BUTTON_LOAD_GAME_IDLE = nullptr;
	static inline const Texture *BUTTON_LOAD_GAME_HOVER = nullptr;
	static inline const Texture *BUTTON_LOAD_GAME_PRESS = nullptr;

	static inline const Texture *BUTTON_NEW_GAME_IDLE = nullptr;
	static inline const Texture *BUTTON_NEW_GAME_HOVER = nullptr;
	static inline const Texture *BUTTON_NEW_GAME_PRESS = nullptr;

	static inline const Texture *BUTTON_MISSION1_IDLE = nullptr;
	static inline const Texture *BUTTON_MISSION1_HOVER = nullptr;
	static inline const Texture *BUTTON_MISSION1_PRESS = nullptr;

	static inline const Texture *CONTAINER_MISSION_INTRO = nullptr;
	static inline const Texture *CONTAINER_MISSIONS = nullptr;

	static inline const Texture *ANIMATION_RED_BARS_1 = nullptr;
	static inline const Texture *ANIMATION_RED_BARS_2 = nullptr;
	static inline const Texture *ANIMATION_RED_BARS_3 = nullptr;
	static inline const Texture *ANIMATION_RED_BARS_4 = nullptr;
};

#endif //ASM_SRC_ENGINE_ASSETLIBRARY_H_
