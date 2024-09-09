#include "SubOperation.h"

void SubOperation::execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) {
	Token operand1 = lexer.next();
	Token operand2 = lexer.next();
	Token operand3 = lexer.next();

	if (operand1.type == Token::TOKEN_REGISTER) {
		sub(currentNano, operand1, operand2, operand3, currentLine);
	} else {
		currentNano->code->error = ParserError("Invalid operands", "Invalid operands for ADD operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
	}
}

void SubOperation::sub(Nano *currentNano, Token operand1, Token operand2, Token operand3, uint8_t currentLine) {
	if (operand1.text != "M1") {
		currentNano->code->error = ParserError("Invalid operands", "Invalid operands (1) for ADD operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
		return;
	}

	uint8_t substraction = 0;

	switch (operand2.type) {
		case Token::TOKEN_NUMBER: {
			substraction = std::stoi(operand2.text);
			break;
		}
		case Token::TOKEN_REGISTER: {
			if (operand2.text == "M0") {
				substraction = 0;
			} else if (operand2.text == "M1") {
				substraction = currentNano->memory;
			} else if (operand2.text == "TEST") {
				substraction = currentNano->test;
			} else if (operand2.text == "RX") {
				// blocking ?
				substraction = currentNano->rx;
				currentNano->rx = 0;
			} else if (operand2.text == "PC") {
				substraction = currentNano->cycles;
			} else {
				currentNano->code->error = ParserError("Invalid operands", "Invalid operands (2) for ADD operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
				return;
			}
			break;
		}
		case Token::TOKEN_IO: {
			if (operand2.text == "IN") {
				// TODO: get current input from mission
			} else {
				currentNano->code->error = ParserError("Invalid operands", "Invalid operands (2) for ADD operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
				return;
			}
			break;
		}
		default: {
			currentNano->code->error = ParserError("Invalid operands", "Invalid operands (2) for ADD operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
			break;
		}
	}

	switch (operand3.type) {
		case Token::TOKEN_NUMBER: {
			substraction -= std::stoi(operand3.text);
			break;
		}
		case Token::TOKEN_REGISTER: {
			if (operand3.text == "M0") {
				substraction -= 0;
			} else if (operand3.text == "M1") {
				substraction -= currentNano->memory;
			} else if (operand3.text == "TEST") {
				substraction -= currentNano->test;
			} else if (operand3.text == "RX") {
				// blocking ?
				substraction -= currentNano->rx;
				currentNano->rx = 0;
			} else if (operand3.text == "PC") {
				substraction -= currentNano->cycles;
			} else {
				currentNano->code->error = ParserError("Invalid operands", "Invalid operands (3) for ADD operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
				return;
			}
			break;
		}
		case Token::TOKEN_IO: {
			if (operand2.text == "IN") {
				// TODO: get current input from mission
			} else {
				currentNano->code->error = ParserError("Invalid operands", "Invalid operands (3) for ADD operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
				return;
			}
			break;
		}
		default: {
			currentNano->code->error = ParserError("Invalid operands", "Invalid operands (3) for ADD operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
			break;
		}
	}

	currentNano->memory = substraction;
}