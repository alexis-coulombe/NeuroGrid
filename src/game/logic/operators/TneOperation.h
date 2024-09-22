#ifndef ASM_TNEOPERATION_H
#define ASM_TNEOPERATION_H

#include "../Operation.h"

class TneOperation : public Operation {
 public:
	void execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) override;
 private:
	void tne(Nano *currentNano, Token operand1, Token operand2, uint8_t currentLine);
};

#endif