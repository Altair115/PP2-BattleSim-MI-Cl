//
// Created by kevin on 12/17/2019.
//

#include "grid.h"

#include <cmath>

PP2::grid::grid() {
    //clear the grid
    for (int x = 0; x < numberOfCells; x++) {
        for (int y = 0; y < numberOfCells; ++y) {
            cells_[x][y] = NULL;
        }
    }
}

void PP2::grid::add(PP2::Tank* tank) {
    int cellX =(int)(tank->position.x / grid::sizeOfCell);
    int cellY =(int)(tank->position.y / grid::sizeOfCell);
    if (cellX < 0)
    {
        cellX = 0;
    }
    if (cellY < 0)
    {
        cellY = 0;
    }
    tank->prev_ = NULL;
    tank->next_ = cells_[cellX][cellY];
    cells_[cellX][cellY] = tank;

    if(tank->next_ !=NULL){
        tank->next_->prev_ = tank;
    }

}

void PP2::grid::handelCell(int x , int y) {
    Tank* tank = cells_[x][y];
    while(tank != NULL){
        handelTank(tank,tank->next_);

        if (x > 0 && y > 0) handelTank(tank, cells_[x - 1][y - 1]);
        if (x > 0) handelTank(tank, cells_[x - 1][y]);
        if (y > 0) handelTank(tank, cells_[x][y - 1]);
        if (x > 0 && y < numberOfCells - 1)
        {
            handelTank(tank, cells_[x - 1][y + 1]);
        }

        tank = tank->next_;
    }
}

void PP2::grid::move(PP2::Tank *tank, vec2 targetPosistion) {
    // See which cell it was in.
    int oldCellX = (int)(tank->position.x / grid::sizeOfCell);
    int oldCellY = (int)(tank->position.y / grid::sizeOfCell);
    if(oldCellX < 0){
        oldCellX = 0;
    }
    if(oldCellY < 0){
        oldCellY = 0;
    }
    int cellX = (int)(round(targetPosistion.x) / grid::sizeOfCell);
    int cellY = (int)(round(targetPosistion.y) / grid::sizeOfCell);
    if (cellX < 0)
    {
        cellX = 0;
    }
    if (cellY < 0)
    {
        cellY = 0;
    }
    tank->position = targetPosistion;
    // If it didn't change cells, we're done.
    if (oldCellX == cellX && oldCellY == cellY) return;

    // Unlink it from the list of its old cell.
    if (tank->prev_ != NULL)
    {
        tank->prev_->next_ = tank->next_;
    }

    if (tank->next_ != NULL)
    {
        tank->next_->prev_ = tank->prev_;
    }

    // If it's the head of a list, remove it.
    if (cells_[oldCellX][oldCellY] == tank)
    {
        cells_[oldCellX][oldCellY] = tank->next_;
    }

    // Add it back to the grid at its new cell.
    add(tank);
}



void PP2::grid::handelTank(PP2::Tank *tank, PP2::Tank *other) {
    while (other != NULL)
    {
        if(colliding(tank,other)){
            handelpush();
        }
        other = other->next_;
    }
}

bool PP2::grid::colliding(PP2::Tank *tank, PP2::Tank *other) {
    vec2 dir = tank->Get_Position() - other->Get_Position();
    float dirSquaredLen = dir.sqrLength();

    float colSquaredLen = (tank->Get_collision_radius() * tank->Get_collision_radius()) +
                          (other->Get_collision_radius() * other->Get_collision_radius());
    if (dirSquaredLen < colSquaredLen) {
        tank->Push(dir.normalized(), 1.f);
        return true;
    }
    return false;
}

void PP2::grid::handelpush() {
    for (int x = 0; x < numberOfCells; x++)
    {
        for (int y = 0; y < numberOfCells; y++)
        {
            handelCell(x, y);
        }
    }
}
