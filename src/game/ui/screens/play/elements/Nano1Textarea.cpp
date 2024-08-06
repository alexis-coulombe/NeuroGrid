#include "Nano1Textarea.h"
#include "../../../../../language/Lexer.h"

Lexer *lexer;

Nano1Textarea::Nano1Textarea(Container *parentContainer, Vector2f position, uint8_t cols, uint8_t rows, Font *font, Color textColor): Textarea(parentContainer, position, cols, rows, font, textColor){
}

void Nano1Textarea::onHover() {

}

void Nano1Textarea::onLineExit(uint8_t line) {
	for(size_t i = 0; i < getLines()->size(); i++) {
		if(getLines()->at(i).empty()) {
			continue;
		}

		lexer = new Lexer(getLines()->at(i));
		if (!lexer->validateLine()){
			lineError = i;
			break;
		}
	}
}

void Nano1Textarea::onLineEnter(uint8_t line) {

}

void Nano1Textarea::onLineChange(uint8_t line) {
	// parse
}
