#include <iostream>
#include "LibrarySystem.h" // Giả sử các class đã được khai báo trong file này

using namespace std;

void displayMenu()
{
    cout << "\n--- Library Management System ---\n";
    cout << "1. Add Book\n";
    cout << "2. Add Member\n";
    cout << "3. Loan Book\n";
    cout << "4. Return Book\n";
    cout << "5. Search Books\n";
    cout << "6. Search Members\n";
    cout << "7. Them sach tu file\n";
    cout << "8. Luu sach xuong file\n";
    cout << "9. Them khach hang tu file\n";
    cout << "10. Luu khach xuong file\n";
    cout << "11. Them cac phieu muon tu file\n";
    cout << "12. Luu phieu muon xuong file\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    LibrarySystem library; // Tạo hệ thống quản lý thư viện
    int choice;

    while (true)
    {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Bỏ qua ký tự xuống dòng còn lại trong buffer

        switch (choice)
        {
        case 1:
        {
            // Add Book
            string isbn, title, author, publisher;
            int year, quantity;
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Publisher: ";
            getline(cin, publisher);
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Quantity: ";
            cin >> quantity;

            Book book(isbn, title, author, publisher, year, quantity);
            library.addBook(book);
            cout << "Book added successfully!\n";
            break;
        }
        case 2:
        {
            // Add Member
            string memberId, name, contact, registerDate;
            cout << "Enter Member ID: ";
            getline(cin, memberId);
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Contact: ";
            getline(cin, contact);
            cout << "Enter Register Date: ";
            getline(cin, registerDate);

            Member member(memberId, name, contact, registerDate);
            library.addMember(member);
            cout << "Member added successfully!\n";
            break;
        }
        case 3:
        {
            // Loan Book
            string isbn, memberId, borrowDateStr, dueDateStr;
            Date checkDay, borrowDate, dueDate;
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            cout << "Enter Member ID: ";
            getline(cin, memberId);

            do
            {
                cout << "Enter Borrow Date (dd/mm/yyyy): ";
                getline(cin, borrowDateStr);
            } while (!checkDay.parseDate(borrowDateStr, borrowDate));

            do
            {
                cout << "Enter Due Date (dd/mm/yyyy): ";
                getline(cin, dueDateStr);
            } while (!checkDay.parseDate(dueDateStr, dueDate));

            if (library.loanBook(isbn, memberId, borrowDate, dueDate))
            {
                cout << "Book loaned successfully!\n";
            }
            else
            {
                cout << "Loan failed! Check book availability or member borrowing limit.\n";
            }
            break;
        }
        case 4:
        {
            // Return Book
            string isbn, memberId, returnDateStr;
            Date returnDate;
            cout << "Enter Member ID: ";
            getline(cin, memberId);
            if (library.findMember(memberId) == nullptr)
            {
                cout << "Khong ton tai khach hang co id " << memberId << endl;
                break;
            }
            cout << "Enter ISBN: ";
            getline(cin, isbn);

            if (library.findBook(isbn) == nullptr)
            {
                cout << "Khong ton tai sach co id " << isbn << endl;
                break;
            }
            do
            {
                cout << "Enter Return Date (dd/mm/yyyy): ";
                getline(cin, returnDateStr);

            } while (!returnDate.parseDate(returnDateStr, returnDate));

            if (library.returnBook(isbn, memberId, returnDate))
            {
                cout << "Book returned successfully!\n";
            }
            else
            {
                cout << "Book returned fail!\n";
            }
            break;
        }
        case 5:
        {
            // Search Books
            string keyword;
            cout << "Enter keyword to search books: ";
            getline(cin, keyword);

            vector<Book> books = library.searchBooks(keyword);
            if (books.empty())
            {
                cout << "No books found.\n";
            }
            else
            {
                cout << "Books found:\n";
                for (const auto &book : books)
                {
                    cout << "ISBN: " << book.getISBN() << ", Title: " << book.getTitle() << ", Author: " << book.getAuthor() << "\n";
                }
            }
            break;
        }
        case 6:
        {
            // Search Members
            string keyword;
            cout << "Enter keyword to search members: ";
            getline(cin, keyword);

            vector<Member> members = library.searchMembers(keyword);
            if (members.empty())
            {
                cout << "No members found.\n";
            }
            else
            {
                cout << "Members found:\n";
                for (const auto &member : members)
                {
                    cout << "Member ID: " << member.getMemberId() << ", Name: " << member.getName() << "\n";
                }
            }
            break;
        }

       
        case 7:
        {

            string duongdan;
            cin >> duongdan;
            library.loadBooksFromFile(duongdan);

            break;
        }
         case 8:
        {

            string duongdan;
            cin >> duongdan;
            library.saveBooksToFile(duongdan);

            break;
        }
         case 9:
        {

            string duongdan;
            cin >> duongdan;
            library.loadMembersFromFile(duongdan);

            break;
        }
         case 10:
        {

            string duongdan;
            cin >> duongdan;
            library.saveMembersToFile(duongdan);

            break;
        }
         case 11:
        {

            string duongdan;
            cin >> duongdan;
            library.loadLoansFromFile(duongdan);

            break;
        }
         case 12:
        {

            string duongdan;
            cin >> duongdan;
            library.saveLoansToFile(duongdan);

            break;
        }
         case 0:
        {
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        }
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
