#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_PLAYSCREEN_H_
#define ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_PLAYSCREEN_H_

#include "../../../../engine/ui/GenericScreen.h"
#include "../../../../engine/ui/Container.h"

class PlayScreen : public GenericScreen {
 private:
	Container *screenContainer;

	Container *inputContainer;
	Container *gameContainer;
	Container *outputContainer;

 public:
	PlayScreen();
	~PlayScreen();

	void init() override;
	void render() override;
	void onWindowResized() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_PLAYSCREEN_H_
