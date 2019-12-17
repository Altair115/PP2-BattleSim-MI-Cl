//
// Created by kevin on 12/17/2019.
//

#ifndef PP2_BATTLE_SIMULATOR_NODE_H
#define PP2_BATTLE_SIMULATOR_NODE_H

#pragma once

#include <vector>
#include "tank.h"

namespace PP2{

    class node {
        int x,y;
        std::vector<Tank> tanks;
    };
}






#endif //PP2_BATTLE_SIMULATOR_NODE_H
