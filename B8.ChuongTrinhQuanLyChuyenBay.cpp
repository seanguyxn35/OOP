
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool kiemTraNgay(int d, int m, int y) {
    if (y < 0 || y > 2026 || m < 1 || m > 12 || d < 1) return false;
    int soNgayTrongThang[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) soNgayTrongThang[2] = 29;
    return d <= soNgayTrongThang[m];
}
// Cấu trúc thời gian (giờ, phút)
struct ThoiGian {
    int gio, phut;
    
    bool kiemTraThoiGian() {
        return (gio >= 0 && gio < 24 && phut >= 0 && phut < 60);
    }
};

// Kiểm tra tính hợp lệ của địa danh
bool kiemTraDiaDanh(const string &tenDiaDanh) {
    if (tenDiaDanh.length() > 20) return false;
    for (char kyTu : tenDiaDanh) {
        if (!isalpha(kyTu) && !isspace(kyTu)) return false;
    }
    return true;
}

// Chuyển chuỗi thành chữ thường
string chuyenChuThuong(string chuoi) {
    transform(chuoi.begin(), chuoi.end(), chuoi.begin(), ::tolower);
    return chuoi;
}

// Lớp ChuyenBay
class ChuyenBay {
    string maChuyenBay;
    int ngayBay, thangBay, namBay;
    ThoiGian gioBay;
    string noiKhoiHanh;
    string noiDen;

public:
    void Nhap();
    void Xuat();
    bool timKiemTuKhoa(string tuKhoa);
    bool soSanhThoiGianBay(const ChuyenBay& other) const;
    bool kiemTraTuyenBay(const string &diemDi, const string &diemDen);
    bool kiemTraChuyenBayTheoNgay(const string &diemDi, int ngay, int thang, int nam);

    string getMaChuyenBay() { return maChuyenBay; }
    string getNoiKhoiHanh() { return noiKhoiHanh; }
    string getNoiDen() { return noiDen; }
    int getNgay() { return ngayBay; }
    int getThang() { return thangBay; }
    int getNam() { return namBay; }
    int getGio() { return gioBay.gio; }
    int getPhut() { return gioBay.phut; }
};
// Hàm nhập thông tin
void ChuyenBay::Nhap() {
    cout << "Nhap ma chuyen bay: ";
    cin >> maChuyenBay;
    cin.ignore();

    // Nhập ngày bay
    do {
        cout << "Nhap ngay khoi hanh (dd mm yyyy): ";
        cin >> ngayBay >> thangBay >> namBay;
        
        if (cin.fail()) {  // Kiểm tra nhập sai dữ liệu (không phải số)
            cin.clear();    // Xóa trạng thái lỗi
            cin.ignore(10000, '\n');  // Xóa bộ đệm
            cout << "Loi: Vui long nhap so nguyen hop le!\n";
            continue;
        }

        if (!kiemTraNgay(ngayBay, thangBay, namBay)) {
            cout << "Ngay khong hop le! Nhap lai.\n";
        }

    } while (!kiemTraNgay(ngayBay, thangBay, namBay));

    // Nhập giờ bay
    do {
        cout << "Nhap gio khoi hanh (hh mm): ";
        cin >> gioBay.gio >> gioBay.phut;

        if (cin.fail()) {  // Xử lý nhập sai
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Loi: Vui long nhap so nguyen hop le!\n";
            continue;
        }

        if (!gioBay.kiemTraThoiGian()) {
            cout << "Gio khong hop le! Nhap lai.\n";
        }

    } while (!gioBay.kiemTraThoiGian());

    cin.ignore();  // Xóa ký tự xuống dòng trước khi nhập chuỗi

    // Nhập nơi khởi hành
    do {
        cout << "Nhap noi khoi hanh: ";
        getline(cin, noiKhoiHanh);

        if (!kiemTraDiaDanh(noiKhoiHanh)) {
            cout << "Dia danh khong hop le! Nhap lai.\n";
        }

    } while (!kiemTraDiaDanh(noiKhoiHanh));

    // Nhập nơi đến
    do {
        cout << "Nhap noi den: ";
        getline(cin, noiDen);

        if (!kiemTraDiaDanh(noiDen)) {
            cout << "Dia danh khong hop le! Nhap lai.\n";
        }

    } while (!kiemTraDiaDanh(noiDen));
}//Hàm xuất thông tin
void ChuyenBay::Xuat() {
    cout << "Ma chuyen bay: " << maChuyenBay << endl;
    cout << "Ngay khoi hanh: " << ngayBay << "/" << thangBay << "/" << namBay << endl;
    cout << "Gio bay: " << gioBay.gio << ":" << gioBay.phut << endl;
    cout << "Noi khoi hanh: " << noiKhoiHanh << endl;
    cout << "Noi den: " << noiDen << endl;
}
//Hàm tìm kiếm từ khóa trùng
bool ChuyenBay::timKiemTuKhoa(string tuKhoa) {
    tuKhoa = chuyenChuThuong(tuKhoa);
    return (chuyenChuThuong(maChuyenBay).find(tuKhoa) != string::npos ||
            chuyenChuThuong(noiKhoiHanh).find(tuKhoa) != string::npos ||
            chuyenChuThuong(noiDen).find(tuKhoa) != string::npos);
}
//Hàm so sánh ngày với ngày
bool ChuyenBay::soSanhThoiGianBay(const ChuyenBay &other) const {
    if (namBay != other.namBay) return namBay < other.namBay;
    if (thangBay != other.thangBay) return thangBay < other.thangBay;
    if (ngayBay != other.ngayBay) return ngayBay < other.ngayBay;
    if (gioBay.gio != other.gioBay.gio) return gioBay.gio < other.gioBay.gio;
    return gioBay.phut < other.gioBay.phut;
}
//Hàm kiểm tra các tuyến bay giống 
bool ChuyenBay::kiemTraTuyenBay(const string &diemDi, const string &diemDen) {
    return chuyenChuThuong(noiKhoiHanh) == chuyenChuThuong(diemDi) &&
           chuyenChuThuong(noiDen) == chuyenChuThuong(diemDen);
}
//Hàm kiểm tra các chuyến bay cùng nơi xuất phát
bool ChuyenBay::kiemTraChuyenBayTheoNgay(const string &diemDi, int ngay, int thang, int nam) {
    return chuyenChuThuong(noiKhoiHanh) == chuyenChuThuong(diemDi) &&
           ngayBay == ngay && thangBay == thang && namBay == nam;
}
//Hàm sắp xếp chuyến bay theo thời gian tăng dần
void sapXepChuyenBay(ChuyenBay* danhSach, int soLuong) {
    sort(danhSach, danhSach + soLuong, [](ChuyenBay a, ChuyenBay b) { return a.soSanhThoiGianBay(b); });
}
//Hàm tìm kiếm 
void ketQuaTimKiem(ChuyenBay* list, int n) {
    cout << " Tim kiem chuyen bay" << endl;
    string key;
    
    cout << "Nhap vao tu khoa tim kiem: ";
    cin.ignore();
    getline(cin, key);

    bool found = false;
    cout << "\n Ket qua tim kiem:\n";
    
    for (int i = 0; i < n; i++) {
        if (list[i].timKiemTuKhoa(key)) {
            list[i].Xuat();
            found = true;
            cout << "-----------------\n";
        }
    }
    
    if (!found) cout << "Khong tim thay chuyen bay phu hop!\n";
    return;
}
//Hàm liệt kê
void lietKeChuyenBayCungDiaDiemThoiGian(ChuyenBay* danhSach, int soLuong) {
    string noiKhoiHanh;
    int ngay, thang, nam;

    cout << "\n Liet ke cac chuyen bay cung noi khoi hanh va ngay bay:\n";
    
    do {
        cout << "Nhap noi khoi hanh: ";
        cin.ignore();
        getline(cin, noiKhoiHanh);
    } while (!kiemTraDiaDanh(noiKhoiHanh));

    do {
        cout << "Nhap ngay khoi hanh (dd mm yyyy): ";
        cin >> ngay >> thang >> nam;
    } while (!kiemTraNgay(ngay, thang, nam));

    vector<ChuyenBay> danhSachKetQua;
    
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].getNoiKhoiHanh() == noiKhoiHanh && 
            danhSach[i].getNgay() == ngay &&
            danhSach[i].getThang() == thang &&
            danhSach[i].getNam() == nam) 
        {
            danhSachKetQua.push_back(danhSach[i]);
        }
    }

    if (danhSachKetQua.empty()) {
        cout << "Khong tim thay chuyen bay nao!\n";
    } else {
        cout << "\n Danh sach chuyen bay:\n";
        for (ChuyenBay& cb : danhSachKetQua) {
            cb.Xuat();
            cout << "-----------------\n";
        }
    }
}
//Hàm đếm các chuyến bay có cùng điểm đi và đến
void demChuyenBay(ChuyenBay* danhSach, int soLuong) {
    string diemDi, diemDen;
    cin.ignore();
    do {
        cout << "Nhap noi khoi hanh: "<<endl;
        getline(cin, diemDi);

        if (!kiemTraDiaDanh(diemDi)) {
            cout << "Dia danh khong hop le! Nhap lai.\n";
        }

    } while (!kiemTraDiaDanh(diemDi));

    // Nhập nơi đến
    do {
        cout << "Nhap noi den: "<<endl;
        getline(cin, diemDen);

        if (!kiemTraDiaDanh(diemDen)) {
            cout << "Dia danh khong hop le! Nhap lai.\n";
        }

    } while (!kiemTraDiaDanh(diemDen));

    int soChuyenBay = 0;
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].kiemTraTuyenBay(diemDi, diemDen)) {
            soChuyenBay++;
        }
    }
    cout<<"So luong chuyen bay phu hop la: "<<soChuyenBay<<endl;
   
}//Menu chính
void run(){
    int soLuong;
    cout << "Nhap so luong chuyen bay: ";
    cin >> soLuong;

    ChuyenBay* danhSachChuyenBay = new ChuyenBay[soLuong];

    for (int i = 0; i < soLuong; i++) {
        danhSachChuyenBay[i].Nhap();
    }
    int choice=0;
    do{
        cout<<"=========Menu======="<<endl;
        cout<<"1. Xuat ra danh sach chuyen bay."<<endl;
        cout<<"2. Sap xep chuyen bay theo thoi gian."<<endl;
        cout<<"3. Tim kiem."<<endl;
        cout<<"4. Liet ke cac chuyen bay cung thoi diem."<<endl;
        cout<<"5. Dem so chuyen bay theo tuyen duong."<<endl;
        cout<<"6. Exit."<<endl;
        cout<<"Hay nhap vao lua chon cua ban: ";
        cin>>choice;
        switch(choice){
            case(1):{
                for(int i=0;i<soLuong;i++){
                    danhSachChuyenBay[i].Xuat();
                }
                break;
            }
            case(2):sapXepChuyenBay(danhSachChuyenBay, soLuong);break;
            case(3):ketQuaTimKiem(danhSachChuyenBay, soLuong);break;
            case(4):lietKeChuyenBayCungDiaDiemThoiGian(danhSachChuyenBay, soLuong);break;
            case(5):demChuyenBay(danhSachChuyenBay, soLuong);break;
        }
    }while(choice >0 && choice <6);
    delete[] danhSachChuyenBay;
}
int main() {
    run();
    return 0;
}	
