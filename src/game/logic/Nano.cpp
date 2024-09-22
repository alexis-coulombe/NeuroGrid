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

void Nano::reset() {
	Mission *mission = MissionManager::getInstance()->currentMission;

	currentParseLine = 0;
	cycles = 0;
	memory = 0;
	rx = 0;
	test = 0;
	code->highlightedLine = Textarea::NOT_FOUND;
	mission->getInputAText()->highlightedLine = Text::NOT_FOUND;
	mission->getInputBText()->highlightedLine = Text::NOT_FOUND;
	mission->getInputCText()->highlightedLine = Text::NOT_FOUND;
	mission->getOutputDText()->highlightedLine = Text::NOT_FOUND;
	mission->getOutputEText()->highlightedLine = Text::NOT_FOUND;
	mission->getOutputFText()->highlightedLine = Text::NOT_FOUND;
	mission->currentInputALine = 0;
	mission->currentInputBLine = 0;
	mission->currentInputCLine = 0;
	mission->currentOutputDLine = 0;
	mission->currentOutputELine = 0;
	mission->currentOutputFLine = 0;
	code->readonly = false;
}