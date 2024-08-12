#include "NanoTextarea.h"
#include "../../language/Lexer.h"

Lexer *lexer;

NanoTextarea::NanoTextarea(Container *parentContainer, Vector2f position, uint8_t cols, uint8_t rows, Font *font, Color textColor): Textarea(parentContainer, position, cols, rows, font, textColor){
}

void NanoTextarea::onHover() {

}

void NanoTextarea::onLineExit(uint8_t line) {
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

void NanoTextarea::onLineEnter(uint8_t line) {

}

void NanoTextarea::onLineChange(uint8_t line) {
	// parse
}
