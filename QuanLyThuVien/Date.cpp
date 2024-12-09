#include <iostream>
#include <string>
#include <ctime>
#include "Date.h"
#include<sstream>
using namespace std;


    Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

    Date::Date()
    {
        this->day=1;
        this->month=1;
        this->year= 2024;
    }

    // Hàm so sánh ngày
    bool Date::isLaterThan(const Date &other) const {
        if (year > other.year) return true;
        if (year < other.year) return false;
        if (month > other.month) return true;
        if (month < other.month) return false;
        return day > other.day;
    }

    // Tính số ngày giữa hai ngày
    int Date::daysBetween(const Date &other) const {
        struct tm tm1 = {0};
        struct tm tm2 = {0};

        tm1.tm_year = year - 1900;  // Year since 1900
        tm1.tm_mon = month - 1;     // Month is 0-based
        tm1.tm_mday = day;

        tm2.tm_year = other.year - 1900;
        tm2.tm_mon = other.month - 1;
        tm2.tm_mday = other.day;

        time_t time1 = mktime(&tm1);
        time_t time2 = mktime(&tm2);

        return difftime(time2, time1) / (60 * 60 * 24);  // Return the difference in days
    }

    // Hàm chuyển ngày thành chuỗi dễ đọc
    string Date::toString() const {
        char buffer[11];
        snprintf(buffer, sizeof(buffer), "%02d-%02d-%d", day, month, year);
        return string(buffer);
    }
     bool Date::isValidDateFormat(const string &date)
    {
        if (date.size() != 10)
            return false;
        if (date[2] != '/' || date[5] != '/')
            return false;

        for (int i = 0; i < date.size(); ++i)
        {
            if (i != 2 && i != 5 && !isdigit(date[i]))
                return false;
        }

        return true;
    }

    // Hàm chuyển đổi chuỗi dd/mm/yyyy thành day, month, year
    bool Date::parseDate(const string &dateStr, Date &date)

    {
        if (!isValidDateFormat(dateStr))
        {
            cout << "nhap ngay khong dung dinh dang" << endl;
            cout << "Vui long nhap lai " << endl;
            return false;
        }

        // Tách chuỗi thành các phần dd, mm, yyyy
        stringstream ss(dateStr);
        char delimiter;
        ss >> date.day >> delimiter >> date.month >> delimiter >> date.year;

        // Kiểm tra tính hợp lệ của ngày, tháng, năm
        if (date.day < 1 || date.day > 31 || date.month < 1 || date.month > 12 || date.year < 1)
        {
            cout << "Nhap ngay khong dung dinh dang " << endl;
            cout << "Vui long nhap lai " << endl;
            return false;
        }

        // Kiểm tra số ngày hợp lệ trong tháng (ví dụ: tháng 2 có thể có 28 hoặc 29 ngày)
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Mảng số ngày trong tháng

        // Kiểm tra tháng 2 trong năm nhuận
        if (date.month == 2 && (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0)))
        {
            daysInMonth[1] = 29;
        }

        if (date.day > daysInMonth[month - 1])
        {
            cout << "khong ton tai ngay nay trong thang !" << endl;
            cout << "Vui long nhap lai " << endl;
            return false;
        }

        return true;
    }
