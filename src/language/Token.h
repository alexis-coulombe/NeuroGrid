#ifndef ASM_SRC_LANGUAGE_TOKEN_H_
#define ASM_SRC_LANGUAGE_TOKEN_H_

#include <string>

class Token {
 public:
	enum TokenType {
		TOKEN_END = 0,
		TOKEN_SYMBOL,
		TOKEN_IO,
		TOKEN_REGISTER,
		TOKEN_NUMBER,
		TOKEN_COMMENT,
		TOKEN_LABEL,
		TOKEN_INVALID
	};

	TokenType type;
	std::string text;
};

#endif //ASM_SRC_LANGUAGE_TOKEN_H_
