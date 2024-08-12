#ifndef ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PLAYSTEPBUTTON_H_
#define ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PLAYSTEPBUTTON_H_

#include "../../../../../engine/ui/GenericButton.h"
#include "../../../../mission/Mission.h"

class PlayStepButton : public GenericButton {
 public:
	Mission *mission;

	PlayStepButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel);

	void linkMission(Mission *mission);
	void onRender() override;
	void onClick() override;
	void onHover() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PLAYSTEPBUTTON_H_
