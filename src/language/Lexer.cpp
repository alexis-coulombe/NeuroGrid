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

	if(content.at(cursor) == '.') {
		token.type = Token::TOKEN_LABEL;
		cursor++;
		while (cursor < content.length() && isSymbol(content.at(cursor))) {
			token.text.push_back(content.at(cursor));
			cursor++;
		}
		if (cursor < content.length() && content.at(cursor) == ' ') {
			token.type = Token::TOKEN_INVALID;
		}
		return token;
	}

	if (isSymbolStart(content.at(cursor))) {
		token.type = Token::TOKEN_SYMBOL;
		while (cursor < content.length() && isSymbol(content.at(cursor))) {
			token.text.push_back(content.at(cursor));
			cursor++;
		}

		if (token.text == "M0" || token.text == "M1" || token.text == "PC" ||
			  token.text == "RX" || token.text == "N1" || token.text == "N2" ||
				token.text == "N3") {
			token.type = Token::TOKEN_REGISTER;
		} else if (token.text == "A" || token.text == "B" || token.text == "C" || token.text == "D" || token.text == "E" || token.text == "F") {
			token.type = Token::TOKEN_IO;
		}

		return token;
	}

	if (isdigit(content.at(cursor))) {
		token.type = Token::TOKEN_NUMBER;
		while (cursor < content.length() && isdigit(content.at(cursor))) {
			token.text.push_back(content.at(cursor));
			cursor++;
		}
		if (cursor < content.length() && content.at(cursor) != ' ') {
			token.type = Token::TOKEN_INVALID;
		}
    	return token;
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