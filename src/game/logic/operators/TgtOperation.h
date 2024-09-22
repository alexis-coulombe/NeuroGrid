#ifndef ASM_TGTOPERATION_H
#define ASM_TGTOPERATION_H

#include "../Operation.h"

class TgtOperation : public Operation {
 public:
	void execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) override;
 private:
	void tgt(Nano *currentNano, Token operand1, Token operand2, uint8_t currentLine);
};

#endif