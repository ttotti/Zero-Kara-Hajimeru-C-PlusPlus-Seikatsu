#include <iostream>

using namespace std;

int Factorial(int n);
int max(int x, int y);
int MidValue(int, int, int, int, int);

int main()
{
	int result;

	result = Factorial(5); // ���� ����

	cout << "5! �� " << result << " �Դϴ�" << endl;

	//////////

	int ref = max(3, 5); // �ΰ� �̻��� ���� ����

	cout << ref << endl;

	/////////

	int arg1 = 3;
	int arg2 = 5;

	cout << max(arg1, arg2) << endl; // �Լ� ���ڿ� ������ ���� �Լ��ȿ��� �Ű������� �����ǰ� ���� ���Եȴ� // ���ڿ� �Ű������� ���� �ٸ� �޸� ������ ����ϰ��ִ� �� ���� �ٸ� �����̴�

	/////////

	int mid = MidValue(9, 1, 15, 3, 7);

	cout << "�߰��� = " << mid << endl;

	return 0;
}

int Factorial(int n)
{
	int result = 1;

	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}

	return result;
}

int max(int x, int y) // �Ű� ���� �Լ� �ȿ��� ������ ����ó�� ��޵ȴ�
{
	return x > y ? x : y;
}

int MidValue(int a, int b, int c, int d, int e)
{
	int arr[5] = { a,b,c,d,e };
	int temp;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	return arr[2];
}