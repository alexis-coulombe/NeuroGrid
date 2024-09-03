#include "PlayScreen.h"
#include "../../../GameState.h"
#include "../../../mission/Mission1-7/Mission1.h"
#include "../../../MissionManager.h"
#include "../../../../engine/utility/Timer.h"
#include "../../../../engine/fileIO/SaveFileManager.h"

void handleTimer();
Timer timer = Timer(5 * 60 * TARGET_FPS, true, handleTimer);

PlayScreen::PlayScreen() : GenericScreen() {
	inputContainer = new Container(screenContainer, Bounds2(0, 0, (std::min((int)Window::width, 1920) / 6), std::min((int)Window::height, 1080)));
	gameContainer = new Container(screenContainer, Bounds2((std::min((int)Window::width, 1920) / 6), 0, (std::min((int)Window::width, 1920) / 6) * 4, std::min((int)Window::height, 1080)));
	outputContainer = new Container(screenContainer, Bounds2((std::min((int)Window::width, 1920) / 6) * 5, 0, (std::min((int)Window::width, 1920) / 6), std::min((int)Window::height, 1080)));

	nano1Container = new Container(gameContainer, Bounds2(0, 0, (int) gameContainer->bounds.size.x / 3, (int) gameContainer->bounds.size.y / 4 * 3));
	nano1TextareaContainer = new Container(nano1Container, Bounds2(20, 20, (int) nano1Container->bounds.size.x - 120, (int) nano1Container->bounds.size.y - 120));
	nano1InfoContainer = new Container(nano1Container, Bounds2((int) nano1Container->bounds.size.x - 100, (int)nano1Container->bounds.size.y / 2 - 300, 100, 300));
	nano1MemoryContainer = new Container(nano1InfoContainer, Bounds2(0, 0, 100, 100));
	nano1TestContainer = new Container(nano1InfoContainer, Bounds2(0, 100, 100, 100));
	nano1RxContainer = new Container(nano1InfoContainer, Bounds2(0, 200, 100, 100));
	nano1StatsContainer = new Container(nano1Container, Bounds2((int) nano1Container->bounds.size.x / 2 - 150, (int) nano1Container->bounds.size.y - 100, 300, 100));
	nano1CyclesContainer = new Container(nano1StatsContainer, Bounds2(0, 0, 100, 100));
	nano1LinesContainer = new Container(nano1StatsContainer, Bounds2(100, 0, 100, 100));
	nano1ComplexityContainer = new Container(nano1StatsContainer, Bounds2(200, 0, 100, 100));

	nano2Container = new Container(gameContainer, Bounds2((int) gameContainer->bounds.size.x / 3, 0, (int) gameContainer->bounds.size.x / 3, (int) gameContainer->bounds.size.y / 4 * 3));
	nano2TextareaContainer = new Container(nano2Container, Bounds2(20, 20, (int) nano2Container->bounds.size.x - 120, (int) nano2Container->bounds.size.y - 120));
	nano2InfoContainer = new Container(nano2Container, Bounds2((int) nano2Container->bounds.size.x - 100, (int)nano2Container->bounds.size.y / 2 - 300, 100, 300));
	nano2StatsContainer = new Container(nano2Container, Bounds2((int) nano2Container->bounds.size.x / 2 - 150, (int) nano2Container->bounds.size.y - 100, 300, 100));

	nano3Container = new Container(gameContainer, Bounds2((int) gameContainer->bounds.size.x / 3 * 2, 0, (int) gameContainer->bounds.size.x / 3, (int) gameContainer->bounds.size.y / 4 * 3));
	nano3TextareaContainer = new Container(nano3Container, Bounds2(20, 20, (int) nano3Container->bounds.size.x - 120, (int) nano3Container->bounds.size.y - 120));
	nano3InfoContainer = new Container(nano3Container, Bounds2((int) nano3Container->bounds.size.x - 100, (int)nano3Container->bounds.size.y / 2 - 300, 100, 300));
	nano3StatsContainer = new Container(nano3Container, Bounds2((int) nano3Container->bounds.size.x / 2 - 150, (int) nano3Container->bounds.size.y - 100, 300, 100));

	missionContainer = new Container(gameContainer, Bounds2(0, (int) gameContainer->bounds.size.y / 4 * 3, (int) gameContainer->bounds.size.x, (int) gameContainer->bounds.size.y / 4));
	missionActionContainer = new Container(missionContainer, Bounds2(0, 0, (int) missionContainer->bounds.size.x, (int) missionContainer->bounds.size.y / 3));
	playStepButton = new PlayStepButton(missionActionContainer, Bounds2(0, 0, (int) missionActionContainer->bounds.size.x / 4, (int) missionActionContainer->bounds.size.y), Color::WHITE, 0);
	playStopButton = new PlayStopButton(missionActionContainer, Bounds2((int) missionActionContainer->bounds.size.x / 4, 0, (int) missionActionContainer->bounds.size.x / 4, (int) missionActionContainer->bounds.size.y), Color::WHITE, 0);

	missionBriefContainer = new Container(missionContainer, Bounds2(0, (int) missionContainer->bounds.size.x / 3, (int) missionContainer->bounds.size.x / 3 * 2, (int) missionContainer->bounds.size.y));

	input1 = new Container(inputContainer, Bounds2(0, 0, (int) inputContainer->bounds.size.x / 3, (int) inputContainer->bounds.size.y));
	input1Text = new Text(input1, Vector2f(), Mission1::Ainputs, Asset::loadFont((char *)"assets/ModernDOS.ttf", 8));
	input2 = new Container(inputContainer, Bounds2((int) inputContainer->bounds.size.x / 3, 0, (int) inputContainer->bounds.size.x / 3, (int) inputContainer->bounds.size.y));
	input3 = new Container(inputContainer, Bounds2((int) inputContainer->bounds.size.x / 3 * 2, 0, (int) inputContainer->bounds.size.x / 3, (int) inputContainer->bounds.size.y));

	output1 = new Container(outputContainer, Bounds2(0, 0, (int) outputContainer->bounds.size.x / 3, (int) outputContainer->bounds.size.y));
	output1Text = new Text(output1, Vector2f(), Mission1::Doutputs, Asset::loadFont((char *)"assets/ModernDOS.ttf", 8));
	output2 = new Container(outputContainer, Bounds2((int) outputContainer->bounds.size.x / 3, 0, (int) outputContainer->bounds.size.x / 3, (int) outputContainer->bounds.size.y));
	output3 = new Container(outputContainer, Bounds2((int) outputContainer->bounds.size.x / 3 * 2, 0, (int) outputContainer->bounds.size.x / 3, (int) outputContainer->bounds.size.y));
}

PlayScreen::~PlayScreen() {
}

void PlayScreen::init() {
	mission = MissionManager::getInstance()->currentMission;
	mission->setNanoParentContainer(Mission::NANO1, nano1TextareaContainer);
	mission->setNanoParentContainer(Mission::NANO2, nano2TextareaContainer);
	mission->setNanoParentContainer(Mission::NANO3, nano3TextareaContainer);

	playStepButton->linkMission(mission);
	playStopButton->linkMission(mission);
}

void PlayScreen::render() {
	nano1Container->render(true);
	nano1TextareaContainer->render(true);
	nano1InfoContainer->render(true);
	nano1MemoryContainer->render(true);
	nano1TestContainer->render(true);
	nano1RxContainer->render(true);
	nano1StatsContainer->render(true);
	nano1CyclesContainer->render(true);
	nano1LinesContainer->render(true);
	nano1ComplexityContainer->render(true);

	input1->render();
	input1Text->render();
	input2->render();
	input3->render();

	output1->render();
	output1Text->render();
	output2->render();
	output3->render();

	playStepButton->render();
	playStopButton->render();

	mission->render(Mission::NANO1);
	mission->render(Mission::NANO2);
	mission->render(Mission::NANO3);

	if(Input::getInstance()->getKeyDown(Input::Tab)) {
		mission->setParsing(true);
		mission->stepParsing();
	}

	if(Input::getInstance()->getKeyDown(Input::Escape)) {
		mission->setParsing(false);
	}

	timer.tick();
}

void PlayScreen::onWindowResized() {

}

void handleTimer() {
	SaveFileManager::saveGame();
}