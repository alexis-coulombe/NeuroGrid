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

	// Nano 1
	Container *nano1Container;
	Container *nano1TextareaContainer;
	// Nano 1 - Nano Info
	Container *nano1InfoContainer;
	Container *nano1MemoryContainer;
	Container *nano1TestContainer;
	Container *nano1RxContainer;
	// Nano 1 - Stats
	Container *nano1StatsContainer;
	Container *nano1CyclesContainer;
	Container *nano1LinesContainer;
	Container *nano1ComplexityContainer;

	Container *nano2Container;
	Container *nano2TextareaContainer;
	// Nano 2 - Nano Info
	Container *nano2InfoContainer;
	Container *nano2MemoryContainer;
	Container *nano2TestContainer;
	Container *nano2RxContainer;
	// Nano 2 - Stats
	Container *nano2StatsContainer;
	Container *nano2CyclesContainer;
	Container *nano2LinesContainer;
	Container *nano2ComplexityContainer;

	Container *nano3Container;
	Container *nano3TextareaContainer;
	// Nano 3 - Nano Info
	Container *nano3InfoContainer;
	Container *nano3MemoryContainer;
	Container *nano3TestContainer;
	Container *nano3RxContainer;
	// Nano 3 - Stats
	Container *nano3StatsContainer;
	Container *nano3CyclesContainer;
	Container *nano3LinesContainer;
	Container *nano3ComplexityContainer;

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
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_PLAYSCREEN_H_
