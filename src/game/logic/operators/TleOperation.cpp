#include "TleOperation.h"

void TleOperation::execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) {
	Token operand1 = lexer.next();
	Token operand2 = lexer.next();

	tle(currentNano, operand1, operand2, currentLine);
}

void TleOperation::tle(Nano *currentNano, Token operand1, Token operand2, uint8_t currentLine) {
	uint8_t value1 = getParseOperand(currentNano, operand1, currentLine);
	uint8_t value2 = getParseOperand(currentNano, operand2, currentLine);

	currentNano->test = value1 <= value2;
}