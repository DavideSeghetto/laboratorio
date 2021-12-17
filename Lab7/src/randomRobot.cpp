#include "../lib/randomRobot.h"
#include <cstdlib>
#include <ctime>

RandomRobot :: RandomRobot(const Maze& maze) {
    position.x = maze.getS_pos() % 9;
    position.y = maze.getS_pos() / 9;
}

void RandomRobot :: move(const Maze& maze) {
    char* list_maze = maze.getMaze();

    int movable[8];
    movable[0] = getLogicalPosition() - 10;
    movable[1] = getLogicalPosition() - 9;
    movable[2] = getLogicalPosition() - 8;
    movable[3] = getLogicalPosition() - 1;
    movable[4] = getLogicalPosition() + 1;
    movable[5] = getLogicalPosition() + 8;
    movable[6] = getLogicalPosition() + 9;
    movable[7] = getLogicalPosition() + 10;

    srand(time(NULL));
    int random_number;
    do {
        random_number = rand() % 8;
    } while(list_maze[movable[random_number]] == '*');
    setPosition(movable[random_number]);
}