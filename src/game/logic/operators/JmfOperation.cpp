#include "JmfOperation.h"

void JmfOperation::execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) {
	Token operand1 = lexer.next();

	if (operand1.type == Token::TOKEN_SYMBOL) {
		jmf(currentNano, operand1, currentLine);
	} else {
		currentNano->code->error = ParserError("Malformed expression for JMP, first operand must be a valid LABEL", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
	}
}

void JmfOperation::jmf(Nano *currentNano, Token operand1, uint8_t currentLine) {
	uint8_t labelLine = currentNano->code->getLineOfLabel(operand1.text);

	if(currentNano->test >= 1) {
		return;
	}

	if (labelLine == Textarea::NOT_FOUND) {
		currentNano->code->error = ParserError("Label \"" + operand1.text + "\" was not found", ParserError::ERROR_TYPE::LABEL_NOT_FOUND, currentLine);
		return;
	}

	if(labelLine == Textarea::DUPLICATE) {
		currentNano->code->error = ParserError("Conflict during JMP, duplicate label \"" + operand1.text + "\" found", ParserError::ERROR_TYPE::DUPLICATE_LABEL, currentLine);
		return;
	}

	while (currentNano->currentParseLine != labelLine) {
		currentNano->increaseParseLine();
	}
}