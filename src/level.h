#ifndef __LEVEL_H__
#define __LEVEL_H__

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL 0
#endif

#include "sequence.h"
#include "blockShape.h"
#include <vector>
#include <stdexcept>

class Tetris;

class Level {
protected:
    Sequence seq;
    bool rand;
    int seed;

public:
    explicit Level(std::string standard_sequence_file, bool rand, int seed);
    virtual ~Level();

    virtual BlockShape getNextBlock() = 0;

    virtual void noRandom(const std::string &file_name) = 0;

    virtual void random() = 0;

    virtual void action_left(Tetris *tetris) = 0;
    virtual void action_right(Tetris *tetris) = 0;
    virtual void action_down(Tetris *tetris) = 0;
    virtual void action_drop(Tetris *tetris, int row_cleared) = 0;
    virtual void action_clockwise(Tetris *tetris) = 0;
    virtual void action_counter_clockwise(Tetris *tetris) = 0;
};

#endif