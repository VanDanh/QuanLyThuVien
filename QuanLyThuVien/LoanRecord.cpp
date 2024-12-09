#include <string>
#include "LoanRecord.h"
using namespace std;

// Constructor
LoanRecord::LoanRecord(string bookIsbn, string memberId, Date borrowDate, Date dueDate){
    this->bookIsbn= bookIsbn;
    this->memberId= memberId;
    this->borrowDate= borrowDate;
    this->dueDate = dueDate;
}
  



// Getters
string LoanRecord::getBookIsbn() const { return bookIsbn; }
string LoanRecord::getMemberId() const { return memberId; }
string LoanRecord::getLoanId() const
{
    return loanId;
}
string LoanRecord::getBorrowDateStr() const
{
    return borrowDate.toString();
}

string LoanRecord::getDueDateStr() const
{
    return dueDate.toString();
}

string LoanRecord::getReturnDateStr() const
{
    return returnDate.toString();
}






Date LoanRecord::getBorrowDate() const
{
    return borrowDate;
}

Date LoanRecord::getDueDate() const
{
    return dueDate;
}

Date LoanRecord::getReturnDate() const
{
    return returnDate;
}

// Methods
void LoanRecord::returnBook(Date returnDate)
{
    int lateDays = borrowDate.daysBetween(returnDate);

        if (returnDate.isLaterThan(dueDate)) {
            this->fine = lateDays * 5000;  // Tính phạt 5000 đồng mỗi ngày trễ
        }
}

double LoanRecord::getFine() const { return fine; }
