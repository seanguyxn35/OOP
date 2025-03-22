#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

// Hàm kiểm tra họ tên hợp lệ (không chứa số, độ dài >= 2)
bool isValidName(const string &name) {
    if (name.length() < 2) return false;
    for (char c : name) {
        if (isdigit(c)) return false;
    }
    return true;
}

// Hàm nhập điểm (kiểm tra hợp lệ 0-10)
double inputScore(string subject) {
    double score;
    do {
        cout << "Nhap diem " << subject << ": ";
        cin >> score;
    } while (score < 0 || score > 10);
    return score;
}

class HocSinh {
private:
    string HovaTen;
    double Math, Literature, English;

public:
    void Nhap();
    void Xuat();
    double getDiemTb();
    double getMath();
    string getName();
    string XepLoai();
    bool matchName(string keyword);
};

// Nhập thông tin học sinh
void HocSinh::Nhap() {
    cin.ignore();
    cout << "Nhap ho ten: ";
    do {
        getline(cin, HovaTen);
        if (!isValidName(HovaTen)) {
            cout << "Loi! Ho ten khong hop le. Moi nhap lai!\n";
            cout << "Nhap ho ten: ";
        }
    } while (!isValidName(HovaTen));

    Math = inputScore("Toan");
    Literature = inputScore("Van");
    English = inputScore("Anh");
}

// Xuất thông tin học sinh
void HocSinh::Xuat() {
    cout << "\n-------------\n";
    cout << "Ho ten: " << HovaTen;
    cout << "\nDiem Toan: " << Math;
    cout << "\nDiem Van: " << Literature;
    cout << "\nDiem Ngoai ngu: " << English;
    cout << "\nDiem trung binh: " << getDiemTb();
    cout << "\nXep loai: " << XepLoai() << endl;
}

// Hàm lấy điểm trung bình
double HocSinh::getDiemTb() {
    return (Math * 2 + Literature + English) / 4;
}

// Hàm lấy điểm toán
double HocSinh::getMath() {
    return Math;
}

// Hàm lấy tên học sinh
string HocSinh::getName() {
    return HovaTen;
}

// Hàm xếp loại học sinh
string HocSinh::XepLoai() {
    double x = getDiemTb();
    if (x < 5) return "Yeu";
    if (x >= 5 && x < 6.5) return "Trung Binh";
    if (x >= 6.5 && x < 8) return "Kha";
    if (x >= 8 && x < 9) return "Gioi";
    return "Xuat Sac!";
}

// Hàm tìm học sinh có điểm TB cao nhất
string highestTB(HocSinh* list, int n) {
    double max = list[0].getDiemTb();
    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        if (list[i].getDiemTb() > max) {
            max = list[i].getDiemTb();
            maxIndex = i;
        }
    }
    return list[maxIndex].getName();
}

// Hàm tìm học sinh có điểm toán thấp nhất
void lowestMath(HocSinh* list, int n) {
    vector<string> nameOfLowMath;
    double min = list[0].getMath();

    for (int i = 1; i < n; i++) {
        if (list[i].getMath() < min) {
            min = list[i].getMath();
        }
    }

    for (int i = 0; i < n; i++) {
        if (list[i].getMath() == min) {
            nameOfLowMath.push_back(list[i].getName());
        }
    }

    cout << "Danh sach hoc sinh co diem Toan thap nhat: \n";
    for (string x : nameOfLowMath) {
        cout << "- " << x << endl;
    }
}

// Hàm chuyển đổi chuỗi thành chữ thường (để so sánh không phân biệt hoa thường)
string toLowerCase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Hàm kiểm tra từ khóa có trong tên học sinh không
bool HocSinh::matchName(string keyword) {
    return toLowerCase(HovaTen).find(toLowerCase(keyword)) != string::npos;
}

// Hàm tìm kiếm học sinh theo từ khóa
void Search(HocSinh* list, int n) {
    bool found = false;
    cin.ignore();
    string keyword;
    cout << "\nNhap tu khoa can tim: ";
    getline(cin, keyword);

    cout << "\n*** Ket qua tim kiem ***\n";
    for (int i = 0; i < n; i++) {
        if (list[i].matchName(keyword)) {
            list[i].Xuat();
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay hoc sinh nao!\n";
    }
}
void run(){
    int n;
    cout << "Nhap vao so luong hoc sinh: ";
    cin >> n;

    HocSinh* List = new HocSinh[n];

    for (int i = 0; i < n; i++) {
        cout << "\nNhap vao thong tin hoc sinh thu " << i + 1 << ":\n";
        List[i].Nhap();
    }
    
    int check=0;
    do{
        cout<<"                 MENU"<<endl;
        cout<<"Hay nhap lua chon cua ban: "<<endl;
		cout<<"1. Xuat ra danh sach hoc sinh: "<<endl;
		cout<<"2. Hoc sinh co diem trung binh cao nhat: "<<endl;
		cout<<"3. Tim kiem hoc sinh: "<<endl;
		cout<<"4. Danh sach hoc sinh co diem Toan thap nhat: "<<endl;
		cout<<"5. Exit"<<endl;

		cin>>check;
		switch(check){
		    case(1):{
		        cout << "\nDanh sach hoc sinh:\n";
                for (int i = 0; i < n; i++) {
                    List[i].Xuat();
                }break;
            }
		    case(2):cout << "\nHoc sinh co diem trung binh cao nhat: " << highestTB(List, n) << endl;break;
		    case(3):Search(List, n);break;
		    case(4): lowestMath(List, n);break;
    }}while(check >0 && check <5);
    
    delete[] List;
    }

int main() {
    run();
    return 0;
}
