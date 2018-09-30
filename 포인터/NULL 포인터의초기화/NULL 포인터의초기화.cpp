#include <iostream>

using namespace std;

int main()
{
	// 포인터를 사용할때는 항상 0또는NULL로 초기화를 해주어야 안전하다
	int* p = 0;

	if (0 != p) // 포인터변수 p가 0이 아닐경우 p가 가르키는 곳의 값을 30으로 바꾼다
		*p = 30;

	int a = 100;
	p = &a; // p가 a의주소를 가르키게한다

	if (p) // p가 0이 아닐경우 p가 가르키는 곳의 값을 30으로 바꾼다
		*p = 30;

	cout << "a = " << a << endl << endl;

	//////////////////////////////////////////////////////////////////////////////////

	int* pi = NULL;

	if (NULL != pi)
		*pi = 30;

	int q = 100;
	pi = &q;

	if (pi)
		*pi = 40;

	cout << "q의 값: " << q << endl;

	return 0;
}