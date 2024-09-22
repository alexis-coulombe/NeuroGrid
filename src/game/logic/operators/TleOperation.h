#ifndef ASM_TLEOPERATION_H
#define ASM_TLEOPERATION_H

#include "../Operation.h"

class TleOperation : public Operation {
 public:
	void execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) override;
 private:
	void tle(Nano *currentNano, Token operand1, Token operand2, uint8_t currentLine);
};

#endif