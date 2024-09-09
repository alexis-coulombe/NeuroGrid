#include "NopOperation.h"

void NopOperation::execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) {
	Token operand1 = lexer.next();

	if (operand1.type != Token::TOKEN_END) {
		currentNano->code->error = ParserError("Invalid operands", "Invalid operands (1) for NOP operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
	}
}