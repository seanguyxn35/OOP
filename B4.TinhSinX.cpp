#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Hàm tính giai thừa
double GiaiThua(int n) {
    double res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

// Hàm tính sin(x) bằng chuỗi Taylor
double calculateSin(double x) {
    x = fmod(x, 2 * M_PI); // Đưa x về khoảng [0, 2π]
    
    double res = 0.0, term = x;
    int n = 0;

    while (abs(term) >= 1e-6) { // Sai số nhỏ hơn 10^-6
        res += term;
        n++;
        term = (-term * x * x) / ((2 * n) * (2 * n + 1));
    }
    
    return res;
}

int main() {
    double x;
    cout << "Nhap x (radian): ";
    cin >> x;

    cout << fixed << setprecision(10) << "sin(" << x << ") = " << calculateSin(x) << endl;

    return 0;
}
