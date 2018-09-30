#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char str1[20] = "abcde";
	char str2[] = "fghij";

	strcat(str1, str2); // 두개의 문자열을 결합하는 함수 // str1의 맨뒤에다 str2를 붙인다 // 이때 str1의 배열은 넉넉한 크기를 가지고 있어야 한다

	if (strcmp(str1, "abcdefghij") == 0) // 문자열의 내용을 비교한다 // 두 문자열이 같으면 0을 반환한다
	{
		cout << "str1 and \"abcdefgjij\" are identical." << endl;
	}

	if (strcmp(str1, "123456") != 0) // 일부러 틀리게 만들어본다
	{
		cout << "\"123456\" and str1 are NOT identical." << endl;
	}

	return 0;
}