#include <string>
#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

bool kiemTraNgay(int d, int m, int y) {
    if (y < 0 || y > 2026 || m < 1 || m > 12 || d < 1) return false;
    int soNgayTrongThang[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) soNgayTrongThang[2] = 29;
    return d <= soNgayTrongThang[m];
}

bool kiemTraMaSo(const string &maso) {
    if (maso.length() > 5) return false;
    for (char c : maso) {
        if (!isalnum(c)) return false; // Chỉ cho phép ký tự chữ và số
    }
    return true;
}

bool kiemTraHoTen(const string &hoTen) {
    if (hoTen.length() > 30) return false;
    for (char c : hoTen) {
        if (!isalpha(c) && !isspace(c)) return false; // Chỉ cho phép chữ cái và khoảng trắng
    }
    return true;
}

bool kiemTraLoaiTietKiem(const string &loaiTK) {
    return !loaiTK.empty() && loaiTK.length() <= 10;
}

bool kiemTraCMND(const string &cmnd) {
    if (cmnd.length() != 9 && cmnd.length() != 12) return false;
    for (char c : cmnd) {
        if (!isdigit(c)) return false;
    }
    return true;
}


class SoTietKiem {
private:
	string maSo;
	string loaiTietKiem;
	string hoTenKhachHang;
	string CMND;
	int ngayMo, thangMo, namMo;
	double soTienGui;
	double laiSuat;

public:
	void Nhap();
	void Xuat();
	bool ngayLonHon(const SoTietKiem &other) const ;
    double getTienLai();
    void rutTien();
    
	double getSoTienGui() const {return soTienGui;}
	string getCMND() const {return CMND;}
	string getmaSo() const {return maSo;}
    int getNgayMo() const { return ngayMo; }
    int getThangMo() const { return thangMo; }
    int getNamMo() const { return namMo; }
    
    void setNgayMo(int ngay, int thang, int nam) {
        ngayMo = ngay;
        thangMo = thang;
        namMo = nam;
    }
    void capNhatLaiSuat();

};
void SoTietKiem::Nhap() {
	do {
		cout << "Nhap ma so: ";
		cin >> maSo;
	} while (!kiemTraMaSo(maSo));

	cin.ignore();
	do {
		cout << "Nhap loai tiet kiem: ";
		getline(cin, loaiTietKiem);
	} while (!kiemTraLoaiTietKiem(loaiTietKiem));

	do {
		cout << "Nhap ho ten khach hang: ";
		getline(cin, hoTenKhachHang);
	} while (!kiemTraHoTen(hoTenKhachHang));

	do {
		cout << "Nhap chung minh nhan dan: ";
		cin >> CMND;
	} while (!kiemTraCMND(CMND));

	do {
		cout << "Nhap ngay mo so (dd mm yyyy): ";
		cin >> ngayMo >> thangMo >> namMo;
	} while (!kiemTraNgay(ngayMo, thangMo, namMo));

	do {
		cout << "Nhap so tien gui : ";
		cin >> soTienGui;
	} while (soTienGui<=0);
}

void SoTietKiem::Xuat() {
	cout << "\n--- Thong Tin So Tiet Kiem ---\n";
	cout << "Ma so: " << maSo << endl;
	cout << "Loai tiet kiem: " << loaiTietKiem << endl;
	cout << "Ho ten khach hang: " << hoTenKhachHang << endl;
	cout << "CMND: " << CMND << endl;
	cout << "Ngay mo so: " << ngayMo << "/" << thangMo << "/" << namMo << endl;
	cout << "So tien gui: " << soTienGui << endl;
	cout<<"Tien lai: "<<this->getTienLai()<<endl;
}

double SoTietKiem::getTienLai() {

    int ngayHienTai = 25;
    int thangHienTai = 3;
    int namHienTai = 2025;

    int soThangGui = (namHienTai - namMo) * 12 + (thangHienTai - thangMo);

    double laiSuatApDung = laiSuat;

    // Nếu là ngắn hạn (≤ 6 tháng) hoặc dài hạn (> 6 tháng)
    if (loaiTietKiem == "ngan han" || soThangGui > 6) {
        laiSuatApDung = 0.5; // Nếu quá hạn mà chưa tất toán, giảm lãi suất
    }

    return (soTienGui * laiSuatApDung * soThangGui) / 12 / 100;
}
void SoTietKiem::rutTien() {
    double soTienRut;
    cout << "Nhap so tien muon rut: ";
    cin >> soTienRut;

    if (soTienRut <= 0 || soTienRut > soTienGui) {
        cout << "So tien khong hop le!\n";
        return;
    }

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int ngayHienTai = ltm->tm_mday;
    int thangHienTai = 1 + ltm->tm_mon;
    int namHienTai = 1900 + ltm->tm_year;

    int soThangGui = (namHienTai - namMo) * 12 + (thangHienTai - thangMo);

    if (soThangGui < 6) {
        cout << "Ban dang rut truoc han! Lai suat se duoc tinh theo muc 0.5%/nam\n";
    }

    soTienGui -= soTienRut;
    cout << "Rut tien thanh cong! So du con lai: " << soTienGui << endl;
}

bool SoTietKiem::ngayLonHon(const SoTietKiem &other) const{
    if (namMo != other.namMo) return namMo > other.namMo;
    if (thangMo != other.thangMo) return thangMo > other.thangMo; 
    return ngayMo > other.ngayMo;
}

void sapxepTheoTienGuiGiamDan(SoTietKiem* list, int n) {
    vector<SoTietKiem> danhSachTam(list, list + n); // Tạo bản sao danh sách
    
    sort(danhSachTam.begin(), danhSachTam.end(), [](const SoTietKiem &a, const SoTietKiem &b) {
        return a.getSoTienGui() > b.getSoTienGui();
    });

    cout << "\nDanh sach so tiet kiem sau khi sap xep theo so tien gui (giam dan):\n";
    for (auto stk : danhSachTam) {
        stk.Xuat();
    }
}
void sapxepTheoNgayGuiTangDan(SoTietKiem* list, int n) {
    vector<SoTietKiem> danhSachTam(list, list + n); // Tạo bản sao danh sách
    
    sort(danhSachTam.begin(), danhSachTam.end(), [](const SoTietKiem &a, const SoTietKiem &b) {
        return a.ngayLonHon(b);
    });

    cout << "\nDanh sach so tiet kiem sau khi sap xep theo ngay gui (tang dan):\n";
    for (auto stk : danhSachTam) {
        stk.Xuat();
    }
}

void LietKeTrongKhoangTG(SoTietKiem* list, int n){
    int ngayBD, thangBD, namBD;
    int ngayKT, thangKT, namKT;

    // Nhập khoảng thời gian bắt đầu và kết thúc
    cout << "Nhap ngay bat dau (dd mm yyyy): ";
    cin >> ngayBD >> thangBD >> namBD;
    
    cout << "Nhap ngay ket thuc (dd mm yyyy): ";
    cin >> ngayKT >> thangKT >> namKT;

    if (!kiemTraNgay(ngayBD, thangBD, namBD) || !kiemTraNgay(ngayKT, thangKT, namKT)) {
        cout << "Ngay nhap khong hop le!\n";
        return;
    }
    SoTietKiem A, B;
    A.setNgayMo(ngayBD, thangBD, namBD);
    B.setNgayMo(ngayKT, thangKT, namKT);
    
    bool found=false;
    
    if(A.ngayLonHon(B)){
        cout<<"Khoang nay khong hop le."<<endl;
        return;
    }
    cout<<"Danh sach so tiet kiem mo trong khoang thoi gian: "<<endl;
    for(int i=0;i<n;i++){
        if(!A.ngayLonHon(list[i]) && B.ngayLonHon(list[i])){
            found=true;
            list[i].Xuat();
        }
    }
    if(!found) cout<<"Khong tim thay so tiet kiem phu hop."<<endl;
    return;
}
void Search(SoTietKiem* list, int n) {
	cout<<"Nhap vao ma so hoac CMND can tim: ";
	string key;
	cin>>key;
	bool found=false;
	cin.ignore();
	for(int i=0; i<n; i++) {
        if(list[i].getCMND() == key || list[i].getmaSo() == key){
            cout<<"Ket qua tim kiem la: ";
            list[i].Xuat();
            found=true;
            return;
        }

	}
	if(!found) cout<<"Khong tim thay !"<<endl;
}
void SoTietKiem::capNhatLaiSuat() {
    double laiSuatMoi;
    do {
        cout << "Nhap lai suat moi (%/nam): ";
        cin >> laiSuatMoi;
        if (laiSuatMoi <= 0) {
            cout << "Lai suat phai lon hon 0!\n";
        }
    } while (laiSuatMoi <= 0);

    laiSuat = laiSuatMoi;
    cout << "Cap nhat lai suat thanh cong! Lai suat moi: " << laiSuat << "%/nam\n";
}
void capNhatLaiSuatVaTienLai(SoTietKiem* list, int n){
    cout<<"Chon stk de cap nhat lai suat: ";
    int i;
    cin>>i;
    list[i].capNhatLaiSuat();
    cout<<"Tien lai hien tai la: "<<list[i].getTienLai();
}
void run() {
    int n;
    cout << "Nhap so luong so tiet kiem: ";
    cin >> n;
    SoTietKiem *list = new SoTietKiem[n];

    for (int i = 0; i < n; i++) {
        list[i].Nhap();
    }

    int choice;
    do {
        cout << "\n================ Menu ================\n";
        cout << "1. Xuat danh sach so tiet kiem.\n";
        cout << "2. Rut tien.\n";
        cout << "3. Tim kiem so tiet kiem theo ma so hoac CMND.\n";
        cout << "4. Liet ke danh sach so tiet kiem trong khoang thoi gian nhat dinh.\n";
        cout << "5. Sap xep danh sach so tiet kiem.\n";
        cout << "6. Cap nhat lai suat.\n";
        cout << "7. Thoat.\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < n; i++) {
                    list[i].Xuat();
                }
                break;

            case 2: {
                int i;
                cout << "Chon so tiet kiem de rut (1-" << n << "): ";
                cin >> i;
                if (i >= 1 && i <= n) {
                    list[i - 1].rutTien();
                } else {
                    cout << "Lua chon khong hop le!\n";
                }
                break;
            }

            case 3:
                Search(list, n);
                break;

            case 4:
                LietKeTrongKhoangTG(list, n);
                break;

            case 5: {
                int subChoice;
                cout << "\n1. Sap xep theo ngay mo so (tang dan).\n";
                cout << "2. Sap xep theo so tien gui (giam dan).\n";
                cout << "Nhap lua chon: ";
                cin >> subChoice;

                if (subChoice == 1) {
                    sapxepTheoNgayGuiTangDan(list, n);
                } else if (subChoice == 2) {
                    sapxepTheoTienGuiGiamDan(list, n);
                } else {
                    cout << "Lua chon khong hop le!\n";
                }
                break;
            }

            case 6: {
                int i;
                cout << " Cap nhat lai suat tat ca cac so tiet kiem: "<<endl;
                for(int i=0;i<n;i++){
                    cout<<"Cap nhat lai suat cua so tiet kiem thu "<<i+1<<endl;
                    list[i].capNhatLaiSuat();
                    cout<<"Tien lai hien tai: "<<list[i].getTienLai()<<endl;
                }
                break;
            }

            case 7:
                cout << "Thoat chuong trinh!\n";
                break;

            default:
                cout << "Lua chon khong hop le! Moi nhap lai.\n";
        }
    } while (choice != 7);

    delete[] list;
}
int main()
{
    run();
	return 0;
}

