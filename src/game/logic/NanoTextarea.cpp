#include "NanoTextarea.h"
#include "../../language/Lexer.h"

Lexer *lexer;

NanoTextarea::NanoTextarea(Container *parentContainer, Vector2f position, Font *font, Color textColor) : Textarea(parentContainer, position, font, textColor) {
}

void NanoTextarea::onBeforeRender(uint8_t line) {
	if (error.type != ParserError::NONE && line == error.line) {
		Graphics::drawRectSolid(Bounds2(bounds->position.x, bounds->position.y + (line * font->textHeight), bounds->size.x, (float) font->textHeight), Color(Color::RED, 255/3));
	}
}

void NanoTextarea::onAfterRender(uint8_t line) {

}

void NanoTextarea::onHover() {

}

void NanoTextarea::onLineExit(uint8_t line) {
	// TODO: validate line ?
}

void NanoTextarea::onLineEnter(uint8_t line) {

}

void NanoTextarea::onLineChange(uint8_t line) {
	error = ParserError("", ParserError::ERROR_TYPE::NONE);
}
