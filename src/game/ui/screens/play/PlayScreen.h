#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_PLAYSCREEN_H_
#define ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_PLAYSCREEN_H_

#include "../../../../engine/ui/GenericScreen.h"
#include "../../../../engine/ui/Container.h"
#include "elements/Nano1Textarea.h"
#include "elements/Nano2Textarea.h"
#include "elements/Nano3Textarea.h"
#include "../../../../engine/ui/Text.h"

class PlayScreen : public GenericScreen {
 private:
	Container *screenContainer;

	Container *inputContainer;
	Container *gameContainer;
	Container *outputContainer;

	Container *nano1Container;
	Nano1Textarea *nano1Textarea;
	Container *nano2Container;
	Nano2Textarea *nano2Textarea;
	Container *nano3Container;
	Nano3Textarea *nano3Textarea;

	Container *missionDescriptionContainer;

	Container *input1;
	Text *input1Text;
	Container *input2;
	Container *input3;

	Container *output1;
	Container *output2;
	Container *output3;

	uint8_t inputs[];

 public:
	PlayScreen();
	~PlayScreen();

	void init() override;
	void render() override;
	void onWindowResized() override;

	void getMissionInputs();
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_PLAYSCREEN_H_
