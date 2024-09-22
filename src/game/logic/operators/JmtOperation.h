#ifndef ASM_JMTOPERATION_H
#define ASM_JMTOPERATION_H

#include "../Operation.h"

class JmtOperation : public Operation {
 public:
	void execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) override;
 private:
	void jmt(Nano *currentNano, Token operand1, uint8_t currentLine);
};

#endif