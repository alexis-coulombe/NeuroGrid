#ifndef ASM_MOVOPERATION_H
#define ASM_MOVOPERATION_H

#include "../Operation.h"

class MovOperation : public Operation {
 public:
	void execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) override;
 private:
	void mov(Nano *currentNano, Token operand1, Token operand2, uint8_t currentLine);
};

#endif