#include <iostream>

#include "Plus.h" // 이 헤더파일에는 Plus() 함수의 원형을 가지고 있다

using namespace std;

int main()
{
	int result;

	result = Plus(4, 5);
	cout << result << endl;

	return 0;
}