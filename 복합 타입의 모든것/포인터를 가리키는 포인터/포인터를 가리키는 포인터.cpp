#include <iostream>

using namespace std;

int main()
{
	char c = '1';
	char* pc = &c;
	char** ppc = &pc; // 포인터의 포인터 그저 포인터 변수의 주소를 보관하는데 사용한다

	if (*ppc == pc)
	{
		// 참
	}
	if (**ppc == c)
	{
		// 참
	}

	return 0;
}