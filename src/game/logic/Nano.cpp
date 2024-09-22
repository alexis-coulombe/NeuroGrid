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
	currentParseLine = 0;
	cycles = 0;
	memory = 0;
	rx = 0;
	test = 0;
	code->highlightedLine = Textarea::NOT_FOUND;
	code->readonly = false;
}