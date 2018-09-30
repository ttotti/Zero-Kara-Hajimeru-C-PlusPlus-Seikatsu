#include <iostream>

using namespace std;

union MyUnion // 공용체 구조체와 비슷하게 생겼지만 모든 멤버가 같은 메모리 공간에 자리잡는다
{
	int i;
	void* p;
	char c;
};

int main()
{
	MyUnion uni; // 같은 공간을 사용하기때문에 공용체의 크기는 멤버중 가장 크기가 큰 멤버의 크기로 정해진다

	cout << "&uni.i = " << &uni.i << endl; // 두개의 멤버가 주소가 같다
	cout << "&uni.p = " << &uni.p << endl;

	uni.i = 0x12345678; // 한 멤버에 값을 넣으면 다른 멤버에도 영향을 미친다
	cout << hex;
	cout << "uni.i = " << uni.i << endl;
	cout << "uni.p = " << uni.p << endl;

	uni.p = (void*)0x87654321; // 이것또한 다른 멤버에 영향을 미친다
	cout << "uni.i = " << uni.i << endl;
	cout << "uni.p = " << uni.p << endl;


	uni.i = 0x12345678;
	uni.c = 0x90;
	cout << "uni.i = " << uni.i << endl;
	cout << "uni.c = " << (int)uni.c << endl;

	return 0;
}