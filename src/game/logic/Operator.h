#ifndef ASM_OPERATOR_H
#define ASM_OPERATOR_H

#include "Nano.h"
#include "../../language/Lexer.h"

class Operation {
public:
    virtual void execute(Nano* currentNano, Lexer& lexer, uint8_t currentLine) = 0;
    virtual ~Operation() = default;
};

#endif