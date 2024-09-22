#ifndef ASM_TGEOPERATION_H
#define ASM_TGEOPERATION_H

#include "../Operation.h"

class TgeOperation : public Operation {
 public:
	void execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) override;
 private:
	void tge(Nano *currentNano, Token operand1, Token operand2, uint8_t currentLine);
};

#endif