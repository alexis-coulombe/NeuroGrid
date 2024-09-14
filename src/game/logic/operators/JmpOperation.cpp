#include "JmpOperation.h"

void JmpOperation::execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) {
	Token operand1 = lexer.next();

	if (operand1.type == Token::TOKEN_SYMBOL) {
		jmp(currentNano, operand1, currentLine);
	} else {
		currentNano->code->error = ParserError("Invalid operands", "Invalid operands for ADD operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
	}
}

void JmpOperation::jmp(Nano *currentNano, Token operand1, uint8_t currentLine) {
	uint8_t labelLine = currentNano->code->getLineOfLabel(operand1.text);

	if (labelLine == 0xFF) {
		currentNano->code->error = ParserError("Label not found", "Label not found", ParserError::ERROR_TYPE::LABEL_NOT_FOUND, currentLine);
		return;
	}

	while (currentNano->currentParseLine != labelLine) {
		currentNano->increaseParseLine();
	}
}