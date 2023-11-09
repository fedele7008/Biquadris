#include "level_0.h"
#include "tetris.h"

Level_0::Level_0(const std::string &standard_sequence_file, int seed) :
Level{standard_sequence_file,false, seed} {
#if DEBUG_LEVEL > 0
    #include <iostream>
    std::cout << "Level_0 Constructor" << std::endl;
#endif
}

BlockShape Level_0::getNextBlock() {
    BlockShape temp;
    try {
        temp = seq.get_next_block();
    } catch (EmptySequenceException &err) {
        throw err;
    }
    return temp;
}

void Level_0::noRandom(const std::string &file_name) {
}

void Level_0::random() {
}

void Level_0::action_left(Tetris *tetris) {} // DO nothing by default

void Level_0::action_right(Tetris *tetris) {} // DO nothing by default

void Level_0::action_down(Tetris *tetris) {} // DO nothing by default

void Level_0::action_drop(Tetris *tetris, int row_cleared) {} // DO nothing by default

void Level_0::action_clockwise(Tetris *tetris) {} // DO nothing by default

void Level_0::action_counter_clockwise(Tetris *tetris) {} // DO nothing by default