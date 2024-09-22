#ifndef ASM_TEQOPERATION_H
#define ASM_TEQOPERATION_H

#include "../Operation.h"

class TeqOperation : public Operation {
 public:
	void execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) override;
 private:
	void teq(Nano *currentNano, Token operand1, Token operand2, uint8_t currentLine);
};

#endif