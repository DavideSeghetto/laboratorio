#include <iostream>
#include <stdexcept>

class vector {

    private:
    int size;
    double* ptr;
    
    public:
    vector(int size_);
    double get(int index);
    void set(int index, double elem);
    double safe_get(int index);
    void safe_set(int index, double elem);
    double& operator[] (int n);
    ~vector();

};

vector::~vector() {
    delete[] ptr;
}

vector::vector(int size_) {
    size = size_;
    ptr = new double[size];
}

double vector::get(int index) {
    return ptr[index];
}

double vector::safe_get(int index) {
    if(index > size || index < 0) throw std::invalid_argument ("Index out of bounds");
    return ptr[index];
}

void vector::set(int index, double elem) {
    ptr[index] = elem;
}

void vector::safe_set(int index, double elem) {
    if(index > size || index < 0)  throw std::invalid_argument ("Index out of bounds");
    ptr[index] = elem;
}

double& vector::operator[] (int n) {
    return ptr[n];
}

int main() {
    vector vettore = vector(10);
    for(int i = 0; i < 10; i++) vettore[i] = i;
    for(int i = 0; i < 10; i++) std :: cout << vettore[i] << std :: endl;
}
