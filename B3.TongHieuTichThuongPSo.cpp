#include <iostream>
using namespace std;

// Hàm tìm ước chung lớn nhất (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

class PhanSo {
private:
    int tuso, mauso;
public:
    // Hàm khởi tạo
    PhanSo() {
        tuso = 0;
        mauso = 1;
    }

    // Hàm nhập phân số, đảm bảo mẫu số khác 0
    void Nhap() {
        cout << "Nhap tu so: ";
        cin >> tuso;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mauso;
            if (mauso == 0) cout << "Mau so khong duoc bang 0! Vui long nhap lai.\n";
        } while (mauso == 0);
    }

    // Hàm rút gọn phân số
    void RutGon() {
        int ucln = gcd(tuso, mauso);
        tuso /= ucln;
        mauso /= ucln;
        if (mauso < 0) { // Đưa dấu trừ lên tử số
            tuso = -tuso;
            mauso = -mauso;
        }
    }

    // Hàm xuất phân số
    void Xuat() {
        RutGon();
        cout << tuso << "/" << mauso << endl;
    }

    // Toán tử cộng
    PhanSo operator+(const PhanSo& other) {
        PhanSo result;
        result.tuso = tuso * other.mauso + other.tuso * mauso;
        result.mauso = mauso * other.mauso;
        result.RutGon();
        return result;
    }

    // Toán tử trừ
    PhanSo operator-(const PhanSo& other) {
        PhanSo result;
        result.tuso = tuso * other.mauso - other.tuso * mauso;
        result.mauso = mauso * other.mauso;
        result.RutGon();
        return result;
    }

    // Toán tử nhân
    PhanSo operator*(const PhanSo& other) {
        PhanSo result;
        result.tuso = tuso * other.tuso;
        result.mauso = mauso * other.mauso;
        result.RutGon();
        return result;
    }

    // Toán tử chia
    PhanSo operator/(const PhanSo& other) {
        PhanSo result;
        result.tuso = tuso * other.mauso;
        result.mauso = mauso * other.tuso;
        result.RutGon();
        return result;
    }
};

int main() {
    PhanSo a, b;
    
    cout << "Nhap phan so thu nhat:\n";
    a.Nhap();
    
    cout << "Nhap phan so thu hai:\n";
    b.Nhap();

    cout << "\nTong hai phan so: ";
    (a + b).Xuat();
    
    cout << "Hieu hai phan so: ";
    (a - b).Xuat();
    
    cout << "Tich hai phan so: ";
    (a * b).Xuat();
    
    cout << "Thuong hai phan so: ";
    (a / b).Xuat();

    return 0;
} 
