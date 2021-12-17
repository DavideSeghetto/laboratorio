#include <iostream>

using namespace std;

void print_reference(int& a, double& b) {
    cout << a << " and " << b;
}  

void print_pointer(int* a, double* b) {
    cout << a[0] << " and " << b[0];
}

int main() {
    int a = 1;
    double b = 2.0;
    int* a_ = &a;
    double* b_ = &b;
    print_reference(a, b);
    cout << endl;
    print_pointer(a_, b_);
}