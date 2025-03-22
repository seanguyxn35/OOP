
#include <iostream>
using namespace std;


// phan so du thu
/*


int gcd(int a, int b) {
	while (b != 0) {
		int remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}
class pso {
private:
	int tu,mau;
public:
	void nhap();
	void rutgon();
	void in();

	bool operator==(const pso& other);
	bool operator<(const pso& other);
	bool operator>(const pso& other);

	pso operator+(const pso& other);
	pso operator-(const pso& other);
	pso operator*(const pso& other);
	pso operator/(const pso& other);
};
void pso::nhap() {
	cout<<"nhap vao tu va mau"<<endl;
	cin>>tu>>mau;
	if (mau==0) {
		cout<<"nnhaplai";
		return;
	}
}
void pso::rutgon() {
	int c=gcd(tu,mau);
	tu/=c;
	mau/=c;
}
void pso::in() {
	if (tu==0) cout<<0<<endl;
	if (mau==1) cout<<tu<<endl;
	else cout<<tu<<"/"<<mau<<endl;
}
bool pso::operator==(const pso& other) {
	return (tu * other.mau == mau * other.tu);
}
bool pso::operator<(const pso& other) {
	return (tu*other.mau < mau*other.tu);

}
bool pso::operator>(const pso& other) {
	return (tu*other.mau > mau*other.mau);
}
pso pso::operator+(const pso& other) {
	pso s;
	s.mau=mau*other.mau;
	s.tu=tu*other.mau+other.tu*mau;
	s.rutgon();
	return s;
}
pso pso::operator-(const pso& other) {
	pso s;
	s.mau=mau*other.mau;
	s.tu=tu*other.mau-other.tu*mau;
	s.rutgon();
	return s;
}
pso pso::operator*(const pso& other) {
	pso s;
	s.mau=mau*other.mau;
	s.tu=tu*other.tu;
	s.rutgon();
	return s;
}
pso pso::operator/(const pso& other) {
	pso s;
	s.mau=mau*other.tu;
	s.tu=tu*other.mau;
	s.rutgon();
	return s;
}
int main()
{
	pso* a= new pso;
	a->nhap();
	pso* b=new pso;
	b->nhap();
	cout<<"tong: ";
	(*a + *b).in();
	cout<<"hieu: ";
	(*a - *b).in();
	cout<<"tich: ";
	(*a * *b).in();
	cout<<"thuong: ";
	(*a / *b).in();
	delete(b);
	delete(a);
	return 0;
}*/


//date
/*

bool leap(int y){
    return(y%4==0 && y%100!=0) || y%400==0);
}
int cuithang(int m, int y) {
	if (m==2 && leap(y)) return 29;
	if (m==2 ) return 28;
	if (m==1 || m==3|| m==5|| m==7|| m==8|| m==10|| m==12) return 31;
	else return 30;
}
bool checkdate(int d, int m, int y) {
	if (y>0 && m>0 && d>0 && m<=12) {
        if (d<=cuithang(m,y)) return true;
	}
	return false;
}


class date {
	int day,month,year;
public:
	void nhap();
	bool juan();
	void in();
	void next();

};
void date::nhap() {
	cout<<"nhap ngay ";
	cin>>day;
	cout<<"nhap thang ";
	cin>>month;
	cout<<"nhap nam ";
	cin>>year;
}
bool date::juan() {
	return checkdate(day, month, year);
}
void date::in() {
	if (juan()) cout<<day<<"/"<<month<<"/"<<year<<endl;
	else cout<<"Ko hop le";
}
void date::next() {
    if (juan()){
	day++;
    if (day>cuithang(month,year)){
        day=1;
        month++;
        if (month>12){
            year++;
            month=1;
        }
    }
    cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
    else cout<<"KO hop li";
}
int main()
{
	date* a= new date;
	a->nhap();
	cout<<"hien tai"<<endl;
	a->in();
	cout<<"the next day"<<endl;
	a->next();

	return 0;
}

*/


//so phuc
/*
using namespace std;
#include <cmath>
#include <iostream>
class sophuc {
	double a,b;
public:
	void nhap();
	void in();
    double ttdoi();
    
	sophuc operator+(const sophuc& other);
	sophuc operator-(const sophuc& other);
	sophuc operator*(const sophuc& other);
	sophuc operator/(const sophuc& other);
	
};
void sophuc::nhap() {
	cout<<"phan thuc ";
	cin>>a;
	cout<<"phan ao ";
	cin>>b;
}
void sophuc::in() {
    if (a==0 && b==0) cout<<0;
	if (a==0) cout<<b<<"i"<<endl;
	if (b==0) cout<<a<<endl;
	else cout<<a<<"+"<<b<<"i"<<endl;
}
double sophuc::ttdoi(){
    return sqrt(a*a +b*b);
}
sophuc sophuc::operator+(const sophuc& other) {
	sophuc s;
	s.a=a+other.a;
	s.b=b+other.b;
	return s;
}
sophuc sophuc::operator-(const sophuc& other) {
	sophuc s;
	s.a=a-other.a;
	s.b=b-other.b;
	return s;
}
sophuc sophuc::operator*(const sophuc& other) {
	sophuc s;
	s.a= a * other.a - b*other.b;
	s.b= a * other.b + other.a *b;
	return s;
}
sophuc sophuc::operator/(const sophuc& other) {
	sophuc s;
	s.a=(a * other.a + b * other.b)/(other.a * other.a + other.b * other.b);
	s.b=(b * other.a - a * other.b)/(other.a * other.a + other.b * other.b);
	return s;
}
int main()
{
	sophuc* a= new sophuc;
	sophuc* b=new sophuc;
	a->nhap();
	b->nhap();
	cout<<"abs "<<a->ttdoi()<<endl;
	(*a + *b).in();
	(*a - *b).in();
	(*a * *b).in();
	(*a / *b).in();
	delete(a);
	delete(b);

	return 0;
}
*/


//candidate
/*

#include <iostream>
#include <string>
using namespace std;
class candidate {
	string ma,hoten;
	double toan,van,anh;
public:
	void nhap();
	bool check();
	void in();
};
void candidate::nhap() {
	cin>>ma;
	cin.ignore();
	getline(cin,hoten);
	cin>>toan>>van>>anh;
}
bool candidate::check() {
	return (toan+van+anh >15);
}
void candidate::in() {
	cout<<ma<<endl;
	cout<<hoten<<endl;
	cout<<toan<<" "<<van<<" "<<anh<<endl;
}
class testcandidate {
	candidate* a;
	int n;
public:
    testcandidate();
    ~testcandidate();
	void nhap();
	void in();
};
testcandidate::testcandidate(){
    a=nullptr;
    n=0;
}
testcandidate::~testcandidate(){
    delete[] a;
}
void testcandidate::nhap() {
	cout<<"nhap so luong thi sinh: ";
	cin>>n;
    a=new candidate[n];
	for (int i=0; i<n; i++) {
		a[i].nhap();
	}
}
void testcandidate::in() {
	cout<<"ds thoa dk"<<endl;
	bool found=false;
	for (int i=0; i<n; i++) {
		if (a[i].check()) {
			a[i].in();
			found=true;
			cout<<"---------";
		}
		if (!found) cout<<"ko co ai thoa dk";
	}
}
int main() {
    testcandidate a;
    a.nhap();
    a.in();
	return 0;
}
*/



/*
//sinx




#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double GiaiThua(double n){
    if( n==0 || n==1){
        return 1;
    }
    double res=1;
    for (int i=2;i<=n;i++){
        res*=i;
    }
    return res;
}
double calculateSin(int x){
    x=fmod(x, 2*3.14);
    double res=0.0, term =x;
    int n=0;

    while (abs(term)>=0.00001){
        res+=term;
        n++;
        term=(pow(-1,n)*(pow(x,2*n+1))/GiaiThua(2*n+1));
        
    }
    return res;
}
int main()
{
    double x;
    cin>>x;
    cout<<fixed<<setprecision(10)<<"sin: "<< calculateSin(x);
     

    return 0;
}

*/


