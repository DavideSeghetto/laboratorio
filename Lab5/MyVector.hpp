#include <algorithm>
#include <stdexcept>
#include "MyVector.h"

#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

template <typename T>
MyVector<T> :: MyVector() {
    MyVector(100);
}

template <typename T>
MyVector<T> :: MyVector(int size) {
    ptr = new T[size];
    elem = size;
    actual_elem = 0;
}

template <typename T>
MyVector<T> :: MyVector(MyVector<T>& vector) {
    ptr = new T[vector.getElem()];
    std :: copy(vector.ptr, vector.ptr + vector.actual_elem, ptr);
    actual_elem = vector.getActualElem();
    elem = vector.getElem();
}

template<typename T>
MyVector<T>& MyVector<T> :: operator=(MyVector<T>& vector) {
    //devo ritornare *this con i membri di vector
    /*T* new_ptr = new T[vector.elem()];
    std :: copy(vector.ptr, vector.ptr + vector.getActualElem(), new_ptr);
    delete[] ptr;
    ptr = new_ptr;
    elem = vector.getElem();
    actual_elem = vector.getActualElem();
    return *this;*/
    delete[] ptr;
    ptr = new T[vector.getElem()];
    std :: copy(vector.ptr, vector.ptr + vector.getActualElem(), ptr);
    elem = vector.getElem();
    actual_elem = vector.getActualElem();
    return *this;
}

template<typename T>
int MyVector<T> :: getElem() {
    return elem;
}

template<typename T>
int MyVector<T> :: getActualElem() {
    return actual_elem;
}

template <typename T>
T& MyVector<T> :: operator [] (int n) {
    return ptr[n];
}

template <typename T>
T& MyVector<T> :: at(int n) {
    if(n < 0 || n > this -> actual_elem) throw std :: invalid_argument ("POLLO");
    return ptr[n];
}

template <typename T>
void MyVector<T> :: resize(int newElem) {
    T* newPtr = new T[newElem];
    //memcpy(newPtr, ptr, actual_elem);   CON QUESTO LA COPIA NON E' CORRETTA
    for(int i = 0; i < actual_elem; i++) newPtr[i] = ptr[i];
    delete[]  ptr;
    ptr = newPtr;
    elem = newElem;
}

template<typename T>
void MyVector<T> :: reserve(int newdim) {
    if(newdim < elem) return;
    int newElem = elem;
    while(newdim > newElem) newElem *= 2;
    resize(newElem);
}

template <typename T>
void MyVector<T> :: push_back(T element) {
    if(elem == actual_elem) resize(elem * 2);
    ptr[actual_elem++] = element;
}

template <typename T>
T MyVector<T> :: pop_back() {
    T ris = ptr[--actual_elem];
    return ris;
}

template<typename T>
MyVector<T> :: ~MyVector() {
    delete[] ptr;
}

#endif