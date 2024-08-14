#include "ParserError.h"

ParserError::ParserError(std::string title, std::string message, ParserError::ERROR_TYPE type, uint8_t line) : title(title), message(message), type(type), line(line) {
}