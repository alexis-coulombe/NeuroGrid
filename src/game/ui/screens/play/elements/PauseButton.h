#ifndef ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PAUSEBUTTON_H_
#define ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PAUSEBUTTON_H_

#include "../../../../../engine/ui/GenericButton.h"
#include "../../../../mission/Mission.h"

class PauseButton : public GenericButton {
 public:
	PauseButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel);

	void onRender() override;
	void onPress() override;
	void onClick() override;
	void onHover() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PAUSEBUTTON_H_
