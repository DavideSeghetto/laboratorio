#include <string>
#include <iostream>

using namespace std;

int main() {
    char parola [10] = "Ciao";
    for(int i = 0; i < 4; i++) cout << parola[i];
    cout << endl << parola[10];
}