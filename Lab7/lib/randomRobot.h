#include "robot.h"

class RandomRobot : public Robot {
    
    public:
    RandomRobot(const Maze& maze);
    void move(const Maze& maze) override;
};