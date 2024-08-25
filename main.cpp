#include "src/engine/Engine.h"
#include "src/language/Lexer.h"
#include "src/engine/fileIO/SaveFileManager.h"

int main(int argc, char** args) {
    //Engine engine = Engine();
    //engine.start();
    //engine.run();

		SaveFileManager::saveGame();

		return 0;
}
