#include "ParserError.h"
#include "../../engine/ui/Textarea.h"

ParserError::ParserError(std::string message, ParserError::ERROR_TYPE type, uint8_t line) : type(type), line(line) {
	if(line == Textarea::NOT_FOUND) {
		this->message = message;
		return;
	}

	this->message = "Line " + std::to_string(line) + ": " + message;
}