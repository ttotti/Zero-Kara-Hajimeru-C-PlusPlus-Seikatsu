#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char src[] = "Hanbit-Media";

	int len = strlen(src); // 문자열의 길이를 계산해주는 문자열 함수 // 이때 계산하는 길이는 맨끝의 NULL을 제외한 길이이다

	char* dest = new char[len + 1]; // 복사할 문자열의 길이+1 만큼 메모리를 할당한다

	strcpy(dest, src); // 문자열을 복사해주는 문자열 함수 // strcpy(문자열을 복사할 주소, 원본 문자열)

	cout << src << endl;
	cout << dest << endl;

	delete[] dest;
	dest = NULL;

	return 0;
}