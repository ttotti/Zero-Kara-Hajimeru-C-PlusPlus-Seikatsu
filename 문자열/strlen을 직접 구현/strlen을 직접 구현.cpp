#include <iostream>

using namespace std;

int stclen(const char* len) // 문자열 길이를 계산해주는 함수 // 문자열의 끝이 NULL이 나올때까지 i를 1 증가시킨다 // NULL값이 나올때 멈추므로 NULL값은 세주지 않는다
{
	int i = 0;

	while (len[i] != NULL)
	{
		i++;
	}

	//i++; // NULL값을 세주지 않으므로 NULL값까지 값을 올리게 만들었다

	return i;
}

void stccpy(char* dest, const char* str) // 문자열을 복사해주는 함수
{
	int len = stclen(str);

	for (int i = 0; i < len+1; i++) // 복사한다 // 위에서 길이를 잰 후 복사하는데 길이를 잴때 NULL값을 안세주면 이 반복문에서 len+1을 해주어야 한다
	{
		dest[i] = str[i];
	}
}

int main()
{
	char src[] = "Lim-ttotti";

	int len = stclen(src);

	char* str = new char[len + 1]; // 길이에 맞게 메모리를 할당했지만 만약 길이를 잴때 그 함수가 NULL값까지 길이를 쟀다면 +1 적어 줄 필요가 없다

	stccpy(str, src);

	cout << str << endl;
	cout << "str의 길이: " << len << endl;

	delete[] str;
	str = NULL;

	return 0;
}