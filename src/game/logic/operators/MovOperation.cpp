#include "MovOperation.h"

void MovOperation::execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) {
	Token operand1 = lexer.next();
	Token operand2 = lexer.next();
	if (operand1.type == Token::TOKEN_REGISTER && operand2.type == Token::TOKEN_IO
	 || operand1.type == Token::TOKEN_IO && operand2.type == Token::TOKEN_REGISTER
	 || operand1.type == Token::TOKEN_REGISTER && operand2.type == Token::TOKEN_REGISTER) {
		mov(currentNano, operand1, operand2, currentLine);
	} else {
		currentNano->code->error = ParserError("Invalid operands", "Invalid operands for MOV operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
	}
}

void MovOperation::mov(Nano *currentNano, Token operand1, Token operand2, uint8_t currentLine) {
}