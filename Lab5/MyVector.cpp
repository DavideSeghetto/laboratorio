#include <stdexcept>
#include "MyVector.h"
#include <iostream>
int main() {
    /*int* ptr = new int;
    *ptr = 3;
    MyVector<int>* a = new MyVector<int>(10);
    //MyVector<int> a{10};
    (*a).push_back(2); // o con ->
    (*a).push_back(1); // o con ->
    for(int i = 0; i < 2; i++) std :: cout << (*a)[i] << std :: endl;*/

    MyVector<int> vector(1);
	std :: cout << "----- VECTOR 1 -----" << std :: endl;
    std::cout <<  "dimensione: " << vector.getElem() << std::endl;
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	for(int i = 0; i < vector.getActualElem(); i++) std::cout << vector[i] << std::endl;
    std :: cout << std :: endl;
	std::cout << "Eliminato l'elemento: " << vector.pop_back()  << std::endl;
	std::cout << "dimensione: " << vector.getElem() << std::endl;
	std::cout << "dimensione effettiva: " << vector.getActualElem() << std::endl;
    /*std :: cout << "Riservo almeno 17 celle" << std :: endl;
    vector.reserve(17);
    std :: cout << "dimensione: " << vector.getElem() << std :: endl;
    std :: cout << "dimensione effettiva: " << vector.getActualElem() << std :: endl;*/
    std :: cout << std :: endl;

    MyVector<int> vector2(vector); //COSTRUTTORE DI COPIA
    std :: cout << "----- VECTOR 2 -----" << std :: endl;
    for(int i = 0; i < vector2.getActualElem(); i++) std::cout << vector2[i] << std::endl;
    std::cout << "dimensione: " << vector2.getElem() << std::endl;
	std::cout << "dimensione effettiva: " << vector2.getActualElem() << std::endl;
    std :: cout << std :: endl;
    vector2.push_back(3);
    vector2.push_back(4);
    for(int i = 0; i < vector2.getActualElem(); i++) std :: cout << vector2[i] << std :: endl;
    std :: cout << "dimensione: " << vector2.getElem() << std :: endl;
    std :: cout << "dimensione effettiva: " << vector2.getActualElem() << std :: endl;
    std :: cout << std :: endl;
    std :: cout << "Eliminato l'elemento: " << vector2.pop_back() << std :: endl;
    std :: cout << std :: endl;
    for(int i = 0; i < vector2.getActualElem(); i++) std :: cout << vector2[i] << std :: endl;
    std :: cout << "dimensione: " << vector2.getElem() << std :: endl;
    std :: cout << "dimensione effettiva: " << vector2.getActualElem() << std :: endl;
    std :: cout << std :: endl;

    MyVector<int> vector3 = vector2; //ASSEGNAMENTO DI COPIA
    std :: cout << "----- VECTOR 3 -----" << std :: endl;
    for(int i = 0; i < vector3.getActualElem(); i++) std :: cout << vector3[i] << std :: endl;
    std :: cout << "dimensione: " << vector3.getElem() << std :: endl;
    std :: cout << "dimensione effettiva: " << vector3.getActualElem() << std :: endl;
    std :: cout << std :: endl;
    vector3.push_back(4);
    vector3.push_back(5);
    for(int i = 0; i < vector3.getActualElem(); i++) std :: cout << vector3[i] << std :: endl;
    std :: cout << "dimensione: " << vector3.getElem() << std :: endl;
    std :: cout << "dimensione effettiva: " << vector3.getActualElem() << std :: endl;
    std :: cout << std :: endl;
    std :: cout << "Eliminato l'elemento: " << vector3.pop_back() << std :: endl;
    std :: cout << std :: endl;
    for(int i = 0; i < vector3.getActualElem(); i++) std :: cout << vector3[i] << std :: endl;
    std :: cout << "dimensione: " << vector3.getElem() << std :: endl;
    std :: cout << "dimensione effettiva: " << vector3.getActualElem() << std :: endl;

}