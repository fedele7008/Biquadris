#include "level_1.h"
#include "blockShape.h"
#include "tetris.h"
#include <vector>
#include <cstdlib>

Level_1::Level_1(const std::string &standard_sequence_file, int seed) :
Level{standard_sequence_file, true, seed} {
#if DEBUG_LEVEL > 0
    #include <iostream>
    std::cout << "Level_1 Constructor" << std::endl;
#endif

    if (seed != -1) srand(seed);
}

BlockShape Level_1::getNextBlock() {
    std::vector<BlockShape> shapeWeightList = {BlockShape::I, // 2 I
                                               BlockShape::I,
                                               BlockShape::J, // 2 J
                                               BlockShape::J,
                                               BlockShape::L, // 2 L
                                               BlockShape::L,
                                               BlockShape::O, // 2 O
                                               BlockShape::O,
                                               BlockShape::S, // 1 S
                                               BlockShape::Z, // 1 Z
                                               BlockShape::T, // 2 T
                                               BlockShape::T};

    int idx = std::rand() % shapeWeightList.size();
    return shapeWeightList[idx];
}

void Level_1::noRandom(const std::string &file_name) {} // no nothing

void Level_1::random() {} // no nothing

void Level_1::action_left(Tetris *tetris) {} // DO nothing by default

void Level_1::action_right(Tetris *tetris) {} // DO nothing by default

void Level_1::action_down(Tetris *tetris) {} // DO nothing by default

void Level_1::action_drop(Tetris *tetris, int row_cleared) {} // DO nothing by default

void Level_1::action_clockwise(Tetris *tetris) {} // DO nothing by default

void Level_1::action_counter_clockwise(Tetris *tetris) {} // DO nothing by default
