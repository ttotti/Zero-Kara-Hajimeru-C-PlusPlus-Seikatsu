#include <iostream>

using namespace std;

char* ShiftLeftString(const char* str, int len)
{
	char* SLS = new char[len + 1]; // 문자열을 넣어줄 변수 // 문자열 만큼의 크기를 할당한다

	SLS[len - 1] = str[0]; // 할당한 배열 끝에서 한칸 뒤에 복사할 첫번째 문자를 넣는다

	for (int i = 0; i < len-1; i++) // 할당한 배열 끝에는 첫번째 문자를 넣었으므로 배열 끝을 제외한 나머지에다 문자열을 넣어준다
	{
		SLS[i] = str[i + 1]; // 비어있는 배열칸에 복사할 두번째 문자열부터 순서대로 넣어준다(첫번째문자는 배열 끝에 이미 넣어주었다)
	}

	SLS[len] = NULL; // 문자열 맨끝에 NULL값을 넣어준다
	
	return SLS; // 문자열을 반환한다
}

int main()
{
	char message[] = "BINGO JJANG!!!";

	char* copy = ShiftLeftString(message, 14);
	cout << copy << endl;

	char* copy2 = ShiftLeftString(copy, 14);
	cout << copy2 << endl;

	delete[] copy;
	copy = NULL;
	delete[] copy2;
	copy2 = NULL;

	return 0;
}