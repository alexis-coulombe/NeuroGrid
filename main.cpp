#include <iostream>
#include "src/engine/Engine.h"

// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char** args) {
    Engine engine = Engine();
    engine.start();
    engine.run();
    return 0;
}
