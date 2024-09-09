#include "Operation.h"

uint8_t Operation::parseOperand(Nano *currentNano, Token operand, uint8_t currentLine)
{
    switch (operand.type) {
        case Token::TOKEN_NUMBER:
        {
            return std::stoi(operand.text);
        }
        case Token::TOKEN_REGISTER:
        {
            return getRegisterValue(currentNano, operand.text, currentLine);
        }
        case Token::TOKEN_IO: {
            if (operand.text == "IN") {
                // TODO: get current input from mission
                return 0; // Placeholder
            }
        }
        default: {
            currentNano->code->error = ParserError("Invalid operands", "Invalid operand type for SUB operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
            return 0;
        }
    }
}

uint8_t Operation::getRegisterValue(Nano* currentNano, const std::string &reg, uint8_t currentLine)
{
    if (reg == "M0") {
        return 0;   
    }
    
    if (reg == "M1") {
        return currentNano->memory
    }
    
    if (reg == "TEST") {
        return currentNano->test;
    }

    if (reg == "RX") {
        uint8_t value = currentNano->rx;
        currentNano->rx = 0;
        return value;
    }

    if (reg == "PC") {
        return currentNano->cycles;
    }

    currentNano->code->error = ParserError("Invalid operands", "Invalid register for SUB operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
    return 0;
}