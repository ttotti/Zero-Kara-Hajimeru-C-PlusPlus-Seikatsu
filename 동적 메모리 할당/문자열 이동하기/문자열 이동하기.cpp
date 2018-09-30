#include <iostream>

using namespace std;

char* ShiftLeftString(const char* str, int len)
{
	char* SLS = new char[len + 1]; // ���ڿ��� �־��� ���� // ���ڿ� ��ŭ�� ũ�⸦ �Ҵ��Ѵ�

	SLS[len - 1] = str[0]; // �Ҵ��� �迭 ������ ��ĭ �ڿ� ������ ù��° ���ڸ� �ִ´�

	for (int i = 0; i < len-1; i++) // �Ҵ��� �迭 ������ ù��° ���ڸ� �־����Ƿ� �迭 ���� ������ ���������� ���ڿ��� �־��ش�
	{
		SLS[i] = str[i + 1]; // ����ִ� �迭ĭ�� ������ �ι�° ���ڿ����� ������� �־��ش�(ù��°���ڴ� �迭 ���� �̹� �־��־���)
	}

	SLS[len] = NULL; // ���ڿ� �ǳ��� NULL���� �־��ش�
	
	return SLS; // ���ڿ��� ��ȯ�Ѵ�
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