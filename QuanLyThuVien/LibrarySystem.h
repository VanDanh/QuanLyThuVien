#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H




#undef remove
#undef remove_if
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Book.h"
#include "Member.h"
#include "LoanRecord.h"
using namespace std;

class LibrarySystem
{
private:
    vector<Book> books;
    vector<Member> members;
    vector<LoanRecord> loans;

   

public:
    bool isBookAvailable(string isbn);
    double calculateFine(Date dueDate, Date returnDate);
    // double calculateFine(string dueDate, string returnDate);
    Book *findBook(string isbn);
    Member *findMember(string memberId);
    // Constructor
    LibrarySystem();

    // Core methods
     void addBook(const Book book);

    void addMember(const Member member);
    bool loanBook(string isbn, string memberId, Date borrowDate, Date dueDate);
    // bool loanBook(string isbn, string memberId, string borrowDate, string dueDate);
    // bool returnBook(string isbn, string memberId, string returnDate);

    bool returnBook(string isbn, string memberId, Date returnDate);

    // Search methods
    vector<Book> searchBooks(string keyword) const;
    vector<Member> searchMembers(string keyword) const;

    void saveBooksToFile(const string &filename);

    void loadBooksFromFile(const string &filename);

    void saveLoansToFile(const string &filename);

    void loadLoansFromFile(const string &filename);

    void saveMembersToFile(const string &filename);

    void loadMembersFromFile(const string &filename);

    // Utility methods
    void loadData(); // Load data from file
    void saveData(); // Save data to file
};

#endif // LIBRARY_SYSTEM_H
