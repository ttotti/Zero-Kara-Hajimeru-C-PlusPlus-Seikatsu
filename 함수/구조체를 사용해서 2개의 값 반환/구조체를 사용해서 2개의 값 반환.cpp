#include <iostream>

using namespace std;

struct RetValues
{
	int retValue1;
	int retValue2;
};

RetValues PlusMinus(int a, int b)
{
	RetValues ret;
	ret.retValue1 = a + b;
	ret.retValue2 = a - b;

	return ret; // ����ü ������ ��ȯ�Ѵ� // ����ü ���� �ϳ��� ��ȯ�ص� �����δ� ����ü������ ��� �� �������� ������ ��ȯ�ϴ� ȿ���� ���´�
}

int main()
{
	RetValues result;

	result = PlusMinus(5, 5);

	cout << result.retValue1 << endl;
	cout << result.retValue2 << endl;

	return 0;
}