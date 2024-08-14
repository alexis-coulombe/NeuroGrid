#include "NanoParser.h"
#include "../../language/Lexer.h"

NanoParser::NanoParser(Nano *nano1, Nano *nano2, Nano *nano3) : currentCycle(0), nano1(nano1), nano2(nano2), nano3(nano3) {
}

void NanoParser::step() {
	parseLine(nano1, currentCycle);
	parseLine(nano2, currentCycle);
	parseLine(nano3, currentCycle);

	currentCycle++;
}

void NanoParser::parseLine(Nano *currentNano, uint8_t currentLine) {
	std::string line = currentNano->code->getLines()->at(currentLine);

	Lexer lexer = Lexer(line);
	Token token = lexer.next();

	currentNano->code->highlightedLine = currentLine;

	if (token.type == Token::TOKEN_COMMENT || token.type == Token::TOKEN_END) {
		currentLine++;
		return;
	}

	if (token.type == Token::TOKEN_SYMBOL) {
		OPERATION_TYPE operation = parseSymbol(token.text);
		auto operationHandler = OperationFactory::createOperation(operation);

		if (operationHandler != nullptr) {
			operationHandler->execute(currentNano, lexer, currentLine);
		} else {
			currentNano->code->error = ParserError("Unknown operation", "Operation not supported", ParserError::ERROR_TYPE::UNKNOWN_OPERATION, currentLine);
		}

		currentLine++;
		return;
	}
}

OPERATION_TYPE NanoParser::parseSymbol(const std::string& symbol) {
	if (symbol == "MOV") {
		return OPERATION_TYPE::MOV;
	} else if (symbol == "ADD") {
		return OPERATION_TYPE::ADD;
	} else if (symbol == "SUB") {
		return OPERATION_TYPE::SUB;
	} else if (symbol == "MOD") {
		return OPERATION_TYPE::MOD;
	} else if (symbol == "JMP") {
		return OPERATION_TYPE::JMP;
	} else if (symbol == "JGT") {
		return OPERATION_TYPE::JGT;
	} else if (symbol == "JLT") {
		return OPERATION_TYPE::JLT;
	} else if (symbol == "JEQ") {
		return OPERATION_TYPE::JEQ;
	} else if (symbol == "NOP") {
		return OPERATION_TYPE::NOP;
	} else {
		return OPERATION_TYPE::INVALID_OP;
	}
}