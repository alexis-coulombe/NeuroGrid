#include "AssetLibrary.h"
#include "../engine/utility/Asset.h"

void AssetLibrary::init() {
	BUTTON_POPUP_CLOSE_IDLE = Asset::loadTexture((char *)"assets/ui/button/close_popup_idle.png");
	BUTTON_POPUP_CLOSE_HOVER = BUTTON_POPUP_CLOSE_IDLE;
	BUTTON_POPUP_CLOSE_PRESS = BUTTON_POPUP_CLOSE_IDLE;

	BUTTON_LOAD_GAME_IDLE = Asset::loadTexture((char *)"assets/ui/button/load_game_idle.png");
	BUTTON_LOAD_GAME_HOVER = Asset::loadTexture((char *)"assets/ui/button/load_game_hover.png");
	BUTTON_LOAD_GAME_PRESS = Asset::loadTexture((char *)"assets/ui/button/load_game_press.png");

	BUTTON_NEW_GAME_IDLE = Asset::loadTexture((char *)"assets/ui/button/new_game_idle.png");
	BUTTON_NEW_GAME_HOVER = Asset::loadTexture((char *)"assets/ui/button/new_game_hover.png");
	BUTTON_NEW_GAME_PRESS = Asset::loadTexture((char *)"assets/ui/button/new_game_press.png");

	BUTTON_PLAY_CODE_IDLE = Asset::loadTexture((char *)"assets/ui/button/play_code_idle.png");
	BUTTON_PLAY_CODE_HOVER = Asset::loadTexture((char *)"assets/ui/button/play_code_hover.png");
	BUTTON_PLAY_CODE_PRESS = Asset::loadTexture((char *)"assets/ui/button/play_code_press.png");

	BUTTON_MISSION1_IDLE = Asset::loadTexture((char *)"assets/ui/button/mission1_idle.png");
	BUTTON_MISSION1_HOVER = Asset::loadTexture((char *)"assets/ui/button/mission1_hover.png");
	BUTTON_MISSION1_PRESS = BUTTON_MISSION1_HOVER;

	CONTAINER_MISSION_INTRO = Asset::loadTexture((char *)"assets/ui/container/mission_info.png");
	CONTAINER_MISSIONS = Asset::loadTexture((char *)"assets/ui/container/missions.png");

	ANIMATION_RED_BARS_1 = Asset::loadTexture((char *)"assets/ui/animation/red_bars_1.png");
	ANIMATION_RED_BARS_2 = Asset::loadTexture((char *)"assets/ui/animation/red_bars_2.png");
	ANIMATION_RED_BARS_3 = Asset::loadTexture((char *)"assets/ui/animation/red_bars_3.png");
	ANIMATION_RED_BARS_4 = Asset::loadTexture((char *)"assets/ui/animation/red_bars_4.png");
}