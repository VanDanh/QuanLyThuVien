#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Date
{
public:
    int day, month, year;
    Date(int d, int m, int y);
    Date();

    // Hàm so sánh ngày
    bool isLaterThan(const Date &other) const;

    // Tính số ngày giữa hai ngày
    int daysBetween(const Date &other) const;

    // Hàm chuyển ngày thành chuỗi dễ đọc
    string toString() const;
    // Hàm kiểm tra xem chuỗi có đúng định dạng dd/mm/yyyy hay không
    bool isValidDateFormat(const string &date);
  
    // Hàm chuyển đổi chuỗi dd/mm/yyyy thành day, month, year
    bool parseDate(const string &dateStr, Date &date);

   
};