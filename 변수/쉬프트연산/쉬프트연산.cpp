#include <iostream>

using namespace std;

int main()
{
	int i;

	cout << "값을 입력하시오: ";
	cin >> i;

	i = i << 2; // 왼쪽 쉬프트연산은 * 2^x의 효과가 있다

	cout << i << endl;

	i = i >> 2; // 반대로 오른쪽 쉬프트연산은 / 2^x의 효과가 있다

	cout << i << endl;

	return 0;
}