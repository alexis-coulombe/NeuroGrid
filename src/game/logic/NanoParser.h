#ifndef ASM_SRC_GAME_LOGIC_NANOPARSER_H_
#define ASM_SRC_GAME_LOGIC_NANOPARSER_H_

#include <cstdint>
#include "Nano.h"
class NanoParser {
 public:
	uint8_t currentCycle = 0;

	Nano *nano1;
	Nano *nano2;
	Nano *nano3;

	enum OPERATION_TYPE {
		MOV = 0,
		ADD,
		SUB,
		MOD,
		JMP,
		JGT,
		JLT,
		JEQ,
		NOP,
		INVALID_OP
	};

	enum IO_TYPE {
		INPUT_A = 0,
		INPUT_B,
		INPUT_C,
		OUTPUT_D,
		OUTPUT_E,
		OUTPUT_F,
		INVALID_IO
	};

	enum REGISTER_TYPE {
		MEMORY = 0,
		RX,
		NANO1,
		NANO2,
		NANO3,
		INVALID_REG
	};

	NanoParser(Nano *nano1, Nano *nano2, Nano *nano3);

	void parseLine(Nano *currentNano, uint8_t currentLine);
	OPERATION_TYPE parseSymbol(std::string symbol);
	REGISTER_TYPE parseRegister(std::string registerSymbol);
	IO_TYPE parseIO(std::string ioSymbol);

	/*
	 * Input to register
	 */
	void executeMov(Nano *currentNano, IO_TYPE io, REGISTER_TYPE reg);

	/**
	 * Register to output
	 */
	void executeMov(Nano *currentNano, REGISTER_TYPE reg, IO_TYPE io);

	/**
	 * Register to register
	 */
	void executeMov(Nano *currentNano, REGISTER_TYPE reg1, REGISTER_TYPE reg2);
};

#endif //ASM_SRC_GAME_LOGIC_NANOPARSER_H_
