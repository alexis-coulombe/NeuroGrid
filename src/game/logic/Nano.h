#ifndef ASM_SRC_GAME_NANO_H_
#define ASM_SRC_GAME_NANO_H_

#include <cstdint>
#include "../../engine/ui/Textarea.h"

class Nano {
 public:
	uint8_t memory = 0;
	uint8_t test = 0;
	uint8_t rx = 0;
	uint16_t cycles = 0;

	Textarea *code;

	uint8_t currentParseLine = 0;

	explicit Nano(Textarea *code);
	void setParentContainer(Container *container);
	void render();
};

#endif //ASM_SRC_GAME_NANO_H_
