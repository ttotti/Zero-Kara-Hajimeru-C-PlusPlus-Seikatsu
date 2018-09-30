#include <iostream>

using namespace std;

void RecursiveCall(int n);
int factorial(int n);

int main()
{
	RecursiveCall(3);
	
	int n = factorial(4);

	cout << n << endl;

	return 0;
}

void RecursiveCall(int n)
{
	cout << "n = " << n << endl;

	if (n < 0)
		return;

	RecursiveCall(n - 1); // 재귀 호출 // 함수가 자기 자신을 호출하는 경우 // 마지막 까지 돌고 재귀호출이 끝날때 함수가 종료된 순서대로 실행된다

	cout << "n = " << n << endl;
}

int factorial(int n) // 펙토리얼을 재귀함수로 재현
{
	if (n <= 1)
		return 1;
	else
		return n*factorial(n - 1); // 함수가 1을 반환할때까지 돌고 1을 반환할때 1을 넘겨주었던 2을 받은 함수로 호출되고 그 함수의 반환값은 2*1 된다
								   // 그리고 2*1을 반환하면 2를 넘겨주었던 3을 받은 함수가 호출되고 그 함수의 반환값은 3*(2*1) 이 된다 이렇게 거꾸로 반복된다

}