#include <iostream>

using namespace std;

// 문자열을 뒤집에서 복사해주는 함수
char* ReverseString(const char* src, int len)
{
	// 새로운 문자열을 보관할 메모리를 할당한다
	char* reverse = new char[len + 1];

	// 문자열을 역순으로 복사한다
	for (int i = 0; i < len; i++)
	{
		reverse[i] = src[len - i - 1];
	}

	// 새 문자열의 끝에 NULL을 넣어준다
	reverse[len] = NULL;

	// 새 문자열을 반환한다
	return reverse;
}

int main()
{
	// 뒤집을 문자열을 만든다
	char orginal[] = "NEMODORI";

	// 함수를 호출한다
	char* copy = ReverseString(orginal, 8); // 메모리 할당은 함수 안에서 했지만 할당한 메모리를 반환해서 함수 밖에서도 할당한 메모리를 가지고 있다

	// 출력
	cout << orginal << endl;
	cout << copy << endl;

	// 할당한 메모리를 해제하고 NULL값을 넣어준다
	delete[] copy; // 결과적으로 copy가 할당한 메모리를 가지고 있으므로 copy를 해제한다
	copy = NULL;

	return 0;
}