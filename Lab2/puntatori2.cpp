#include <iostream>

using namespace std;

void f() {
    int array [10];
    int* puntatore = &array[1];

    puntatore[-1] = 4;
    
    for(int i = 0; i < 10;i++) {
        *puntatore = i;
        puntatore++;
    }
    puntatore = &array[0];
    
    for(int i = 0; i < 10; i++) {
        cout << puntatore[i] << endl;
    }
}

int main() {
    f();
}