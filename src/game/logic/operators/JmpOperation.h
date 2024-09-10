#ifndef ASM_JMPOPERATION_H
#define ASM_JMPOPERATION_H

#include "../Operation.h"

class JmpOperation : public Operation {
 public:
	void execute(Nano *currentNano, Lexer &lexer, uint8_t currentLine) override;
 private:
	void jmp(Nano *currentNano, Token operand1, uint8_t currentLine);
};

#endif