#ifndef ASM_SRC_GAME_LOGIC_OPERATORS_NOPOPERATION_H_
#define ASM_SRC_GAME_LOGIC_OPERATORS_NOPOPERATION_H_

#include "../Operation.h"

class NopOperation : public Operation {
 public:
	void execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) override;
};

#endif //ASM_SRC_GAME_LOGIC_OPERATORS_NOPOPERATION_H_
