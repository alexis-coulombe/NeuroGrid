#ifndef ASM_ADDOPERATION_H
#define ASM_ADDOPERATION_H

#include "../Operator.h"

class AddOperation : public Operation {
 public:
	void execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) override;
 private:
	void add(Nano *currentNano, Token operand1, Token operand2, Token operand3, uint8_t currentLine);
};

#endif