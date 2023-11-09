#include "level_3.h"
#include "blockShape.h"
#include "tetris.h"
#include <vector>
#include <cstdlib>

Level_3::Level_3(const std::string &standard_sequence_file, int seed) :
        Level{standard_sequence_file, true, seed} {
#if DEBUG_LEVEL > 0
    #include <iostream>
    std::cout << "Level_3 Constructor" << std::endl;

    if (seed != -1) srand(seed);
#endif
}

BlockShape Level_3::getNextBlock() {
    if (rand) {
        std::vector<BlockShape> shapeWeightList = {BlockShape::I, // 1 I
                                                   BlockShape::J, // 1 J
                                                   BlockShape::L, // 1 L
                                                   BlockShape::O, // 1 O
                                                   BlockShape::S, // 2 S
                                                   BlockShape::S,
                                                   BlockShape::Z, // 2 Z
                                                   BlockShape::Z,
                                                   BlockShape::T}; // 1 T

        int idx = std::rand() % shapeWeightList.size();
        return shapeWeightList[idx];
    } else {
        return seq.get_next_block();
    }
}

void Level_3::noRandom(const std::string &file_name) {
    try {
        seq.set_sequence(file_name);
    } catch (EmptySequenceException &e) {
        std::cerr << "given sequence is invalid" << std::endl;
        return;
    }
    rand = false;
}

void Level_3::random() {
    rand = true;
}

void Level_3::action_left(Tetris *tetris) {
    try {
        tetris->get_current_block()->down(1);
    } catch (InvalidActionException &err) {
        std::cerr << err.what() << std::endl;
    }
}

void Level_3::action_right(Tetris *tetris) {
    try {
        tetris->get_current_block()->down(1);
    } catch (InvalidActionException &err) {
        std::cerr << err.what() << std::endl;
    }
}

void Level_3::action_down(Tetris *tetris) {
    try {
        tetris->get_current_block()->down(1);
    } catch (InvalidActionException &err) {
        std::cerr << err.what() << std::endl;
    }
}

void Level_3::action_drop(Tetris *tetris, int row_cleared) {}

void Level_3::action_clockwise(Tetris *tetris) {
    try {
        tetris->get_current_block()->down(1);
    } catch (InvalidActionException &err) {
        std::cerr << err.what() << std::endl;
    }
}

void Level_3::action_counter_clockwise(Tetris *tetris) {
    try {
        tetris->get_current_block()->down(1);
    } catch (InvalidActionException &err) {
        std::cerr << err.what() << std::endl;
    }
}
