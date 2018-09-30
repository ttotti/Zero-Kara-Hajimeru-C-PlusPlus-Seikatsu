#include <iostream>

using namespace std;

int Factorial(int n);
int max(int x, int y);
int MidValue(int, int, int, int, int);

int main()
{
	int result;

	result = Factorial(5); // 인자 전달

	cout << "5! 는 " << result << " 입니다" << endl;

	//////////

	int ref = max(3, 5); // 두개 이상의 인자 전달

	cout << ref << endl;

	/////////

	int arg1 = 3;
	int arg2 = 5;

	cout << max(arg1, arg2) << endl; // 함수 인자에 변수를 전달 함수안에서 매개변수가 생성되고 값이 대입된다 // 인자와 매개변수는 서로 다른 메모리 공간을 사용하고있다 즉 서로 다른 변수이다

	/////////

	int mid = MidValue(9, 1, 15, 3, 7);

	cout << "중간값 = " << mid << endl;

	return 0;
}

int Factorial(int n)
{
	int result = 1;

	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}

	return result;
}

int max(int x, int y) // 매개 변수 함수 안에서 정의한 변수처럼 취급된다
{
	return x > y ? x : y;
}

int MidValue(int a, int b, int c, int d, int e)
{
	int arr[5] = { a,b,c,d,e };
	int temp;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	return arr[2];
}