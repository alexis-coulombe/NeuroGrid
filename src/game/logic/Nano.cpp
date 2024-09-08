#include "Nano.h"
#include "../../language/Token.h"
#include "../../language/Lexer.h"

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

	if (currentParseLine >= code->getNonEmptyLines()) {
		currentParseLine = 0;
	}
}