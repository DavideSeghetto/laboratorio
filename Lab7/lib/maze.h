#ifndef MAZE_H
#define MAZE_H

#include <fstream>
#include <iostream>

class Maze {
    
    private:
    char* ptr;
    static constexpr int SIZE = 81;

    public:
    Maze(std :: ifstream& file);
    int getS_pos() const;
    char* getMaze() const;
    ~Maze();
};

#endif