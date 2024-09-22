#ifndef ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PLAYBUTTON_H_
#define ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PLAYBUTTON_H_

#include "../../../../../engine/ui/GenericButton.h"
#include "../../../../mission/Mission.h"

class PlayButton : public GenericButton {
 public:
	PlayButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel);

	void onRender() override;
	void onPress() override;
	void onClick() override;
	void onHover() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_PLAYBUTTON_H_
