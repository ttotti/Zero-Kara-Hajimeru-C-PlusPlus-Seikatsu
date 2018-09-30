#include <iostream>

using namespace std;

int main()
{
	char c = 'B';
	int i = 19;
	float f = 4.5f;

	cout << "c의 주소 = " << (int*)&c << endl;
	cout << "i의 주소 = " << &i << endl;
	cout << "f의 주소 = " << &f << endl << endl;

	//////////////////////////////////////////////////////////////////////////////////

	int a = 123; // 일반적인 변수를 선언한다
	int *p; // 포인터 변수를 선언한다

	p = &a; // 포인터 변수 p가 일반변수 a의 주소를 가르키게한다

	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;
	cout << "&p = " << &p << endl << endl;

	//////////////////////////////////////////////////////////////////////////////////

	// 포인터의 사이즈는 항상 4byte 이다
	int q = 100;
	int* pq = &q;
	cout << "q의 사이즈: " << sizeof(q) << endl;
	cout << "pq의 사이즈: " << sizeof(pq) << endl;

	char w = 'A';
	char* pw = &w;
	cout << "w의 사이즈: " << sizeof(w) << endl;
	cout << "pw의 사이즈: " << sizeof(pw) << endl;

	double e = 10.0;
	double* pe = &e;
	cout << "e의 사이즈: " << sizeof(e) << endl;
	cout << "pe의 사이즈: " << sizeof(pe) << endl;

	short int r = 20;
	short int* pr = &r;
	cout << "r의 사이즈: " << sizeof(r) << endl;
	cout << "pr의 사이즈: " << sizeof(pr) << endl;

	bool t = true;
	bool* pt = &t;
	cout << "t의 사이즈: " << sizeof(t) << endl;
	cout << "pt의 사이즈: " << sizeof(pt) << endl;

	/*int u = 300;
	unsigned* y = &u;*/ // 에러! 초기화중 int* 에서 unsigned int* 으로 변환할 수 없습니다!

	return 0;
}