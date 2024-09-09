#ifndef ASM_OPERATION_H
#define ASM_OPERATION_H

#include "Nano.h"
#include "../../language/Lexer.h"

class Operation {
public:
    virtual void execute(Nano* currentNano, Lexer& lexer, uint8_t currentLine) = 0;
    virtual ~Operation() = default;

    uint8_t parseOperand(Nano *currentNano, Token operand, uint8_t currentLine);
    uint8_t getRegisterValue(Nano* currentNano, const std::string &reg, uint8_t currentLine);
};

#endif