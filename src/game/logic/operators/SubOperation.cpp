#include "SubOperation.h"

void SubOperation::execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) {
	Token operand1 = lexer.next();
	Token operand2 = lexer.next();
	Token operand3 = lexer.next();

	if (operand1.type == Token::TOKEN_REGISTER) {
		sub(currentNano, operand1, operand2, operand3, currentLine);
	} else {
		currentNano->code->error = ParserError("Invalid operands for SUB, first operant mu be a REGISTER", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
	}
}

void SubOperation::sub(Nano *currentNano, Token operand1, Token operand2, Token operand3, uint8_t currentLine) {
	uint8_t substraction = getParseOperand(currentNano, operand2, currentLine);

	if (currentNano->code->error.type != ParserError::ERROR_TYPE::NONE) {
		return;
	}

	substraction -= getParseOperand(currentNano, operand3, currentLine);

	if (currentNano->code->error.type != ParserError::ERROR_TYPE::NONE) {
		return;
	}

	setParseOperand(currentNano, operand1, substraction, currentLine);
}