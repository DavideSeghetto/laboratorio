#include "../lib/maze.h"
#include "../lib/randomRobot.h"
#include <iostream>

int main() {
    std :: ifstream file("text.txt");
    Maze maze(file);
    RandomRobot random_robot(maze);
    std :: cout << random_robot.getLogicalPosition() << std :: endl;
    std :: cout << random_robot.getPosition().x << " " << random_robot.getPosition().y << std :: endl;
    while(maze.getMaze()[random_robot.getLogicalPosition()] != 'E') {
        random_robot.move(maze);
        std :: cout << random_robot.getPosition().x << " " << random_robot.getPosition().y << std :: endl;
    }
    std :: cout << "Ce l'ho fatta capo";
}