#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char src[] = "Hanbit-Media";

	int len = strlen(src); // ���ڿ��� ���̸� ������ִ� ���ڿ� �Լ� // �̶� ����ϴ� ���̴� �ǳ��� NULL�� ������ �����̴�

	char* dest = new char[len + 1]; // ������ ���ڿ��� ����+1 ��ŭ �޸𸮸� �Ҵ��Ѵ�

	strcpy(dest, src); // ���ڿ��� �������ִ� ���ڿ� �Լ� // strcpy(���ڿ��� ������ �ּ�, ���� ���ڿ�)

	cout << src << endl;
	cout << dest << endl;

	delete[] dest;
	dest = NULL;

	return 0;
}