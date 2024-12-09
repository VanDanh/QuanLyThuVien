#ifndef BOOK_H
#define BOOK_H




#undef remove
#undef remove_if
#include <string>
using namespace std;

class Book
{
private:
    string isbn;
    string title;
    string author;
    string publisher;
    int year;
    int quantity;
    int available; // Số lượng sách còn lại để mượn

public:
    // Constructor
    Book(string isbn, string title, string author, string publisher, int year, int quantity);

    // Getters
    string getISBN() const;
    string getTitle() const;
    string getAuthor() const;
    string getPublisher() const;
    int getYear() const;
    int getQuantity() const;
    int getAvailable() const;

    // Setters
    void setQuantity(int quantity);
    void setAvailable(int available);

    void updateQuantity(int newQuantity);

    bool isAvailable() const;

    void borrowBook();

    void returnBook();

    // Other methods
    void displayInfo() const;
};

#endif // BOOK_H
