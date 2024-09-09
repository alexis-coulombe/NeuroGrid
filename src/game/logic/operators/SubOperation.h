#ifndef ASM_SUBOPERATION_H
#define ASM_SUBOPERATION_H

#include "../Operator.h"

class SubOperation : public Operation {
 public:
	void execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) override;
 private:
	void sub(Nano *currentNano, Token operand1, Token operand2, Token operand3, uint8_t currentLine);
};

#endif