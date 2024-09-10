#include "Operation.h"
#include "../MissionManager.h"

uint8_t Operation::getParseOperand(Nano *currentNano, Token operand, uint8_t currentLine) {
	switch (operand.type) {
		case Token::TOKEN_NUMBER: {
			return std::stoi(operand.text);
		}
		case Token::TOKEN_REGISTER: {
			return getRegisterValue(currentNano, operand.text, currentLine);
		}
		case Token::TOKEN_IO: {
			if (operand.text == "IN") {
				// TODO: get current input from mission
				return 0; // Placeholder
			}
		}
		default: {
			currentNano->code->error = ParserError("Invalid operands", "Invalid operand type for SUB operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
			return 0;
		}
	}
}

void Operation::setParseOperand(Nano *currentNano, Token operand, uint8_t value, uint8_t currentLine) {
	switch (operand.type) {
		case Token::TOKEN_REGISTER: {
			setRegisterValue(currentNano, operand.text, value, currentLine);
			break;
		}
		case Token::TOKEN_IO: {
			if (operand.text == "OUT") {
				// TODO
			}
			break;
		}
		default: {
			currentNano->code->error = ParserError("Invalid operands", "Invalid operand type for SUB operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
		}
	}
}

uint8_t Operation::getRegisterValue(Nano *currentNano, const std::string &reg, uint8_t currentLine) {
	if (reg == "M0") {
		return 0;
	}

	if (reg == "M1") {
		return currentNano->memory;
	}

	if (reg == "TEST") {
		return currentNano->test;
	}

	if (reg == "RX") {
		uint8_t value = currentNano->rx;

		if(value == 0) {
			currentNano->code->blocking = true;
			return 0;
		} else {
			currentNano->code->blocking = false;
		}

		currentNano->rx = 0;
		return value;
	}

	if (reg == "PC") {
		return currentNano->cycles;
	}

	currentNano->code->error = ParserError("Invalid operands", "Invalid register source for operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
	return 0;
}

void Operation::setRegisterValue(Nano *currentNano, const std::string &reg, uint8_t value, uint8_t currentLine) {
	if (reg == "M0") {
		return;
	}

	if (reg == "M1") {
		currentNano->memory = value;
		return;
	}

	if (reg == "TEST") {
		currentNano->test = value;
		return;
	}

	if (reg == "RX") {
		currentNano->rx = value;
		return;
	}

	if (reg == "N1") {
		MissionManager::getInstance()->currentMission->getNano(Mission::NANO1)->rx = value;
		return;
	}

	if (reg == "N2") {
		MissionManager::getInstance()->currentMission->getNano(Mission::NANO2)->rx = value;
		return;
	}

	if (reg == "N3") {
		MissionManager::getInstance()->currentMission->getNano(Mission::NANO3)->rx = value;
		return;
	}

	currentNano->code->error = ParserError("Invalid operands", "Invalid register destination for operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
}