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

	BUTTON_STOP_CODE_IDLE = Asset::loadTexture((char *)"assets/ui/button/stop_code_idle.png");
	BUTTON_STOP_CODE_HOVER = Asset::loadTexture((char *)"assets/ui/button/stop_code_hover.png");
	BUTTON_STOP_CODE_PRESS = Asset::loadTexture((char *)"assets/ui/button/stop_code_press.png");

	BUTTON_AUTOPLAY_IDLE = Asset::loadTexture((char *)"assets/ui/button/autoplay_code_idle.png");
	BUTTON_AUTOPLAY_HOVER = Asset::loadTexture((char *)"assets/ui/button/autoplay_code_hover.png");
	BUTTON_AUTOPLAY_PRESS = Asset::loadTexture((char *)"assets/ui/button/autoplay_code_press.png");

	BUTTON_PAUSE_IDLE = Asset::loadTexture((char *)"assets/ui/button/pause_code_idle.png");
	BUTTON_PAUSE_HOVER = Asset::loadTexture((char *)"assets/ui/button/pause_code_hover.png");
	BUTTON_PAUSE_PRESS = Asset::loadTexture((char *)"assets/ui/button/pause_code_press.png");

	BUTTON_MISSION1_IDLE = Asset::loadTexture((char *)"assets/ui/button/mission1_idle.png");
	BUTTON_MISSION1_HOVER = Asset::loadTexture((char *)"assets/ui/button/mission1_hover.png");
	BUTTON_MISSION1_PRESS = BUTTON_MISSION1_HOVER;

	CONTAINER_MISSION_INTRO = Asset::loadTexture((char *)"assets/ui/container/mission_info.png");
	CONTAINER_MISSIONS = Asset::loadTexture((char *)"assets/ui/container/missions.png");

	CONTAINER_MISSION_PLAY = Asset::loadTexture((char *)"assets/ui/container/mission_play.png");
	CONTAINER_MISSION_PLAY_BRIEF = Asset::loadTexture((char *)"assets/ui/container/mission_play_brief.png");

	ERROR_SOUND = new Sound(Asset::loadSound((char *)"assets/sound/error.mp3"));
}