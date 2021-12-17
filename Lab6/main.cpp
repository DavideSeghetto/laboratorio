#include "Document.h"

int main() {
    Document d1{};
    std :: string roba = "linea 1";
    d1.add_line(roba);
    std :: ifstream file("example.txt");
    if(file.is_open()) while (file.good()) d1.read_line(file);
    file.close();
    std :: cout << d1;
    std :: cout << "Il numero di caratteri e': " << d1.char_count() << std :: endl;
    std :: cout << "Il numero di caratteri senza spazi e': " << d1.char_count_no_whitespace() << std :: endl;
    std :: cout << std :: endl;
    
    Document d2(d1);
    std :: string linea("linea");
    std :: string riga("riga");
    d2.find_replace(linea, riga);
    std :: cout << d2;

    std :: string saluto("ciao come stai");
    std :: string find = "come";
    size_t pos = saluto.find(find);
    saluto.replace(pos, find.length(), "bo");
    std :: cout << saluto;
}