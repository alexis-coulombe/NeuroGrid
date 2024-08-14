#ifndef ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PLAYSTOPBUTTON_H_
#define ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PLAYSTOPBUTTON_H_

#include "../../../../mission/Mission.h"
#include "../../../../../engine/ui/GenericButton.h"

class PlayStopButton: public GenericButton {
 public:
	Mission *mission;

	PlayStopButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel);

	void linkMission(Mission *mission);
	void onRender() override;
	void onClick() override;
	void onHover() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PLAYSTOPBUTTON_H_
