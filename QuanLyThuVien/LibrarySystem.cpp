#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "LibrarySystem.h"
using namespace std;
LibrarySystem::LibrarySystem()
{
}
// Helper method: Tìm sách theo ISBN
Book *LibrarySystem::findBook(string isbn)
{
    for (auto &book : books)
    {
        if (book.getISBN() == isbn)
            return &book;
    }
    return nullptr;
}

// Helper method: Tìm thành viên theo ID
Member *LibrarySystem::findMember(string memberId)
{
    for (auto &member : members)
    {
        if (member.getMemberId() == memberId)
            return &member;
    }
    return nullptr;
}

// Helper method: Tính tiền phạt
double LibrarySystem::calculateFine(Date dueDate, Date returnDate)
{
   
    int lateDays = dueDate.daysBetween(returnDate);
    return lateDays > 0 ? lateDays * 5000 : 0;
}



// Thêm sách
void LibrarySystem::addBook(const Book book)
{
    books.push_back(book);
}

// Thêm thành viên
void LibrarySystem::addMember(const Member member)
{
    members.push_back(member);
}

// Mượn sách
bool LibrarySystem::loanBook(string isbn, string memberId, Date borrowDate, Date dueDate)
{
    Book *book = findBook(isbn);
    Member *member = findMember(memberId);
    if (!book || !member || !book->isAvailable() || !member->canBorrow())
        return false;

    book->borrowBook();
    member->borrowBook(isbn);
    loans.emplace_back(isbn, memberId, borrowDate, dueDate);
    return true;
}

// Trả sách
bool LibrarySystem::returnBook(string isbn, string memberId, Date returnDate)
{
    Book *book = findBook(isbn);
    Member *member = findMember(memberId);
    if (!book || !member)
        return false;

    // Tìm loan record
    auto it = find_if(loans.begin(), loans.end(), [&](const LoanRecord &loan)
                      { return loan.getBookIsbn() == isbn && loan.getMemberId() == memberId; });
    if (it == loans.end()){
        cout<<"khach hang ko muon cuon sach co ma "<< isbn<<endl;
        return false;
    }

    // Cập nhật sách và thành viên
    Date dueDate = it->getDueDate();
    double fine = calculateFine(dueDate, returnDate);
    if(fine < 1){
        cout<<"khack hang da muon qua "<< dueDate.daysBetween(returnDate)<<endl;
        cout<<"so tien phat la: "<< fine <<" VND"<<endl;
        cout<<"Khach hang da thanh toan hay chua ?"<<endl;
        cout<<"1. Da thanh toan"<<endl;
        cout<<"2. thanh toan"<<endl;
        int choice; cin>>choice;
        if(choice == 1){
             it->returnBook(returnDate);
            book->returnBook();
            member->returnBook(isbn);
            return true;
        }
    }
   
    return false;
}

vector<Book> LibrarySystem::searchBooks(string keyword) const
{
    vector<Book> foundBooks;  // Mảng chứa các sách tìm được
    for (const auto &book : books)  // Duyệt qua tất cả các sách trong danh sách
    {
        if (book.getTitle().find(keyword) != string::npos || book.getISBN().find(keyword) != string::npos) 
        {
            foundBooks.push_back(book);  // Thêm sách vào kết quả nếu tên sách hoặc ISBN chứa từ khóa
        }
    }
    return foundBooks; 
}

vector<Member> LibrarySystem::searchMembers(string keyword) const
{
    vector<Member> foundMenmber;  // Mảng chứa các sách tìm được
    for (const auto &member : members)  // Duyệt qua tất cả các sách trong danh sách
    {
        if (member.getName().find(keyword) != string::npos || member.getContact().find(keyword) != string::npos|| member.getMemberId().find(keyword) != string::npos) 
        {
            foundMenmber.push_back(member);  // Thêm sách vào kết quả nếu tên sách hoặc ISBN chứa từ khóa
        }
    }
    return foundMenmber; 
}


void LibrarySystem::saveBooksToFile(const string &filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Lỗi khi mở file để lưu danh sách sách." << endl;
        return;
    }

    for (const auto &book : books) {
        outFile << book.getISBN() << ","
                << book.getTitle() << ","
                << book.getAuthor() << ","
                << book.getPublisher() << ","
                << book.getYear() << ","
                << book.getQuantity() << ","
                << book.getAvailable() << endl;
    }

    outFile.close();
    cout << "Đã lưu danh sách sách vào file." << endl;
}


void LibrarySystem::loadBooksFromFile(const string &filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Lỗi khi mở file để đọc danh sách sách." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string isbn, title, author, publisher;
        int year, quantity, available;

        // Đọc thông tin sách từ dòng
        getline(ss, isbn, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, publisher, ',');
        ss >> year;
        ss.ignore(1, ','); // Bỏ qua dấu phẩy
        ss >> quantity;
        ss.ignore(1, ','); // Bỏ qua dấu phẩy
        ss >> available;

        // Tạo đối tượng Book và thêm vào danh sách
        books.push_back(Book(isbn, title, author, publisher, year, quantity));
    }

    inFile.close();
    cout << "Đã tải danh sách sách từ file." << endl;
}
void LibrarySystem::saveLoansToFile(const string &filename) {
    ofstream outFile(filename);  // Mở file để ghi
    if (!outFile) {
        cout << "Không thể mở file để lưu danh sách mượn sách!" << endl;
        return;
    }

    // Ghi danh sách các LoanRecord vào file
    for (const auto &loan : loans) {
        outFile << loan.getBookIsbn() << ","
                << loan.getMemberId() << ","
                << loan.getBorrowDateStr() << ","
                << loan.getDueDateStr() << ","
                << loan.getReturnDateStr() << ","
                << loan.getFine() << endl;
    }

    outFile.close();  // Đóng file sau khi ghi xong
    cout << "Đã lưu danh sách mượn sách vào file." << endl;
}
void LibrarySystem::loadLoansFromFile(const string &filename) {
    ifstream inFile(filename);  // Mở file để đọc
    if (!inFile) {
        cout << "Không thể mở file để nạp danh sách mượn sách!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string bookIsbn, memberId, borrowDateStr, dueDateStr, returnDateStr;
        double fine;

        // Đọc các trường từ file
        getline(ss, bookIsbn, ',');
        getline(ss, memberId, ',');
        getline(ss, borrowDateStr, ',');
        getline(ss, dueDateStr, ',');
        getline(ss, returnDateStr, ',');
        ss >> fine;

        // Chuyển đổi các chuỗi ngày thành đối tượng Date
        Date borrowDate, dueDate, returnDate;
        borrowDate.parseDate(borrowDateStr, borrowDate);
        dueDate.parseDate(dueDateStr, dueDate);
        returnDate.parseDate(returnDateStr, returnDate);

        // Tạo LoanRecord và thêm vào danh sách loans
        LoanRecord loan(bookIsbn, memberId, borrowDate, dueDate);
        loan.returnBook(returnDate);  // Cập nhật ngày trả và tiền phạt
        loans.push_back(loan);
    }

    inFile.close();  // Đóng file sau khi đọc xong
    cout << "Đã nạp danh sách mượn sách từ file." << endl;
}
void LibrarySystem::saveMembersToFile(const string &filename) {
    ofstream outFile(filename);  // Mở file để ghi
    if (!outFile) {
        cout << "Không thể mở file để lưu danh sách thành viên!" << endl;
        return;
    }

    // Ghi danh sách thành viên vào file
    for (const auto &member : members) {
        outFile << member.getMemberId() << ","
                << member.getName() << ","
                << member.getContact() << ","
                << member.getRegisterDate() << endl;
    }

    outFile.close();  // Đóng file sau khi ghi xong
    cout << "Đã lưu danh sách thành viên vào file." << endl;
}

void LibrarySystem::loadMembersFromFile(const string &filename) {
    ifstream inFile(filename);  // Mở file để đọc
    if (!inFile) {
        cout << "Không thể mở file để nạp danh sách thành viên!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string memberId, name, contact, registerDate;

        // Đọc các trường từ file
        getline(ss, memberId, ',');
        getline(ss, name, ',');
        getline(ss, contact, ',');
        getline(ss, registerDate, ',');

        // Tạo Member và thêm vào danh sách
        Member member(memberId, name, contact, registerDate);
        members.push_back(member);
    }

    inFile.close();  // Đóng file sau khi đọc xong
    cout << "Đã nạp danh sách thành viên từ file." << endl;
}