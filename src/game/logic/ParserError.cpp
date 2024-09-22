#include "ParserError.h"

ParserError::ParserError(std::string message, ParserError::ERROR_TYPE type, uint8_t line) : type(type), line(line) {
	this->message = "Line " + std::to_string(line) + ": " + message;
}