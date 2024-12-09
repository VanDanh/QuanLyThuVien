// #include <string>
// #include <vector>
// #include "Member.h"
// // #include<algorithm>
// using namespace std;

// // Constructor
// Member::Member(string memberId, string name, string contact, string registerDate)
//     : memberId(memberId), name(name), contact(contact), registerDate(registerDate) {}

// // Getters
// string Member::getMemberId() const { return memberId; }
// string Member::getName() const { return name; }
// int Member::getLoanedBookCount() const { return loanedBooks.size(); }

// // Methods
// void Member::borrowBook(string isbn) { loanedBooks.push_back(isbn); }
// void Member::returnBook(std::string &isbn)
// {
//     // loanedBooks.erase(std::remove(loanedBooks.begin(), loanedBooks.end(), isbn), loanedBooks.end());
//     loanedBooks.erase(std::remove(loanedBooks.begin(), loanedBooks.end(), isbn), loanedBooks.end());
// }

// bool Member::canBorrow() const { return loanedBooks.size() < 3; } // Không được mượn quá 3 sách









#undef remove
#undef remove_if
#include <string>
#include <vector>
#include "Member.h"
#include<algorithm> // Uncomment this line to use std::remove

using namespace std;

// Constructor
Member::Member(string memberId, string name, string contact, string registerDate)
    : memberId(memberId), name(name), contact(contact), registerDate(registerDate) {}

Member::Member()
{
}

// Getters
string Member::getMemberId() const { return memberId; }
string Member::getName() const { return name; }
int Member::getLoanedBookCount() const { return loanedBooks.size(); }

string Member::getContact() const
{
    return this->contact;
}

string Member::getRegisterDate() const
{
    return this->registerDate;
}

void Member::setContact(string contact)
{
    this->contact= contact;
}

// Methods
void Member::borrowBook(string isbn) { loanedBooks.push_back(isbn); }

// Sửa hàm returnBook
void Member::returnBook(string isbn) {
    for (auto it = loanedBooks.begin(); it != loanedBooks.end(); ++it) {
        if (*it == isbn) {
            loanedBooks.erase(it);  // Xóa phần tử nếu tìm thấy
            break;  // Dừng lại sau khi xóa
        }
    }
}

bool Member::canBorrow() const { return loanedBooks.size() < 3; } // Không được mượn quá 3 sách
