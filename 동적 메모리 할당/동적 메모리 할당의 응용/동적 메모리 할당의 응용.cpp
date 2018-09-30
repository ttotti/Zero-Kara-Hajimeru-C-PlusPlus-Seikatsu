#include <iostream>

using namespace std;

// ���ڿ��� �������� �������ִ� �Լ�
char* ReverseString(const char* src, int len)
{
	// ���ο� ���ڿ��� ������ �޸𸮸� �Ҵ��Ѵ�
	char* reverse = new char[len + 1];

	// ���ڿ��� �������� �����Ѵ�
	for (int i = 0; i < len; i++)
	{
		reverse[i] = src[len - i - 1];
	}

	// �� ���ڿ��� ���� NULL�� �־��ش�
	reverse[len] = NULL;

	// �� ���ڿ��� ��ȯ�Ѵ�
	return reverse;
}

int main()
{
	// ������ ���ڿ��� �����
	char orginal[] = "NEMODORI";

	// �Լ��� ȣ���Ѵ�
	char* copy = ReverseString(orginal, 8); // �޸� �Ҵ��� �Լ� �ȿ��� ������ �Ҵ��� �޸𸮸� ��ȯ�ؼ� �Լ� �ۿ����� �Ҵ��� �޸𸮸� ������ �ִ�

	// ���
	cout << orginal << endl;
	cout << copy << endl;

	// �Ҵ��� �޸𸮸� �����ϰ� NULL���� �־��ش�
	delete[] copy; // ��������� copy�� �Ҵ��� �޸𸮸� ������ �����Ƿ� copy�� �����Ѵ�
	copy = NULL;

	return 0;
}