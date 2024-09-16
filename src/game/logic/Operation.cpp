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
			if (operand.text == "A") {
				uint8_t value = std::stoi(MissionManager::getInstance()->currentMission->getInputAText()->lines.at(currentNano->currentInputALine));
				currentNano->increaseInputLine(Nano::INPUTS::A);
				return value;
			}

			if (operand.text == "B") {
				uint8_t value = std::stoi(MissionManager::getInstance()->currentMission->getInputAText()->lines.at(currentNano->currentInputBLine));
				currentNano->increaseInputLine(Nano::INPUTS::B);
				return value;
			}

			if (operand.text == "C") {
				uint8_t value = std::stoi(MissionManager::getInstance()->currentMission->getInputAText()->lines.at(currentNano->currentInputCLine));
				currentNano->increaseInputLine(Nano::INPUTS::C);
				return value;
			}

			currentNano->code->error = ParserError("Invalid operands", "Can't read from output register", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
			return 0;
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
			if (operand.text == "D") {
				MissionManager::getInstance()->currentMission->getOutputDText()->lines.at(currentNano->currentOutputDLine) = std::to_string(value);
				break;
			}

			if (operand.text == "E") {
				MissionManager::getInstance()->currentMission->getOutputEText()->lines.at(currentNano->currentOutputELine) = std::to_string(value);
				break;
			}

			if (operand.text == "F") {
				MissionManager::getInstance()->currentMission->getOutputFText()->lines.at(currentNano->currentOutputFLine) = std::to_string(value);
				break;
			}

			currentNano->code->error = ParserError("Invalid operands", "Can't write to input register", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
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

		if (value == 0) {
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