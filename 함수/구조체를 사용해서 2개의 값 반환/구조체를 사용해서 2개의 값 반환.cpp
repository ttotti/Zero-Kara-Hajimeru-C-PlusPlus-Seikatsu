#include <iostream>

using namespace std;

struct RetValues
{
	int retValue1;
	int retValue2;
};

RetValues PlusMinus(int a, int b)
{
	RetValues ret;
	ret.retValue1 = a + b;
	ret.retValue2 = a - b;

	return ret; // 구조체 변수를 반환한다 // 구조체 변수 하나만 반환해도 실제로는 구조체변수의 멤버 즉 여러개의 변수를 반환하는 효과를 갖는다
}

int main()
{
	RetValues result;

	result = PlusMinus(5, 5);

	cout << result.retValue1 << endl;
	cout << result.retValue2 << endl;

	return 0;
}