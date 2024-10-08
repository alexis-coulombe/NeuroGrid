#ifndef ASM_PARSERERROR_H
#define ASM_PARSERERROR_H

#include <cstdint>
#include <string>

class ParserError {
 public:
	enum ERROR_TYPE {
		NONE = 0,
		INVALID_OPERANDS,
		LABEL_NOT_FOUND,
		UNKNOWN_OPERATION,
		INVALID_TOKEN,
		DUPLICATE_LABEL,
		INVALID_OUTPUT
	};

	std::string message;
	ERROR_TYPE type = NONE;
	uint8_t line;

	ParserError(std::string message, ERROR_TYPE type, uint8_t line = 0);
};

#endif