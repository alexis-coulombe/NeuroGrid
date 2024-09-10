#ifndef ASM_PARSERERROR_H
#define ASM_PARSERERROR_H

#include <string>

class ParserError {
 public:
	enum ERROR_TYPE {
		NONE = 0,
		INVALID_OPERANDS,
		LABEL_NOT_FOUND,
		UNKNOWN_OPERATION,
	};

	std::string title;
	std::string message;
	ERROR_TYPE type = NONE;
	uint8_t line;

	ParserError(std::string title = "", std::string message = "", ERROR_TYPE type = NONE, uint8_t line = 0);
};

#endif