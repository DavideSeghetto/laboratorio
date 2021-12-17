#include <iostream>
#include <string>   

bool is_palindrome1(const std :: string& S) {
    for (int i = 0; i < S.length() / 2; i++) {

        if (S.at(i) != S[S.length() - i - 1]) return false;
    }
    return true;    
}

bool is_palindrome2(const char s[], int length) {
    for(int i = 0; i < length / 2; i++) {
    
        if(s[i] != s[length - 1 -i]) return false;
    }
    return true; 
}

bool is_palindrome3(const char* first, const char* last) {
    const char* ptr = first;
    for(int i = 0; ptr != last; i++, ptr++) {
        if(first[i] != last[-i]) return false;
    }
    return true;
}

int main() {
    std :: string s1 = "abcdcba";

    const char* first = &(s1.at(0));
    const char* last = &(s1.at(s1.length() - 1));

    std :: string s4 = "abcd";

    const char* first_ = &(s4.at(0));
    const char* last_ = &(s4.at(s4.length() - 1));
    
    char s2 [] = {'a', 'b', 'c', 'd', 'c', 'b', 'a'};
    const char* ptr = "abcdcba"; // funziona anche con ptr
    
    std :: cout << "is_palindrome1: " << is_palindrome1(s1) << std :: endl;
    std :: cout << "is_palindrome2: " << is_palindrome2(s2, 7) << std :: endl;
    std :: cout << "is_palindrome3: " << is_palindrome3(first_, last) << std :: endl;
}