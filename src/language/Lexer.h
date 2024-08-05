#ifndef ASM_SRC_LANGUAGE_LEXER_H_
#define ASM_SRC_LANGUAGE_LEXER_H_

#include <string>
#include "Token.h"

class Lexer {
 public:
	std::string content;
	size_t cursor = 0;

	Lexer(std::string content);

	Token next();

	void trimLeft();
	bool isSymbolStart(char c);
	bool isSymbol(char c);
	bool validateLine();
};

#endif //ASM_SRC_LANGUAGE_LEXER_H_
