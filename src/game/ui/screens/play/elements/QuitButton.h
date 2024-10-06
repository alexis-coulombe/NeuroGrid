#ifndef ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_QUITBUTTON_H_
#define ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_QUITBUTTON_H_

#include "../../../../../engine/ui/GenericButton.h"
#include "QuitPopup.h"

class QuitButton : public GenericButton {
 private:
	QuitPopup *quitPopup;
 public:
	QuitButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel);

	void onRender() override;
	void onPress() override;
	void onClick() override;
	void onHover() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_QUITBUTTON_H_
