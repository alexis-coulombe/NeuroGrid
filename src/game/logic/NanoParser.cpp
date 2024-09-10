#include "NanoParser.h"
#include "../../language/Lexer.h"

NanoParser::NanoParser(Nano *nano1, Nano *nano2, Nano *nano3) : nano1(nano1), nano2(nano2), nano3(nano3) {
}

void NanoParser::step() {
	parseLine(nano1);
	parseLine(nano2);
	parseLine(nano3);
}

void NanoParser::parseLine(Nano *currentNano) {
	if(currentNano->code->getNonEmptyLines() <= 0) {
		return;
	}

	std::string line = currentNano->code->getLines()->at(currentNano->currentParseLine);

	Lexer lexer = Lexer(line);
	Token token = lexer.next();

	currentNano->code->highlightedLine = currentNano->currentParseLine;

	if (token.type == Token::TOKEN_END) {
		currentNano->increaseParseLine();
		parseLine(currentNano);
		return;
	}

	if (token.type == Token::TOKEN_COMMENT) {
		currentNano->increaseParseLine();
		parseLine(currentNano);
		return;
	}

	if (token.type == Token::TOKEN_LABEL) {
		currentNano->increaseParseLine();
		parseLine(currentNano);
		return;
	}

	if (token.type == Token::TOKEN_SYMBOL) {
		OPERATION_TYPE operation = parseSymbol(token.text);
		auto operationHandler = OperationFactory::createOperation(operation);

		if (operationHandler != nullptr) {
			operationHandler->execute(currentNano, lexer, currentNano->currentParseLine);

			if (!currentNano->code->blocking) {
				currentNano->cycles++;
				currentNano->increaseParseLine();
			}
		} else {
			currentNano->code->error = ParserError("Unknown operation", "Operation not supported", ParserError::ERROR_TYPE::UNKNOWN_OPERATION, currentNano->currentParseLine);
		}

		return;
	}
}

OPERATION_TYPE NanoParser::parseSymbol(const std::string &symbol) {
	if (symbol == "MOV") {
		return OPERATION_TYPE::MOV;
	} else if (symbol == "ADD") {
		return OPERATION_TYPE::ADD;
	} else if (symbol == "SUB") {
		return OPERATION_TYPE::SUB;
	} else if (symbol == "NOP") {
		return OPERATION_TYPE::NOP;
	} else if (symbol == "JMP") {
		return OPERATION_TYPE::JMP;
	} else {
		return OPERATION_TYPE::INVALID_OP;
	}
}