#ifndef __LEVEL_3_H__
#define __LEVEL_3_H__

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL 0
#endif

#include "level.h"

class Level_3 : public Level {
public:
    explicit Level_3(const std::string &standard_sequence_file, int seed);
    ~Level_3() {
#if DEBUG_LEVEL > 0
        #include <iostream>
    std::cout << "Level_3 Destructor" << std::endl;
#endif
    }
    BlockShape getNextBlock() override;
    void noRandom(const std::string &file_name) override;
    void random() override;
    void action_left(Tetris *tetris) override;
    void action_right(Tetris *tetris) override;
    void action_down(Tetris *tetris) override;
    void action_drop(Tetris *tetris, int row_cleared) override;
    void action_clockwise(Tetris *tetris) override;
    void action_counter_clockwise(Tetris *tetris) override;

};

#endif

#if 0

#ifndef __LEVEL_3_H__
#define __LEVEL_3_H__

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "level.h"

class Level_3 : public Level {
    int counter = 0;
public:
    Level_3(std::string file, bool rand);
    BlockShape getNextBlock() override;
};

#endif
#endif