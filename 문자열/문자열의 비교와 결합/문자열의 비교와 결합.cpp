#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char str1[20] = "abcde";
	char str2[] = "fghij";

	strcat(str1, str2); // �ΰ��� ���ڿ��� �����ϴ� �Լ� // str1�� �ǵڿ��� str2�� ���δ� // �̶� str1�� �迭�� �˳��� ũ�⸦ ������ �־�� �Ѵ�

	if (strcmp(str1, "abcdefghij") == 0) // ���ڿ��� ������ ���Ѵ� // �� ���ڿ��� ������ 0�� ��ȯ�Ѵ�
	{
		cout << "str1 and \"abcdefgjij\" are identical." << endl;
	}

	if (strcmp(str1, "123456") != 0) // �Ϻη� Ʋ���� ������
	{
		cout << "\"123456\" and str1 are NOT identical." << endl;
	}

	return 0;
}