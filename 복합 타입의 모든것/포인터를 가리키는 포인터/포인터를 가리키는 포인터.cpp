#include <iostream>

using namespace std;

int main()
{
	char c = '1';
	char* pc = &c;
	char** ppc = &pc; // �������� ������ ���� ������ ������ �ּҸ� �����ϴµ� ����Ѵ�

	if (*ppc == pc)
	{
		// ��
	}
	if (**ppc == c)
	{
		// ��
	}

	return 0;
}