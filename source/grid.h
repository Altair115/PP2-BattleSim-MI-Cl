//
// Created by kevin on 12/17/2019.
//

#ifndef PP2_BATTLE_SIMULATOR_GRID_H
#define PP2_BATTLE_SIMULATOR_GRID_H

#pragma once

#include "tank.h"

namespace PP2 {
    class grid {
    public:
        grid();
        static const int numberOfCells = 10;
        static const int sizeOfCell = 20;
    private:
        Tank *cells_[numberOfCells][numberOfCells];
    };
}


#endif //PP2_BATTLE_SIMULATOR_GRID_H
