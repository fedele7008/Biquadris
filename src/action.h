#ifndef __ACTION_H__
#define __ACTION_H__

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL 0
#endif

enum class Action {
    updateCurrent,
    updateNext,
    reset,
    blind,
    score
};

#endif
