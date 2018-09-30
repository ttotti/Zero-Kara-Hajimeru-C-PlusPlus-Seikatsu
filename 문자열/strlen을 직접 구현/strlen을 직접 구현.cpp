#include <iostream>

using namespace std;

int stclen(const char* len) // ���ڿ� ���̸� ������ִ� �Լ� // ���ڿ��� ���� NULL�� ���ö����� i�� 1 ������Ų�� // NULL���� ���ö� ���߹Ƿ� NULL���� ������ �ʴ´�
{
	int i = 0;

	while (len[i] != NULL)
	{
		i++;
	}

	//i++; // NULL���� ������ �����Ƿ� NULL������ ���� �ø��� �������

	return i;
}

void stccpy(char* dest, const char* str) // ���ڿ��� �������ִ� �Լ�
{
	int len = stclen(str);

	for (int i = 0; i < len+1; i++) // �����Ѵ� // ������ ���̸� �� �� �����ϴµ� ���̸� �궧 NULL���� �ȼ��ָ� �� �ݺ������� len+1�� ���־�� �Ѵ�
	{
		dest[i] = str[i];
	}
}

int main()
{
	char src[] = "Lim-ttotti";

	int len = stclen(src);

	char* str = new char[len + 1]; // ���̿� �°� �޸𸮸� �Ҵ������� ���� ���̸� �궧 �� �Լ��� NULL������ ���̸� ��ٸ� +1 ���� �� �ʿ䰡 ����

	stccpy(str, src);

	cout << str << endl;
	cout << "str�� ����: " << len << endl;

	delete[] str;
	str = NULL;

	return 0;
}