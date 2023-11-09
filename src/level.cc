#include "level.h"
#include "tetris.h"

Level::Level(std::string standard_sequence_file, bool rand, int seed) :
seq{standard_sequence_file},
rand{rand},
seed{seed} {
#if DEBUG_LEVEL > 0
    #include <iostream>
    std::cout << "Level Constructor" << std::endl;
#endif
}

Level::~Level() {
#if DEBUG_LEVEL > 0
    #include <iostream>
    std::cout << "Level Destructor" << std::endl;
#endif
}
