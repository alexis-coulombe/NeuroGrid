#include "NanoParser.h"
#include "../../language/Lexer.h"

NanoParser::NanoParser(Nano *nano1, Nano *nano2, Nano *nano3) : currentCycle(0), nano1(nano1), nano2(nano2), nano3(nano3) {
}

void NanoParser::parseLine(Nano *currentNano, uint8_t currentLine) {
	std::string line = currentNano->code->getLines()->at(currentLine);
	OPERATION_TYPE operation;

	Lexer lexer = Lexer(line);
	Token token = lexer.next();

	if(token.type == Token::TOKEN_COMMENT || token.type == Token::TOKEN_END) {
		currentLine++;
		return;
	}

	if (token.type == Token::TOKEN_SYMBOL) {
		operation = parseSymbol(token.text);

		if (operation == NOP) {
			currentLine++;
			return;
		}

		if (operation == MOV) {
			Token operand1 = lexer.next();
			Token operand2 = lexer.next();

			if (operand1.type == Token::TOKEN_REGISTER && operand2.type == Token::TOKEN_IO) {
				executeMov(currentNano, parseRegister(operand1.text), parseIO(operand2.text));
			} else if (operand1.type == Token::TOKEN_IO && operand2.type == Token::TOKEN_REGISTER) {
				executeMov(currentNano, parseIO(operand1.text), parseRegister(operand2.text));
			} else if (operand1.type == Token::TOKEN_REGISTER && operand2.type == Token::TOKEN_REGISTER) {
				executeMov(currentNano, parseRegister(operand1.text), parseRegister(operand2.text));
			} else {
				// Handle error: invalid operands
			}
		}

		if(operation == ADD) {
			Token operand1 = lexer.next();
			Token operand2 = lexer.next();

			if(operand1.type == Token::TOKEN_REGISTER && operand2.type == Token::TOKEN_NUMBER) {
				// Handle ADD operation
			} else {
				// Handle error: invalid operands
			}
		}

		currentLine++;
		return;
	}
}

NanoParser::OPERATION_TYPE NanoParser::parseSymbol(std::string symbol){
	if(symbol == "MOV") {
		return NanoParser::OPERATION_TYPE::MOV;
	} else if (symbol == "ADD") {
		return NanoParser::OPERATION_TYPE::ADD;
	} else if (symbol == "SUB") {
		return NanoParser::OPERATION_TYPE::SUB;
	} else if (symbol == "MOD") {
		return NanoParser::OPERATION_TYPE::MOD;
	} else if (symbol == "JMP") {
		return NanoParser::OPERATION_TYPE::JMP;
	} else if (symbol == "JGT") {
		return NanoParser::OPERATION_TYPE::JGT;
	} else if (symbol == "JLT") {
		return NanoParser::OPERATION_TYPE::JLT;
	} else if (symbol == "JEQ") {
		return NanoParser::OPERATION_TYPE::JEQ;
	} else if (symbol == "NOP") {
		return NanoParser::OPERATION_TYPE::NOP;
	} else {
		// Handle error: invalid symbol
		return NanoParser::OPERATION_TYPE::INVALID_OP;
	}
}

NanoParser::REGISTER_TYPE NanoParser::parseRegister(std::string registerSymbol) {
	if(registerSymbol == "M") {
		return NanoParser::REGISTER_TYPE::MEMORY;
	} else if (registerSymbol == "N1") {
		return NanoParser::REGISTER_TYPE::NANO1;
	} else if (registerSymbol == "N2") {
		return NanoParser::REGISTER_TYPE::NANO2;
	} else if (registerSymbol == "N3") {
		return NanoParser::REGISTER_TYPE::NANO3;
	} else if (registerSymbol == "RX") {
		return NanoParser::REGISTER_TYPE::RX;
	} else {
		// Handle error: invalid register symbol
		return NanoParser::REGISTER_TYPE::INVALID_REG;
	}
}

NanoParser::IO_TYPE NanoParser::parseIO(std::string ioSymbol) {
	if(ioSymbol == "A") {
		return NanoParser::IO_TYPE::INPUT_A;
	} else if (ioSymbol == "B") {
		return NanoParser::IO_TYPE::INPUT_B;
	} else if (ioSymbol == "C") {
		return NanoParser::IO_TYPE::INPUT_C;
	} else if (ioSymbol == "D") {
		return NanoParser::IO_TYPE::OUTPUT_D;
	} else if (ioSymbol == "E") {
		return NanoParser::IO_TYPE::OUTPUT_E;
	} else if (ioSymbol == "F") {
		return NanoParser::IO_TYPE::OUTPUT_F;
	} else {
		// Handle error: invalid IO symbol
		return NanoParser::IO_TYPE::INVALID_IO;
	}
}

void NanoParser::executeMov(Nano *currentNano, IO_TYPE io, REGISTER_TYPE reg) {
	/*uint8_t value;

	switch (io) {
		case INPUT_A: {
			value = currentNano->mission->getAInputs().at(currentCycle) % currentNano->mission->getAInputs().size();
			break;
		}
		case INPUT_B: {
			value = currentNano->mission->getBInputs().at(currentCycle) % currentNano->mission->getAInputs().size();
			break;
		}
		case INPUT_C: {
			value = currentNano->mission->getCInputs().at(currentCycle) % currentNano->mission->getAInputs().size();
			break;
		}
		case OUTPUT_D:
		case OUTPUT_E:
		case OUTPUT_F:
		default: {
			// raise error, read only
			break;
		}
	}

	switch (reg) {
		case MEMORY: {
			currentNano->memory = value;
			break;
		}
		case RX: {
			// raise error, read only
			break;
		}
		case NANO1: {
			if (currentNano == nano1) {
				// raise error, can't write to self
			}

			nano1->rx = value;
			break;
		}
		case NANO2: {
			if (currentNano == nano2) {
				// raise error, can't write to self
			}

			nano2->rx = value;
			break;
		}
		case NANO3: {
			if (currentNano == nano3) {
				// raise error, can't write to self
			}

			nano3->rx = value;
			break;
		}
	}*/
}

void NanoParser::executeMov(Nano *currentNano, REGISTER_TYPE reg, IO_TYPE io) {
	/*uint8_t value;

	switch (reg) {
		case MEMORY: {
			value = currentNano->memory;
			break;
		}
		case RX: {
			value = currentNano->rx;
			break;
		}
		case NANO1:
		case NANO2:
		case NANO3: {
			// raise error, can't move from nanos
			break;
		}
	}

	switch (io) {
		case INPUT_A:
		case INPUT_B:
		case INPUT_C: {
			// raise error, read only
			break;
		}
		case OUTPUT_D: {
			currentNano->mission->setDOutput(currentCycle, value);
			break;
		}
		case OUTPUT_E: {
			currentNano->mission->setEOutput(currentCycle, value);
			break;
		}
		case OUTPUT_F: {
			currentNano->mission->setFOutput(currentCycle, value);
			break;
		}
	}*/
}

void NanoParser::executeMov(Nano *currentNano, REGISTER_TYPE reg1, REGISTER_TYPE reg2) {
	/*uint8_t value;

	switch (reg1) {
		case MEMORY: {
			value = currentNano->memory;
			break;
		}
		case RX:
		case NANO1:
		case NANO2:
		case NANO3: {
			// raise error, can't move from nanos
			break;
		}
	}

	switch (reg2) {
		case MEMORY: {
			currentNano->memory = value;
			break;
		}
		case RX: {
			// raise error, read only
			break;
		}
		case NANO1: {
			if (currentNano == nano1) {
				// raise error, can't write to self
			}

			nano1->rx = value;
			break;
		}
		case NANO2: {
			if (currentNano == nano2) {
				// raise error, can't write to self
			}

			nano2->rx = value;
			break;
		}
		case NANO3: {
			if (currentNano == nano3) {
				// raise error, can't write to self
			}

			nano3->rx = value;
			break;
		}
	}*/
}
