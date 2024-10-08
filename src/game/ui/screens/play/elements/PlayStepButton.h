#ifndef ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PLAYSTEPBUTTON_H_
#define ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PLAYSTEPBUTTON_H_

#include "../../../../../engine/ui/GenericButton.h"
#include "../../../../mission/Mission.h"

class PlayStepButton : public GenericButton {
 public:
	PlayStepButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel);

	void onRender() override;
	void onPress() override;
	void onClick() override;
	void onHover() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PLAYSTEPBUTTON_H_
