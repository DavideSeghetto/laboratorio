#include <iostream>

using namespace std;

int array[10];

int* f() {
    //static int array [10]; //senza l'array fuori da f()
    int* puntatore = &array[1];

    puntatore[-1] = 4;
    
    for(int i = 0; i < 9;i++) {
        *puntatore = i;
        puntatore++;
    
    }

    puntatore = &array[0];
                            //{oppure solo return array perchè ritorna un puntatore al suo primo elemento
    return puntatore;
}

int main() {
    int* pointer = f();
    for(int i = 0; i < 10; i++) {
        cout << pointer[i] << endl;
    }    
}