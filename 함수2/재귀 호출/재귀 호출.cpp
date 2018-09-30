#include <iostream>

using namespace std;

void RecursiveCall(int n);
int factorial(int n);

int main()
{
	RecursiveCall(3);
	
	int n = factorial(4);

	cout << n << endl;

	return 0;
}

void RecursiveCall(int n)
{
	cout << "n = " << n << endl;

	if (n < 0)
		return;

	RecursiveCall(n - 1); // ��� ȣ�� // �Լ��� �ڱ� �ڽ��� ȣ���ϴ� ��� // ������ ���� ���� ���ȣ���� ������ �Լ��� ����� ������� ����ȴ�

	cout << "n = " << n << endl;
}

int factorial(int n) // ���丮���� ����Լ��� ����
{
	if (n <= 1)
		return 1;
	else
		return n*factorial(n - 1); // �Լ��� 1�� ��ȯ�Ҷ����� ���� 1�� ��ȯ�Ҷ� 1�� �Ѱ��־��� 2�� ���� �Լ��� ȣ��ǰ� �� �Լ��� ��ȯ���� 2*1 �ȴ�
								   // �׸��� 2*1�� ��ȯ�ϸ� 2�� �Ѱ��־��� 3�� ���� �Լ��� ȣ��ǰ� �� �Լ��� ��ȯ���� 3*(2*1) �� �ȴ� �̷��� �Ųٷ� �ݺ��ȴ�

}