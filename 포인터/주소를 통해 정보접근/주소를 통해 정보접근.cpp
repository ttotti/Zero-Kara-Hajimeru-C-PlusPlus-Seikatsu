#include <iostream>

using namespace std;

int main()
{
	int i = 123;
	int* p = &i;

	cout << "i = " << i << endl;
	cout << "*p = " << *p << endl; // '*p는 p가 가르키는 값' 라는 의미 '&p는 p가 가르키는 주소' 라는 의미

	*p = 456;

	cout << "i = " << i << endl;
	cout << "*p = " << *p << endl << endl;

	//////////////////////////////////////////////////////////////////////////////////

	int a = 65;
	char* c = (char*)&a; // 강제적으로 int타입의 변수를 char타입으로 변환후 주소를 가르키게 했다

	cout << "a = " << a << endl;
	cout << "*c = " << *c << endl; // 결과 아스키코드표 65인 A가 나왔다

	int q = 0x12345678;
	char* pw = (char*)&q;

	//cout << hex;
	cout << "pw = " << (int)*pw << endl << endl; // 4바이트에 0x78 0x56 0x34 0x12(리틀엔디안)이런식으로 저장되있는데 pw의 타입이 char*이므로 1바이트의 내용만 가져오게 된다 고로 결과는 78

	//////////////////////////////////////////////////////////////////////////////////

	int o = 100;
	int* pi = &o;
	int* ppi = pi; // 포인터를 가르키는 포인터 변수

	cout << "t의 값: " << o << endl;
	cout << "pi의 값: " << *pi << endl;
	cout << "ppi의 값: " << *ppi << endl;
	cout << "ppi의 사이즈: " << sizeof(ppi) << endl;

	*pi = 200;

	cout << "t의 값: " << o << endl;
	cout << "pi의 값: " << *pi << endl;
	cout << "ppi의 값: " << *ppi << endl;

	return 0;
}