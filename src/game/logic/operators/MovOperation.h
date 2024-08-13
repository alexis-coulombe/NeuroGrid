#ifndef ASM_MOVOPERATION_H
#define ASM_MOVOPERATION_H

#include "Operator.h"

class MovOperation : public Operation {
public:
    void execute(Nano* currentNano, Lexer& lexer, uint8_t currentLine) override;
};

#endif