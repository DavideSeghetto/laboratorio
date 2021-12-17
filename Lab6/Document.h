#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class Document {

    private:

    std :: list<std :: string> text;

    public:

    Document();
    Document(Document& document);
    Document& operator =(Document& Document);
    void add_line(std :: string& line);
    void read_line(std :: istream& is);
    friend std :: ostream& operator << (std :: ostream& os, Document& document);
    int size();
    int char_count();
    int char_count_no_whitespace();
    void find_replace(const std :: string& s1, const std :: string& s2);
};

#endif
