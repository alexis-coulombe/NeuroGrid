#include "src/engine/Engine.h"
#include "src/language/Lexer.h"

int main(int argc, char** args) {
    Engine engine = Engine();
    engine.start();
    engine.run();

		return 0;
}
