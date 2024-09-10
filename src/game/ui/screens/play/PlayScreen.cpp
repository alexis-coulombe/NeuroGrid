#include "PlayScreen.h"
#include "../../../GameState.h"
#include "../../../mission/Mission1-7/Mission1.h"
#include "../../../MissionManager.h"
#include "../../../../engine/utility/Timer.h"
#include "../../../../engine/fileIO/SaveFileManager.h"
#include "../../../AssetLibrary.h"

void handleTimer();
Timer timer = Timer(5 * 60 * TARGET_FPS, true, handleTimer);

PlayScreen::PlayScreen() : GenericScreen() {
	inputContainer = new Container(screenContainer, Bounds2(0, 0, (std::min((int)Window::width, 1920) / 6), std::min((int)Window::height, 1080)));
	gameContainer = new Container(screenContainer, Bounds2((std::min((int)Window::width, 1920) / 6), 0, (std::min((int)Window::width, 1920) / 6) * 4, std::min((int)Window::height, 1080)));
	outputContainer = new Container(screenContainer, Bounds2((std::min((int)Window::width, 1920) / 6) * 5, 0, (std::min((int)Window::width, 1920) / 6), std::min((int)Window::height, 1080)));

	nano1Container = new Container(gameContainer, Bounds2(0, 0, (int) gameContainer->bounds.size.x / 3, (int) gameContainer->bounds.size.y / 4 * 3), AssetLibrary::CONTAINER_MISSION_PLAY);
	nano1TextareaContainer = new Container(nano1Container, Bounds2(20, 20, (int) nano1Container->bounds.size.x - 120, (int) nano1Container->bounds.size.y - 120));
	// Nano 1 - Nano Info
	nano1InfoContainer = new Container(nano1Container, Bounds2((int) nano1Container->bounds.size.x - 100, (int)nano1Container->bounds.size.y / 2 - 300, 100, 300));
	nano1MemoryContainer = new Container(nano1InfoContainer, Bounds2(0, 0, 100, 100));
	nano1TestContainer = new Container(nano1InfoContainer, Bounds2(0, 100, 100, 100));
	nano1RxContainer = new Container(nano1InfoContainer, Bounds2(0, 200, 100, 100));
	// Nano 1 - Stats
	nano1StatsContainer = new Container(nano1Container, Bounds2((int) nano1Container->bounds.size.x / 2 - 150, (int) nano1Container->bounds.size.y - 100, 300, 100));
	nano1CyclesContainer = new Container(nano1StatsContainer, Bounds2(0, 0, 100, 100));
	nano1LinesContainer = new Container(nano1StatsContainer, Bounds2(100, 0, 100, 100));
	nano1ComplexityContainer = new Container(nano1StatsContainer, Bounds2(200, 0, 100, 100));

	nano2Container = new Container(gameContainer, Bounds2((int) gameContainer->bounds.size.x / 3, 0, (int) gameContainer->bounds.size.x / 3, (int) gameContainer->bounds.size.y / 4 * 3), AssetLibrary::CONTAINER_MISSION_PLAY);
	nano2TextareaContainer = new Container(nano2Container, Bounds2(20, 20, (int) nano2Container->bounds.size.x - 120, (int) nano2Container->bounds.size.y - 120));
	nano2InfoContainer = new Container(nano2Container, Bounds2((int) nano2Container->bounds.size.x - 100, (int)nano2Container->bounds.size.y / 2 - 300, 100, 300));
	nano2MemoryContainer = new Container(nano2InfoContainer, Bounds2(0, 0, 100, 100));
	nano2TestContainer = new Container(nano2InfoContainer, Bounds2(0, 100, 100, 100));
	nano2RxContainer = new Container(nano2InfoContainer, Bounds2(0, 200, 100, 100));
	nano2StatsContainer = new Container(nano2Container, Bounds2((int) nano2Container->bounds.size.x / 2 - 150, (int) nano2Container->bounds.size.y - 100, 300, 100));
	nano2CyclesContainer = new Container(nano2StatsContainer, Bounds2(0, 0, 100, 100));
	nano2LinesContainer = new Container(nano2StatsContainer, Bounds2(100, 0, 100, 100));
	nano2ComplexityContainer = new Container(nano2StatsContainer, Bounds2(200, 0, 100, 100));

	nano3Container = new Container(gameContainer, Bounds2((int) gameContainer->bounds.size.x / 3 * 2, 0, (int) gameContainer->bounds.size.x / 3, (int) gameContainer->bounds.size.y / 4 * 3), AssetLibrary::CONTAINER_MISSION_PLAY);
	nano3TextareaContainer = new Container(nano3Container, Bounds2(20, 20, (int) nano3Container->bounds.size.x - 120, (int) nano3Container->bounds.size.y - 120));
	nano3InfoContainer = new Container(nano3Container, Bounds2((int) nano3Container->bounds.size.x - 100, (int)nano3Container->bounds.size.y / 2 - 300, 100, 300));
	nano3MemoryContainer = new Container(nano3InfoContainer, Bounds2(0, 0, 100, 100));
	nano3TestContainer = new Container(nano3InfoContainer, Bounds2(0, 100, 100, 100));
	nano3RxContainer = new Container(nano3InfoContainer, Bounds2(0, 200, 100, 100));
	nano3StatsContainer = new Container(nano3Container, Bounds2((int) nano3Container->bounds.size.x / 2 - 150, (int) nano3Container->bounds.size.y - 100, 300, 100));
	nano3CyclesContainer = new Container(nano3StatsContainer, Bounds2(0, 0, 100, 100));
	nano3LinesContainer = new Container(nano3StatsContainer, Bounds2(100, 0, 100, 100));
	nano3ComplexityContainer = new Container(nano3StatsContainer, Bounds2(200, 0, 100, 100));

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

	Font *nanoTextFont = Asset::loadFont((char *)"assets/ModernDOS.ttf", 20);
	nano1MemoryText = new Text(nano1MemoryContainer, Vector2f(nano1MemoryContainer->bounds.size.x / 2 - 5, nano1MemoryContainer->bounds.size.y / 2 - 10), std::to_string(mission->getNano(Mission::NANO1)->memory), nanoTextFont);
	nano1TestText = new Text(nano1TestContainer, Vector2f(nano1TestContainer->bounds.size.x / 2 - 5, nano1TestContainer->bounds.size.y / 2 - 10), std::to_string(mission->getNano(Mission::NANO1)->test), nanoTextFont);
	nano1RxText = new Text(nano1RxContainer, Vector2f(nano1RxContainer->bounds.size.x / 2 - 5, nano1RxContainer->bounds.size.y / 2 - 10), std::to_string(mission->getNano(Mission::NANO1)->rx), nanoTextFont);
	nano1CyclesText = new Text(nano1CyclesContainer, Vector2f(nano1CyclesContainer->bounds.size.x / 2 - 5, nano1CyclesContainer->bounds.size.y / 2 - 10), std::to_string(mission->getNano(Mission::NANO1)->cycles), nanoTextFont);
	nano1LinesText = new Text(nano1LinesContainer, Vector2f(nano1LinesContainer->bounds.size.x / 2 - 5, nano1LinesContainer->bounds.size.y / 2 - 10), "0", nanoTextFont);
	nano1ComplexityText = new Text(nano1ComplexityContainer, Vector2f(nano1ComplexityContainer->bounds.size.x / 2 - 5, nano1ComplexityContainer->bounds.size.y / 2 - 10), "0", nanoTextFont);

	nano2MemoryText = new Text(nano2MemoryContainer, Vector2f(nano2MemoryContainer->bounds.size.x / 2 - 5, nano2MemoryContainer->bounds.size.y / 2 - 10), std::to_string(mission->getNano(Mission::NANO2)->memory), nanoTextFont);
	nano2TestText = new Text(nano2TestContainer, Vector2f(nano2TestContainer->bounds.size.x / 2 - 5, nano2TestContainer->bounds.size.y / 2 - 10), std::to_string(mission->getNano(Mission::NANO2)->test), nanoTextFont);
	nano2RxText = new Text(nano2RxContainer, Vector2f(nano2RxContainer->bounds.size.x / 2 - 5, nano2RxContainer->bounds.size.y / 2 - 10), std::to_string(mission->getNano(Mission::NANO2)->rx), nanoTextFont);
	nano2CyclesText = new Text(nano2CyclesContainer, Vector2f(nano2CyclesContainer->bounds.size.x / 2 - 5, nano2CyclesContainer->bounds.size.y / 2 - 10), std::to_string(mission->getNano(Mission::NANO2)->cycles), nanoTextFont);
	nano2LinesText = new Text(nano2LinesContainer, Vector2f(nano2LinesContainer->bounds.size.x / 2 - 5, nano2LinesContainer->bounds.size.y / 2 - 10), "0", nanoTextFont);
	nano2ComplexityText = new Text(nano2ComplexityContainer, Vector2f(nano2ComplexityContainer->bounds.size.x / 2 - 5, nano2ComplexityContainer->bounds.size.y / 2 - 10), "0", nanoTextFont);

	nano3MemoryText = new Text(nano3MemoryContainer, Vector2f(nano3MemoryContainer->bounds.size.x / 2 - 5, nano3MemoryContainer->bounds.size.y / 2 - 10), std::to_string(mission->getNano(Mission::NANO3)->memory), nanoTextFont);
	nano3TestText = new Text(nano3TestContainer, Vector2f(nano3TestContainer->bounds.size.x / 2 - 5, nano3TestContainer->bounds.size.y / 2 - 10), std::to_string(mission->getNano(Mission::NANO3)->test), nanoTextFont);
	nano3RxText = new Text(nano3RxContainer, Vector2f(nano3RxContainer->bounds.size.x / 2 - 5, nano3RxContainer->bounds.size.y / 2 - 10), std::to_string(mission->getNano(Mission::NANO3)->rx), nanoTextFont);
	nano3CyclesText = new Text(nano3CyclesContainer, Vector2f(nano3CyclesContainer->bounds.size.x / 2 - 5, nano3CyclesContainer->bounds.size.y / 2 - 10), std::to_string(mission->getNano(Mission::NANO3)->cycles), nanoTextFont);
	nano3LinesText = new Text(nano3LinesContainer, Vector2f(nano3LinesContainer->bounds.size.x / 2 - 5, nano3LinesContainer->bounds.size.y / 2 - 10), "0", nanoTextFont);
	nano3ComplexityText = new Text(nano3ComplexityContainer, Vector2f(nano3ComplexityContainer->bounds.size.x / 2 - 5, nano3ComplexityContainer->bounds.size.y / 2 - 10), "0", nanoTextFont);

	//mission->getNano(Mission::NANO1)->code->setText(0, "ADD N2 M1 10");
	mission->getNano(Mission::NANO1)->code->setText(0, "ADD M1 M1 1");
	mission->getNano(Mission::NANO1)->code->setText(1, "# A COMMENT WOW");
	mission->getNano(Mission::NANO1)->code->setText(2, "ADD M1 M1 1");
	mission->getNano(Mission::NANO1)->code->setText(3, "ADD M1 M1 1");
	mission->getNano(Mission::NANO1)->code->setText(4, "ADD M1 M1 1");
	mission->getNano(Mission::NANO1)->code->setText(5, "ADD M1 M1 1");
	mission->getNano(Mission::NANO1)->code->setText(6, "ADD M1 M1 1");
	mission->getNano(Mission::NANO1)->code->setText(7, "ADD M1 M1 1");
	mission->getNano(Mission::NANO1)->code->setText(8, "ADD M1 M1 1");
	mission->getNano(Mission::NANO1)->code->setText(9, "MOV N2 M1");


	mission->getNano(Mission::NANO2)->code->setText(0, "NOP");
	mission->getNano(Mission::NANO2)->code->setText(1, "MOV M1 RX");
	mission->getNano(Mission::NANO2)->code->setText(2, "SUB M1 M1 1");
}

void PlayScreen::render() {
	nano1Container->render();
	nano2Container->render();
	nano3Container->render();

	nano1MemoryText->render();
	nano1MemoryText->updateText(std::to_string(mission->getNano(Mission::NANO1)->memory));
	nano1TestText->render();
	nano1TestText->updateText(std::to_string(mission->getNano(Mission::NANO1)->test));
	nano1RxText->render();
	nano1RxText->updateText(std::to_string(mission->getNano(Mission::NANO1)->rx));
	nano1CyclesText->render();
	nano1CyclesText->updateText(std::to_string(mission->getNano(Mission::NANO1)->cycles));
	nano1LinesText->render();
	nano1LinesText->updateText(std::to_string(mission->getNano(Mission::NANO1)->code->getNonEmptyLines()));
	nano1ComplexityText->render();

	nano2MemoryText->render();
	nano2MemoryText->updateText(std::to_string(mission->getNano(Mission::NANO2)->memory));
	nano2TestText->render();
	nano2TestText->updateText(std::to_string(mission->getNano(Mission::NANO2)->test));
	nano2RxText->render();
	nano2RxText->updateText(std::to_string(mission->getNano(Mission::NANO2)->rx));
	nano2CyclesText->render();
	nano2CyclesText->updateText(std::to_string(mission->getNano(Mission::NANO2)->cycles));
	nano2LinesText->render();
	nano2LinesText->updateText(std::to_string(mission->getNano(Mission::NANO2)->code->getNonEmptyLines()));
	nano2ComplexityText->render();

	nano3MemoryText->render();
	nano3MemoryText->updateText(std::to_string(mission->getNano(Mission::NANO3)->memory));
	nano3TestText->render();
	nano3TestText->updateText(std::to_string(mission->getNano(Mission::NANO3)->test));
	nano3RxText->render();
	nano3RxText->updateText(std::to_string(mission->getNano(Mission::NANO3)->rx));
	nano3CyclesText->render();
	nano3CyclesText->updateText(std::to_string(mission->getNano(Mission::NANO3)->cycles));
	nano3LinesText->render();
	nano3LinesText->updateText(std::to_string(mission->getNano(Mission::NANO3)->code->getNonEmptyLines()));
	nano3ComplexityText->render();

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