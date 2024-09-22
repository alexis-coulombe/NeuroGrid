#include "MovOperation.h"
#include "../../MissionManager.h"

void MovOperation::execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) {
	Token operand1 = lexer.next();
	Token operand2 = lexer.next();
	mov(currentNano, operand1, operand2, currentLine);
}

void MovOperation::mov(Nano *currentNano, Token operand1, Token operand2, uint8_t currentLine) {
	if (operand1.text == "IN") {
		currentNano->code->error = ParserError("Invalid operands for MOV, can't write to input", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
		return;
	}

	uint8_t value = getParseOperand(currentNano, operand2, currentLine);

	if (!currentNano->code->blocking) {
		setParseOperand(currentNano, operand1, value, currentLine);
	}
}