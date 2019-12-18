//
// Created by kevin on 12/17/2019.
//

#include "grid.h"

PP2::grid::grid() {
    //clear the grid
    for (int x = 0; x < numberOfCells; x++) {
        for (int y = 0; y < numberOfCells; ++y) {
            cells_[x][y] = NULL;
        }
    }
}
