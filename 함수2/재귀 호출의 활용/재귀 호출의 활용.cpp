// 10진수의 값을 2진수로 바꾸는 함수
#include <iostream>

using namespace std;

void Convert2Bin(int dec);

int main()
{
	Convert2Bin(13);

	cout << endl;

	return 0;
}

void Convert2Bin(int dec)
{
	// 10진수가 0보다 작거나 같으면 종료한다
	if (dec <= 0) 
		return;

	// 인자를 2로 나눈 값을 인자로 다시 호출한다
	Convert2Bin(dec / 2);

	// 인자를 2로 나눈 나머지를 출력한다
	cout << dec % 2;
}