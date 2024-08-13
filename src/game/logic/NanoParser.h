#ifndef ASM_SRC_GAME_LOGIC_NANOPARSER_H_
#define ASM_SRC_GAME_LOGIC_NANOPARSER_H_

#include <cstdint>
#include "Nano.h"
#include "OperationFactory.h"
#include "operators/OperationType.h"

class NanoParser {
 public:
	uint8_t currentCycle = 0;

	Nano *nano1;
	Nano *nano2;
	Nano *nano3;

	NanoParser(Nano *nano1, Nano *nano2, Nano *nano3);

	void parseLine(Nano *currentNano, uint8_t currentLine);
	OPERATION_TYPE parseSymbol(std::string symbol);
};

#endif //ASM_SRC_GAME_LOGIC_NANOPARSER_H_
