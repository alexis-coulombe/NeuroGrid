#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_PLAYSCREEN_H_
#define ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_PLAYSCREEN_H_

#include "../../../../engine/ui/GenericScreen.h"
#include "../../../../engine/ui/Container.h"
#include "../../../../engine/ui/Text.h"
#include "../../../logic/Nano.h"
#include "elements/PlayStepButton.h"
#include "elements/PlayStopButton.h"
#include "../../../../engine/utility/Timer.h"

class PlayScreen : public GenericScreen {
 private:
	Mission *mission;
	Timer* timer;

	static void handleTimer();

	Container *inputContainer;
	Container *gameContainer;
	Container *outputContainer;

	// Nano 1
	Container *nano1Container;
	Container *nano1TextareaContainer;
	// Nano 1 - Nano Info
	Container *nano1InfoContainer;
	Container *nano1MemoryContainer;
	Text *nano1MemoryText;
	Container *nano1TestContainer;
	Text *nano1TestText;
	Container *nano1RxContainer;
	Text *nano1RxText;
	// Nano 1 - Stats
	Container *nano1StatsContainer;
	Container *nano1CyclesContainer;
	Text *nano1CyclesText;
	Container *nano1LinesContainer;
	Text *nano1LinesText;
	Container *nano1ComplexityContainer;
	Text *nano1ComplexityText;

	Container *nano2Container;
	Container *nano2TextareaContainer;
	// Nano 2 - Nano Info
	Container *nano2InfoContainer;
	Container *nano2MemoryContainer;
	Text *nano2MemoryText;
	Container *nano2TestContainer;
	Text *nano2TestText;
	Container *nano2RxContainer;
	Text *nano2RxText;
	// Nano 2 - Stats
	Container *nano2StatsContainer;
	Container *nano2CyclesContainer;
	Text *nano2CyclesText;
	Container *nano2LinesContainer;
	Text *nano2LinesText;
	Container *nano2ComplexityContainer;
	Text *nano2ComplexityText;

	Container *nano3Container;
	Container *nano3TextareaContainer;
	// Nano 3 - Nano Info
	Container *nano3InfoContainer;
	Container *nano3MemoryContainer;
	Text *nano3MemoryText;
	Container *nano3TestContainer;
	Text *nano3TestText;
	Container *nano3RxContainer;
	Text *nano3RxText;
	// Nano 3 - Stats
	Container *nano3StatsContainer;
	Container *nano3CyclesContainer;
	Text *nano3CyclesText;
	Container *nano3LinesContainer;
	Text *nano3LinesText;
	Container *nano3ComplexityContainer;
	Text *nano3ComplexityText;

	Container *missionContainer;
	Container *missionActionContainer;
	PlayStepButton *playStepButton;
	PlayStopButton *playStopButton;
	Container *missionBriefContainer;
	Text *missionBriefText;

	Container *input1;
	Text *input1Text;
	Container *input2;
	Text *input2Text;
	Container *input3;
	Text *input3Text;

	Container *output1;
	Text *output1Text;
	Container *output2;
	Text *output2Text;
	Container *output3;
	Text *output3Text;

	void renderText();
 public:
	PlayScreen();

	void init() override;
	void render() override;
	void onWindowResized() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_PLAYSCREEN_H_
