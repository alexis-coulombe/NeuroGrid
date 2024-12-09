#include "NanoParser.h"
#include "../MissionManager.h"
#include "../AssetLibrary.h"
#include "../../engine/Audio.h"

NanoParser::NanoParser(Nano *nano1, Nano *nano2, Nano *nano3) : nano1(nano1), nano2(nano2), nano3(nano3) {
}

void NanoParser::step() {
	Mission *mission = MissionManager::getInstance()->currentMission;

	if (!mission->getParsing()) {
		mission->setParsing(true);
	}

	if(mission->getFinished()) {
		mission->setAutoStep(false);
		if(mission->validate()) {
			mission->getFinishedWinPopup()->show();
			Audio::playSound(const_cast<Sound *>(AssetLibrary::SUCCESS_SOUND), false);
			mission->reset();
		} else {
			nano1->code->error = ParserError("The output does not match the expected output", ParserError::ERROR_TYPE::INVALID_OUTPUT, Textarea::NOT_FOUND);
			Audio::playSound(const_cast<Sound *>(AssetLibrary::ERROR_SOUND), false);
		}
		return;
	}

	parserCounter = 0;
	parseLine(nano1);
	parserCounter = 0;
	parseLine(nano2);
	parserCounter = 0;
	parseLine(nano3);

	if (nano1->code->error.type != ParserError::ERROR_TYPE::NONE || nano2->code->error.type != ParserError::ERROR_TYPE::NONE || nano3->code->error.type != ParserError::ERROR_TYPE::NONE) {
		mission->reset();
		Audio::playSound(const_cast<Sound *>(AssetLibrary::ERROR_SOUND), false);
		return;
	}
}

void NanoParser::stop() {
	Mission *mission = MissionManager::getInstance()->currentMission;

	mission->reset();
}

void NanoParser::parseLine(Nano *currentNano) {
	parserCounter++;
	Mission *mission = MissionManager::getInstance()->currentMission;

	if (currentNano->code->getNonEmptyLines() <= 0 || parserCounter > MAX_TEXTAREA_LINES) {
		return;
	}

	std::string line = currentNano->code->getLines()->at(currentNano->currentParseLine);

	Lexer lexer = Lexer(line);
	Token token = lexer.next();

	currentNano->code->highlightedLine = currentNano->currentParseLine;
	mission->getIOText(Mission::IO::A)->highlightedLine = mission->currentInputALine;
	mission->getIOText(Mission::IO::B)->highlightedLine = mission->currentInputBLine;
	mission->getIOText(Mission::IO::C)->highlightedLine = mission->currentInputCLine;
	mission->getIOText(Mission::IO::D)->highlightedLine = mission->currentOutputDLine;
	mission->getIOText(Mission::IO::E)->highlightedLine = mission->currentOutputELine;
	mission->getIOText(Mission::IO::F)->highlightedLine = mission->currentOutputFLine;

	if (token.type == Token::TOKEN_INVALID) {
		currentNano->code->error = ParserError("Invalid token", ParserError::ERROR_TYPE::INVALID_TOKEN, currentNano->currentParseLine);
		return;
	}

	// Skip these tokens
	if (token.type == Token::TOKEN_END || token.type == Token::TOKEN_COMMENT || token.type == Token::TOKEN_LABEL) {
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
			currentNano->code->error = ParserError("Operation not supported", ParserError::ERROR_TYPE::UNKNOWN_OPERATION, currentNano->currentParseLine);
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
	} else if (symbol == "JMT") {
		return OPERATION_TYPE::JMT;
	} else if (symbol == "JMF") {
		return OPERATION_TYPE::JMF;
	} else if (symbol == "TEQ") {
		return OPERATION_TYPE::TEQ;
	} else if (symbol == "TNE") {
		return OPERATION_TYPE::TNE;
	} else if (symbol == "TLT") {
		return OPERATION_TYPE::TLT;
	} else if (symbol == "TLE") {
		return OPERATION_TYPE::TLE;
	} else if (symbol == "TGT") {
		return OPERATION_TYPE::TGT;
	} else if (symbol == "TGE") {
		return OPERATION_TYPE::TGE;
	} else {
		return OPERATION_TYPE::INVALID_OP;
	}
}