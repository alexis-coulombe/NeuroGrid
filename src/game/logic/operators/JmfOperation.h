#ifndef ASM_JMFOPERATION_H
#define ASM_JMFOPERATION_H

#include "../Operation.h"

class JmfOperation : public Operation {
 public:
	void execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) override;
 private:
	void jmf(Nano *currentNano, Token operand1, uint8_t currentLine);
};

#endif