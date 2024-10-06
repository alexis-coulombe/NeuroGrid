#ifndef ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_QUITTOMENUBUTTON_H_
#define ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_QUITTOMENUBUTTON_H_

#include "../../../../../../engine/ui/GenericButton.h"
#include "../../../../../../engine/ui/GenericPopup.h"

class QuitToMenuButton : public GenericButton {
 private:
	GenericPopup *popup;
 public:
	QuitToMenuButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel);

	void onRender() override;
	void onPress() override;
	void onClick() override;
	void onHover() override;

	void linkPopup(GenericPopup *popup);
};

#endif //ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_QUITTOMENUBUTTON_H_
