#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_MENUSCREEN_H
#define ASM_SRC_GAME_UI_SCREENS_MENU_MENUSCREEN_H

#include "../../../../engine/ui/GenericScreen.h"
#include "../../../../engine/ui/GenericButton.h"
#include "elements/PlayNewGameButton.h"

class MenuScreen : public GenericScreen {
private:
	PlayNewGameButton *playNewButton;
	Texture *background;
public:
	MenuScreen();
	~MenuScreen();
	void init() override;
	void render() override;
	void onWindowResized() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_MENUSCREEN_H
