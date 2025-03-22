#include <iostream>
using namespace std;

// Hàm kiểm tra năm nhuận
bool leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Hàm trả về số ngày trong một tháng của một năm cụ thể
int dayinMonth(int m, int y) {
    if (m == 2) return leap(y) ? 29 : 28;
    return (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) ? 31 : 30;
}

// Hàm kiểm tra xem một ngày có hợp lệ hay không
bool checkdate(int d, int m, int y) {
    return (y > 0 && m > 0 && d > 0 && m <= 12 && d <= dayinMonth(m, y));
}

class Date {
private:
    int day, month, year;
public:
    void input();
    bool isValid();
    void Output();
    void previous();       // Hàm tính ngày trước đó
    int dayOfYear();       // Hàm tính ngày thứ trong năm
};

void Date::input() {
    do {
        cout << "Nhap ngay: ";
        cin >> day;
        cout << "Nhap thang: ";
        cin >> month;
        cout << "Nhap nam: ";
        cin >> year;
    } while (!isValid());
}

bool Date::isValid() {
    return checkdate(day, month, year);
}

void Date::Output() {
    if (isValid())
        cout << day << "/" << month << "/" << year << endl;
    else
        cout << "Ngay khong hop le!" << endl;
}

void Date::previous() {
   day--;

    if (day < 1) {
        month--;  
        if (month < 1) {  // Nếu tháng giảm xuống 0, cần quay về tháng 12 năm trước
            month = 12;
            year--;
        }
        day = dayinMonth(month, year); // Lấy ngày cuối cùng của tháng trước
    }

    cout << "Ngay hom truoc: " << day << "/" << month << "/" << year << endl;
}

int Date::dayOfYear() {
    int sum = day;
    for (int i = 1; i < month; i++) {
        sum += dayinMonth(i, year);
    }
    return sum;
}

int main() {
    Date* a = new Date;
    a->input();

    cout << "Ngay hien tai: ";
    a->Output();

    a->previous();

    cout << "La ngay thu " << a->dayOfYear() << " trong nam." << endl;

    delete a;
    return 0;
}
