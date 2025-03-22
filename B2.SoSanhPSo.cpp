#include <iostream>
using namespace std;
// Lớp PhanSo
class PhanSo {
private:
    int tuso, mauso;

public:
    // Hàm nhập phân số
    void Nhap() {
    cout << "Nhap vao tu so: ";
    cin>>tuso;
    do{
        cout<<"Nhap vao mau so: ";
        cin>>mauso;
        if(mauso==0) cout<<"Vui long nhap lai!!!"<<endl;
    }while (mauso==0); 
}


   

    // Hàm xuất phân số
    void Xuat() {
       
        if (tuso == 0)
            cout << "0";
        else if (mauso == 1)
            cout << tuso;
        else
            cout << tuso << "/" << mauso;
    }

    // Hàm so sánh hai phân số
    bool LonHon(const PhanSo& ps) {
        return tuso * ps.mauso > ps.tuso * mauso;
    }
};

int main() {
    PhanSo p1, p2;

    cout << "Nhap phan so thu nhat:\n";
    p1.Nhap();
    
    cout << "Nhap phan so thu hai:\n";
    p2.Nhap();

    cout << "\nKet qua la: ";
    if (p1.LonHon(p2)) {
        p1.Xuat();
    } else if (p2.LonHon(p1)) {
        p2.Xuat();
    } else {
        cout << "Hai phan so bang nhau.";
    }

    return 0;
}
