// This is interface of Tetris class
#ifndef __TETRIS_H__
#define __TETRIS_H__

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL 0
#endif

#include "tetrisAbstract.h"
#include "sequence.h"
#include "grid.h"
#include "blockDispenser_I.h"
#include "blockDispenser_J.h"
#include "blockDispenser_L.h"
#include "blockDispenser_O.h"
#include "blockDispenser_S.h"
#include "blockDispenser_Z.h"
#include "blockDispenser_T.h"
#include "blockDispenser_tiny.h"
#include "blockShape.h"
#include "level_0.h"
#include "level_1.h"
#include "level_2.h"
#include "level_3.h"
#include "level_4.h"
#include <vector>
#include <map>
#include <iomanip>

class Tetris : public TetrisAbstract {
    std::string standard_sequence;
    int current_level;
    int next_level;
    const int reserved;
    Grid *grid;
    std::vector<Block*> blocks;
    Block *current_block;
    Block *next_block;
    std::map<BlockShape, BlockDispenser*> dispenser;
    std::vector<Level*> levels;
    Level *levelObj;
    int maximum_level;
    int score;
    bool game_over;
    int seed;
    bool blind = false;

    void gameOver();
    void updateBlock();
public:

    explicit Tetris(std::string standard_sequence, int seed,int initial_level = 0, int width = 11, int height = 18, int reserved = 3);
    virtual ~Tetris();

    Block *get_current_block() const noexcept;

    void placeTiny();

    Grid *getGrid() override;

    int getScore() override;

    int getNextLevel() override;

    void setBlind(bool _blind) override;

    bool isBlind() override;

    bool right(int step) override;

    bool left(int step) override;

    bool down(int step) override;

    bool drop(int step) override;

    void clockwise(int step) override;

    void counter_clockwise(int step) override;

    void level_up(int step) override;

    void level_down(int step) override;

    void random() override;

    void noRandom(const std::string &sequence_file) override;

    void changeCurrentBlock(BlockShape type) override;

    bool isHeavy() override;

    std::vector<std::pair<int,int>> getNextShape() override;

    Block *getNextBlock() override;

    bool isOver() override;
};

#endif
