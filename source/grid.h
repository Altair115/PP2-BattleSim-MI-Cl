//
// Created by kevin on 12/17/2019.
//

#ifndef PP2_BATTLE_SIMULATOR_GRID_H
#define PP2_BATTLE_SIMULATOR_GRID_H

#pragma once

#include "tank.h"
#include <vector>

namespace PP2 {
    class grid {
    public:

        grid();
        void handelTank(Tank* tank, Tank* other);
        void add(Tank* tank);
        void handelCell(int x, int y);
        void move(Tank* tank , vec2 targetPosition);

        bool colliding(Tank* tank, Tank* other);
        void handelpush();
        static const int numberOfCells = 1000;
        static const int sizeOfCell = 20;
    private:
        Tank* cells_[numberOfCells][numberOfCells];
    };
}


#endif //PP2_BATTLE_SIMULATOR_GRID_H
