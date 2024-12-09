#ifndef LOAN_RECORD_H
#define LOAN_RECORD_H

#undef remove
#undef remove_if
#include <string>
#include "Date.h"
using namespace std;

class LoanRecord
{
private:
    string loanId;
    string bookIsbn;
    string memberId;
    Date borrowDate; // Dạng yyyy-mm-dd
    Date dueDate;    // Dạng yyyy-mm-dd
    Date returnDate; // Dạng yyyy-mm-dd (nếu sách chưa trả thì giá trị là rỗng)
    double fine;       // Tiền phạt (nếu có)

public:
    // Constructor
    LoanRecord(string bookIsbn, string memberId, Date borrowDate, Date dueDate);
    // LoanRecord(string loanId, string bookIsbn, string memberId, string borrowDate, string dueDate);

    // Getters
    string getLoanId() const;
    string getBorrowDateStr() const;
    string getDueDateStr() const;
    string getReturnDateStr() const;
    string getBookIsbn() const;
    string getMemberId() const;
    Date getBorrowDate() const;
    Date getDueDate() const;
    Date getReturnDate() const;
    void returnBook(Date returnDate);
    double getFine() const;

  
};

#endif 
