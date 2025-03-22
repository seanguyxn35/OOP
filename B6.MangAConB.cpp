 
#include <iostream>
#include <vector>
using namespace std;

void Input(int *a, int n){
    cout<<"Nhap vao cac phan tu: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}

//Hàm đếm các mảng con
void countSubArr(int a[], int b[], int n1, int n2){
    int count=0;
    vector<int> appear;
    bool checked=false; //đặt cờ hiệu để xét các mảng rỗng
   //Dùng 2 con trỏ i và j để xét các mảng con.
    for (int i = 0;i <= n2 - n1; i++){
        int j = 0;
        while(j < n1 && a[j] == b[j + i]) j++;
        if(j == n1) {
            count++;
            appear.push_back(j + i -n1); //Thêm vào vị trí ban đầu.
            checked=true;
        }
   }
   if(!checked) {
       cout<<"Mang A khong la con cua mang B!"<<endl;
       return;
   }
   cout<<"So lan xuat hien: "<< count<<endl;
   cout<<"Vi tri xuat hien la: ";
   for(int x : appear) cout<<x<<" "; // In ra vị trí đã xuất hiện mảng con.
}
int main() {
    int A[100];
    int B[100];
    int n1, n2;
    cout<<"Nhap vao so phan tu cua A: ";
    cin>>n1;
    Input(A,n1);
    cout<<"Nhap vao so phan tu cua B: ";
    cin>>n2;
    Input(B,n2);
    countSubArr(A,B,n1,n2);
    return 0;
}
