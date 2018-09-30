#include <iostream>

using namespace std;

int main()
{
	float f[5];
	if (f == &f[0]) // f는 배열의 이름이다 또한 배열의 이름은 첫번째 원소의 주소이다
	{
		// 이 if문은 true로 작동한다 
	}

	///////////////////////////////////////

	int nArray[10]; // 일반적인 배열 정의

	for (int i = 0; i < 10; i++) // 배열을 탐색하면서 값은 넣는다
	{
		nArray[i] = i;
	}

	// 포인터의 덧셈을 이용해 배열탐색
	int mArray[10];
	int* p = &mArray[0]; // 포인터가 배열의 첫번째 원소를 가리키게 한다

	for (int i = 0; i < 10; i++) // *(p + i)는 p가 가리키는 원소에서 i만큼 뒤에 있는 원소를 가리킨다
	{
		*(p + i) = i;
	}

	//////////////////////////////////////////////////////

	int zArray[10];
	int* zp = &zArray[0];

	while (zp != &zArray[10])
	{
		*zp = zp - &zArray[0]; // 첫번째 원소와의 차이를 통해 값을 구한다
		cout << *zp << endl;
		zp++;
	}

	///////////////////////////////////////

	//long lArray[20]; // 보류

	//long(*p)[20] = &lArray;

	//for (int i = 0; i < 20; i++)
	//{
	//	(*p)[i] = i;
	//}

	////(p)[3] = 400;

	//cout << "lArray[3] = " << lArray[3] << endl;

	/////////////////////////////////////////

	double a, b, c;

	double* pArray[3]; // 원소 타입이 포인터이다 3개의 원소를 가진 포인터의 배열을 정의한다

	cout << endl << "pArray의 사이즈 = " << sizeof(pArray) << endl;
	pArray[0] = &a;
	pArray[1] = &b;
	pArray[2] = &c;

	return 0;
}