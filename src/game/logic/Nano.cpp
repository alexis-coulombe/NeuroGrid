#include "Nano.h"
#include "../../language/Token.h"
#include "../../language/Lexer.h"

Nano::Nano(Textarea *code) : code(code) {
}

void Nano::setParentContainer(Container *container) {
	code->setParentContainer(container);
}

void Nano::render() {
	code->render();
}