#include "../lib/robot.h"

Position Robot :: getPosition() const {
    return position;
}

void Robot :: setPosition(int pos) {
    position.x = pos % 9;
    position.y = pos / 9;
}

int Robot :: getLogicalPosition() const {
    return position.x + position.y * 9;
}