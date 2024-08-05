#include "Lexer.h"

Lexer::Lexer(std::string content) : content(content) {
}

Token Lexer::next() {
	trimLeft();

	Token token = Token();

	if (cursor >= content.length()) {
		token.type = Token::TOKEN_END;
		return token;
	}

	if (content.at(cursor) == '#') {
		token.type = Token::TOKEN_COMMENT;
		token.text.push_back(content.at(cursor));
		while (cursor < content.length() && content.at(cursor) != '\n') {
			cursor++;
		}
		return token;
	}

	if (isSymbolStart(content.at(cursor))) {
		token.type = Token::TOKEN_SYMBOL;
		while (cursor < content.length() && isSymbol(content.at(cursor))) {
			token.text.push_back(content.at(cursor));
			cursor++;
		}
		return token;
	}

	if (isdigit(content.at(cursor))) {
		token.type = Token::TOKEN_NUMBER;
		while (cursor < content.length()) {
			if (isdigit(content.at(cursor))) {
				token.text.push_back(content.at(cursor));
				cursor++;
			} else if (content.at(cursor) == ' ') {
				return token;
			} else {
				token.type = Token::TOKEN_INVALID;
				return token;
			}
		}
	}

	token.type = Token::TOKEN_INVALID;
	cursor++;

	return token;
}

void Lexer::trimLeft() {
	while (cursor < content.length() && isspace(content.at(cursor))) {
		cursor++;
	}
}

bool Lexer::isSymbolStart(char c) {
	return isalpha(c);
}

bool Lexer::isSymbol(char c) {
	return isalnum(c);
}

bool Lexer::validateLine() {
	Token token;

	while (token.type != Token::TOKEN_END) {
		token = next();
		if (token.type == Token::TOKEN_INVALID) {
			return false;
		}
	}

	return true;
}