#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "LoanRecord.h"
using namespace std;

class Member
{
private:
    string memberId;
    string name;
    string contact;
    string registerDate;
    vector<LoanRecord> loanHistory;
    vector<string> loanedBooks; // danh sach cac cuon sach da muon

public:
    // Constructor
    Member(string memberId, string name, string contact, string registerDate);
    Member();
    // Getters
    string getMemberId() const;
    string getName() const;
    int getLoanedBookCount() const;
    void borrowBook(string isbn);
    void returnBook(string isbn);
    bool canBorrow() const;
    string getContact() const;
    string getRegisterDate() const;

    // Setters
    void setName(string name);
    void setContact(string contact);

    // Other methods
    void addLoanRecord(LoanRecord record);
    int getLoanCount() const; // Số sách hiện đang mượn
    void displayInfo() const;
};

#endif // MEMBER_H
