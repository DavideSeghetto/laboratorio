#include <iostream>
#include <string>
#include <vector> 
#include <stdexcept>

using namespace std;

class Book {
    private:
    string isbn;
    string title;
    string author;
    string date;

    public:
    Book(string isbn_, string title_, string author_, string date_);
    
    string get_isbn();
    
    string get_title();
    
    string get_author();
    
    string get_date();
    
};

Book::Book(string isbn_, string title_, string author_, string date_) {
    isbn = isbn_;
    title = title_;
    author = author_;
    date = date_;
}
string Book::get_isbn() {
    return isbn;
}

string Book::get_title() {
    return title;
}

string Book::get_author() {
    return author;
}

string Book::get_date() {
    return date;
}

bool operator==(Book b1, Book b2) {
    if(b1.get_isbn().compare(b2.get_isbn()) == 0) return true;
    return false;
}

void checkout(vector<Book>& vettore, Book libro) {
    bool done = false;
    for(int i = 0; i < vettore.size(); i++) {
        if(vettore.at(i).get_title() == libro.get_title())  {
            vettore.erase(vettore.begin() + i);
            done = true;
        }
    }
    if(!done) throw invalid_argument ("Ther's no book with such title");
}

void checkin(vector<Book>& vettore, Book libro) {
    vettore.push_back(libro);
}

ostream& operator <<(ostream& os, Book libro) {
    os << "The title is: " << libro.get_title() << endl
       << "The author is: " << libro.get_author() << endl
       << "The ISBN is: " << libro.get_isbn() << endl;
    return os;
}

int main() {
    vector<Book> books;
    Book b1 = Book("97888", "Harry Potter", "Rowling", "1999");
    Book b2 = Book("82944", "The lord of the rings", "Tolkien", "1945");
    Book b3 = Book("12345", "The shadow of the wind", "Zafon", "2008");
    Book b4 = Book("97888", "The name of the rose", "Eco", "1980");
    checkin(books, b1);
    checkin(books, b2);
    checkin(books, b3);
    checkin(books, b4);
    for(int i = 0; i < books.size(); i++) cout << books.at(i);
    std :: cout <<"ciao";
}