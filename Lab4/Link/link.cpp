#include <iostream>
#include <string>
#include <stdexcept>

class Link {
    
    public:

    std :: string value;
    Link* prev;
    Link* succ;
    
    Link(const std::string& v, Link* p = nullptr, Link* s = nullptr) {
        value = v;
        prev = p;
        succ = s;
    }

    void insert(Link* newelem) {
        if(this -> prev == nullptr) {
            this -> prev = newelem;
            newelem -> succ = this;
            return;
        }
        newelem -> prev = this -> prev;
        this -> prev -> succ = newelem;
        this -> prev = newelem;
        newelem -> succ = this;
    }

    void add(Link* newelem) {
        if(this -> succ == nullptr) {
            this -> succ = newelem;
            newelem -> prev = this;
            return; 
        }
        newelem -> succ = this -> succ;
        this -> succ -> prev = newelem;
        this -> succ = newelem;
        newelem -> prev = this;

    }

    void erase() {
        if(this -> succ == nullptr && this -> prev == nullptr) {
            delete this;
            return;
        }
        if(this -> prev == nullptr) {
            this -> succ -> prev = nullptr;
            delete this;
            return;
        }
        if(this -> succ == nullptr) {
            this -> prev -> succ = nullptr;
            delete this;
            return;
        }
        this -> prev -> succ = this -> succ;
        this -> succ -> prev = this -> prev;
        delete this;
    }

    const std :: string find(const std :: string elem) {
        if(this -> prev != nullptr) {
            throw std :: invalid_argument("Non stati puntando al primo elemento");
        }
        std :: string  parola = " ";
        if(parola == elem) return parola;
        Link* current = this;  //IN C++ THIS E' UN PUNTATORE ALL'OGGETTO CHE CHIAMA LA FUNZIONE
        do {
            parola = current -> value;
            if(parola == elem) return parola;
            current = current -> succ;
        
        } while(parola != elem && current != nullptr);
        throw std :: invalid_argument("Elemento non trovato");
    }

    /*Link* advance(Link* tofind) {
        if(this -> prev != nullptr) {
            throw std :: invalid_argument ("Non stai puntando al primo nodo");
        }
        if(this == tofind) return this;
        Link* ptr = this;
        do {
            ptr = ptr -> succ;
            if(ptr == tofind) return ptr;
        } while(ptr != nullptr);
        throw std :: invalid_argument("Nodo non trovato");
    }
    ULTIMO METODO SENZA SENSO MA LO LASCIO PERCHE' MI PIACE*/
};

int main() {
    Link* norse_gods = new Link("Freya"); //funziona anche se metto i due parametri nullptr
    norse_gods -> add(new Link("Thor"));
    norse_gods -> add(new Link("Loki"));
    //std :: cout << norse_gods -> succ -> succ -> value << std::endl;
    //std :: cout << norse_gods -> succ -> value << std::endl;
    //std :: cout << norse_gods -> value  << std::endl;
    Link* ptr = norse_gods; 
    norse_gods -> erase();
    //std :: cout << ptr -> value  << std::endl;
    std :: cout << ptr -> succ -> value << std::endl;
    std :: cout << ptr -> succ -> succ -> value << std::endl; //questo è cancellato
    ptr = ptr -> succ;
    std :: cout << ptr -> find("Loki"); //FUNZIONA
}