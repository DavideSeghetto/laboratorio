#ifndef ROBOT_H
#define ROBOT_H

#include "maze.h"
#include "position.h"

class Robot {

    public:
    Position getPosition() const;
    int getLogicalPosition() const;
    
    protected:
    Position position;
    virtual void move(const Maze& maze) = 0;
    void setPosition(int pos);
};

#endif