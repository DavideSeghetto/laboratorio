#include <iostream>

using namespace std;

void print_array_length(double array[]) {  //vengono fuori tramaci perchè sizeof ritorna la dimensione di double*, 4 (byte) dato che è un int
    cout << "The size of array is: " << sizeof(array) << endl;  //quindi si perde la "conoscenza" della lunghezza dell'array
}

int main () {
    const int l = 10;
    double array[l];
    for(int i = 0; i < l; i++) array[i] = i; 
    cout << "The size of array is: " << sizeof(array)/sizeof(array[0]) << endl;
    print_array_length(array);
}