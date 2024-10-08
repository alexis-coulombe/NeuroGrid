#ifndef ASM_SRC_GAME_NANO_H_
#define ASM_SRC_GAME_NANO_H_

#include <cstdint>
#include "NanoTextarea.h"

class Nano {
 public:
	uint8_t memory = 0;
	uint8_t test = 0;
	uint8_t rx = 0;
	uint16_t cycles = 0;

	// Parser variables
	enum INPUTS {
		A,
		B,
		C
	};

	enum OUTPUTS {
		D,
		E,
		F
	};

	NanoTextarea *code;
	uint8_t currentParseLine = 0;

	explicit Nano(NanoTextarea *code);
	void setParentContainer(Container *container);
	void render();
	void increaseParseLine();
	void reset();
};

#endif //ASM_SRC_GAME_NANO_H_
