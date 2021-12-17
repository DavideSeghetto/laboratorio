#include "Document.h"


Document :: Document() {
    text = {};
}

Document :: Document(Document& document) {
    text = document.text;
}

Document& Document::operator=(Document& document) {
    text = document.text;
    return *this;
}

void Document :: add_line(std :: string& line) {
    text.push_back(line);
}

void Document :: read_line(std :: istream& file) {
    std :: string stringa; 
    getline(file, stringa);
    text.push_back(stringa);
}

std :: ostream& operator << (std :: ostream& os, Document& document) {
    for(std :: string line : document.text) os << line << std :: endl;
    return os;
}

int Document :: size() {
    return text.size();
}

int Document :: char_count() {
    int total_size;
    for(std :: string line : text) {
        int size = line.length();
        total_size = total_size + size;
    }
    return total_size;
}

int Document :: char_count_no_whitespace() {
    int total_size;
    for(std :: string line : text) for(int i = 0; i < line.length(); i++) if(line[i] != ' ') total_size++;
    return total_size;
}

void Document :: find_replace(const std :: string& s1, const std :: string& s2) {  //E SBAGLIATO DC
    for(std :: string& line : text) {
        size_t pos = 0;
        while(pos = line.find(s1, pos) != std :: string :: npos) {
            line.replace(pos, s1.length(), s2);
            pos += s2.length();
        }
    }
}