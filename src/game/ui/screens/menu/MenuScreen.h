#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_MENUSCREEN_H
#define ASM_SRC_GAME_UI_SCREENS_MENU_MENUSCREEN_H

#include "../../../../engine/ui/GenericScreen.h"
#include "../../../../engine/ui/GenericButton.h"

class MenuScreen : public GenericScreen {
private:
	GenericButton *playNewButton;
	Texture *background;
public:
	MenuScreen();
	void init() override;
	void render() override;
	void onWindowResized() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_MENUSCREEN_H
