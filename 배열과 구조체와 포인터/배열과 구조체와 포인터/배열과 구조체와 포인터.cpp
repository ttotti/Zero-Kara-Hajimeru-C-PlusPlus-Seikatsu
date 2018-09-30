#include <iostream>

using namespace std;

int main()
{
	int array[10]; // 배열정의

	int* p = &array[5]; // 포인터 p가 array[5]를 가리키게한다

	cout << "p = " << p << endl;
	cout << "&array[5] = " << &array[5] << endl; // 결과는 포인터 p 와 배열 array[5]의 주소가 같다

	p++; // 배열을 저장한 포인터의 경우 포인터에 +1을 해주면 다음 원소를 가리켜라 라는 의미가 된다

	cout << "p = " << p << endl;
	cout << "&array[6] = " << &array[6] << endl << endl; // 결과는 같다

	////////////////////////////////////////////////////////

	int iArray[10];

	int* pi = &iArray[3]; // int는 4바이트씩 더하고 뺀다

	cout << "pi = " << pi << endl;
	cout << "pi + 1 = " << pi + 1 << endl;
	cout << "pi + 2 = " << pi + 2 << endl;
	cout << "pi - 1 = " << pi - 1 << endl;

	short sArray[10];
	short* ps = &sArray[3]; // shoat는 2바이트씩 더하고 뺀다

	cout << "ps = " << ps << endl;
	cout << "ps + 1 = " << ps + 1 << endl;
	cout << "ps + 2 = " << ps + 2 << endl;
	cout << "ps - 1 = " << ps - 1 << endl;

	int sArrays[10];
	int* ps1 = &sArrays[3];
	int* ps2 = &sArrays[7];

	cout << "ps1 = " << ps1 << endl;
	cout << "ps2 = " << ps2 << endl;
	cout << "ps2 - ps1= " << ps2 - ps1 << endl; // 포인터간의 뺄셈은 두 포인터가 가리키는 원소 사이에 몇개의 원소가 있는지를 반환한다

	return 0;
}