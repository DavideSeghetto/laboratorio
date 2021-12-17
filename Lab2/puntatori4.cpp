#include <iostream>

using namespace std;

void print_array(void* ptr, int length) {
    int* ptr2 = (int*) ptr;
    for(int i = 0; i < 10; i++) cout << ptr2[i] << endl;
}

int main() {
    int my_array [10];
    for(int i = 0; i < 10; i++) my_array[i] = i;
    void* ptr = &my_array[0];
    print_array(ptr, 10);
}