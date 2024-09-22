#ifndef ASM_TLTOPERATION_H
#define ASM_TLTOPERATION_H

#include "../Operation.h"

class TltOperation : public Operation {
 public:
	void execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) override;
 private:
	void tlt(Nano *currentNano, Token operand1, Token operand2, uint8_t currentLine);
};

#endif