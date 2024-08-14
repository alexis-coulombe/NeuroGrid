#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_PLAYSCREEN_H_
#define ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_PLAYSCREEN_H_

#include "../../../../engine/ui/GenericScreen.h"
#include "../../../../engine/ui/Container.h"
#include "../../../../engine/ui/Text.h"
#include "../../../logic/Nano.h"
#include "elements/PlayStepButton.h"
#include "elements/PlayStopButton.h"

class PlayScreen : public GenericScreen {
 private:
	Mission *mission;

	Container *inputContainer;
	Container *gameContainer;
	Container *outputContainer;

	Container *nano1Container;
	Container *nano2Container;
	Container *nano3Container;

	Container *missionContainer;
	Container *missionActionContainer;
	PlayStepButton *playStepButton;
	PlayStopButton *playStopButton;
	Container *missionBriefContainer;

	Container *input1;
	Text *input1Text;
	Container *input2;
	Container *input3;

	Container *output1;
	Text *output1Text;
	Container *output2;
	Container *output3;

 public:
	PlayScreen();
	~PlayScreen();

	void init() override;
	void render() override;
	void onWindowResized() override;
 private:
	void renderContainers();
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_PLAYSCREEN_H_
