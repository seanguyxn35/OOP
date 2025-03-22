Nội dung code: 
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
    void Nhap();
    void Xuat();
    void RutGon();
};

// Nhập phân số
void PhanSo::Nhap() {
    cout << "Nhap vao tu so: ";
    cin>>tuso;
    do{
        cout<<"Nhap vao mau so: ";
        cin>>mauso;
        if(mauso==0) cout<<"Vui long nhap lai!!!"<<endl;
    }while (mauso==0); 
}

// Rút gọn phân số
void PhanSo::RutGon() {
    int temp = gcd(tuso, mauso);
    tuso /= temp;
    mauso /= temp;
}

// Xuất phân số
void PhanSo::Xuat() {
    RutGon();
    if (mauso < 0) {
        tuso = -tuso;
        mauso = -mauso;
        cout << "Phan so rut gon: " << tuso << "/" << mauso << endl;
    }
    else if(mauso==1) cout<<"Phan so rut gon: "<<tuso<<endl;
    else if (tuso==0)  cout << "Phan so rut gon: " <<0<<endl;
    else if (tuso ==mauso) cout<<"Phan so rut gon: "<<1<<endl;
    else cout<<"Phan so rut gon: "<<tuso<<"/"<<mauso<<endl;
}
int main() {
    PhanSo ps;
    ps.Nhap();
    ps.Xuat();
    return 0;
}
