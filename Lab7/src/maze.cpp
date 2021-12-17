#include "../lib/maze.h"
#include <iostream>

Maze :: Maze(std :: ifstream& file) {
    ptr = new char[SIZE];
    int i = 0;
    while(file.good()) {
        file.get(ptr[i]);
        if(ptr[i] != '\n') i++;
    }
    for(int i = 0; i < SIZE; i++) {
        std :: cout << ptr[i];
        if((i + 1) % 9 == 0) std :: cout << std :: endl;
    }
}

char* Maze :: getMaze() const {
    return ptr;
}

int Maze :: getS_pos() const {
    for(int i = 0; i < SIZE; i++) if(ptr[i] == 'S') return i;
    return -1;
}