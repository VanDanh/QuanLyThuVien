#include <string>
#include "Book.h"
using namespace std;

// Constructor
Book::Book(string isbn, string title, string author, string publisher, int year, int quantity)
    : isbn(isbn), title(title), author(author), publisher(publisher), year(year), quantity(quantity), available(quantity) {}

// Getters
string Book::getISBN() const { return isbn; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getPublisher() const
{
    return publisher;
}
int Book::getYear() const
{
    return year;
}
int Book::getQuantity() const
{
    return quantity;
}
int Book::getAvailable() const { return available; }

void Book::setQuantity(int quantity)
{
}

void Book::setAvailable(int available)
{
}

// Setters
void Book::updateQuantity(int newQuantity)
{
    quantity = newQuantity;
    available = newQuantity;
}

// Helper methods
bool Book::isAvailable() const { return available > 0; }
void Book::borrowBook()
{
    if (available > 0)
        available--;
}
void Book::returnBook()
{
    if (available < quantity)
        available++;
}
