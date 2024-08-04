#include "src/engine/Engine.h"
#include "src/language/Lexer.h"

int main(int argc, char** args) {
    Engine engine = Engine();
    engine.start();
    engine.run();

		//std::string content = "      ADD 19 N1 #this is a comment";
		//Lexer lexer = Lexer(content);
		//Token token = lexer.next();
//
		//while(token.type != Token::TOKEN_END) {
		//	std::cout << "Type:" << token.type << " | Value:" << token.text << std::endl;
		//	token = lexer.next();
		//}

    return 0;
}
