#include "Nano.h"
#include "../../language/Token.h"
#include "../../language/Lexer.h"
#include "../MissionManager.h"

Nano::Nano(NanoTextarea *code) : code(code) {
}

void Nano::setParentContainer(Container *container) {
	code->setParentContainer(container);
}

void Nano::render() {
	code->render();
}

void Nano::increaseParseLine() {
	currentParseLine++;

	if (currentParseLine >= code->rows) {
		currentParseLine = 0;
	}
}

void Nano::increaseInputLine(INPUTS input) {
	switch (input) {
		case INPUTS::A: {
			currentInputALine++;
			if (currentInputALine >= MissionManager::getInstance()->currentMission->getInputAText()->lines.size()) {
				currentInputALine = 0;
			}
			break;
		}
		case INPUTS::B: {
			currentInputBLine++;
			if (currentInputBLine >= MissionManager::getInstance()->currentMission->getInputBText()->lines.size()) {
				currentInputBLine = 0;
			}
			break;
		}
		case INPUTS::C: {
			currentInputCLine++;
			if (currentInputCLine >= MissionManager::getInstance()->currentMission->getInputCText()->lines.size()) {
				currentInputCLine = 0;
			}
			break;
		}
	}
}

void Nano::reset() {
	currentParseLine = 0;
	currentInputALine = 0;
	currentInputBLine = 0;
	currentInputCLine = 0;
	currentOutputDLine = 0;
	currentOutputELine = 0;
	currentOutputFLine = 0;
	cycles = 0;
	memory = 0;
	rx = 0;
	test = 0;
	code->highlightedLine = Textarea::NOT_FOUND;
	MissionManager::getInstance()->currentMission->getInputAText()->highlightedLine = Text::NOT_FOUND;
	MissionManager::getInstance()->currentMission->getInputBText()->highlightedLine = Text::NOT_FOUND;
	MissionManager::getInstance()->currentMission->getInputCText()->highlightedLine = Text::NOT_FOUND;
	MissionManager::getInstance()->currentMission->getOutputDText()->highlightedLine = Text::NOT_FOUND;
	MissionManager::getInstance()->currentMission->getOutputEText()->highlightedLine = Text::NOT_FOUND;
	MissionManager::getInstance()->currentMission->getOutputFText()->highlightedLine = Text::NOT_FOUND;
	code->readonly = false;
}