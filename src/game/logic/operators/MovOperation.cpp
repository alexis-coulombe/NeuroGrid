#include "MovOperation.h"

void MovOperation::execute(Nano* currentNano, Lexer& lexer, uint8_t currentLine) override {
    Token operand1 = lexer.next();
    Token operand2 = lexer.next();
    if (operand1.type == Token::TOKEN_REGISTER && operand2.type == Token::TOKEN_IO) {
        executeMov(currentNano, parseRegister(operand1.text), parseIO(operand2.text));
    } 
    else if (operand1.type == Token::TOKEN_IO && operand2.type == Token::TOKEN_REGISTER) {
        executeMov(currentNano, parseIO(operand1.text), parseRegister(operand2.text));
    } 
    else if (operand1.type == Token::TOKEN_REGISTER && operand2.type == Token::TOKEN_REGISTER) {
        executeMov(currentNano, parseRegister(operand1.text), parseRegister(operand2.text));
    } 
    else {
        currentNano->code->error = new ParserError("Invalid operands", "Invalid operands for MOV operation", ParserError::ERROR_TYPE::INVALID_OPERANDS, currentLine);
    }
}