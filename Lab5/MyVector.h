#ifndef MYVECTOR_H
#define MYVECTOR_H

template <typename T>
class MyVector {

    private:

    int  elem;
    int actual_elem;
    T* ptr;

    public:

    MyVector();
    MyVector(int size);
    MyVector(MyVector<T>& vector);
    MyVector<T>& operator=(MyVector<T>& vector);
    int getElem();
    int getActualElem();
    T& operator[] (int n);
    T& at(int n);
    void push_back(T element);
    T pop_back();
    void reserve(int newdim);
    void resize(int newsize);
    ~MyVector();
};

#include "MyVector.hpp"

#endif