#ifndef ASM_SRC_GAME_LOGIC_NANOPARSER_H_
#define ASM_SRC_GAME_LOGIC_NANOPARSER_H_

#include <cstdint>
#include "Nano.h"
#include "OperationFactory.h"
#include "operators/OperationType.h"

class NanoParser {
 public:
	Nano *nano1;
	Nano *nano2;
	Nano *nano3;

	NanoParser(Nano *nano1, Nano *nano2, Nano *nano3);

	void step();
	void stop();
	void parseLine(Nano *currentNano);
	OPERATION_TYPE parseSymbol(const std::string& symbol);
 private:
	uint8_t parserCounter = 0;
};

#endif //ASM_SRC_GAME_LOGIC_NANOPARSER_H_
