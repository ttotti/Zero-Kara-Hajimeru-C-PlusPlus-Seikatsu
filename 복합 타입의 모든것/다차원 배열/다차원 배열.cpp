#include <iostream>

using namespace std;

int main()
{
	const int number1 = 10;
	const int number2 = 10;

	int arr[number1][number2];

	for (int i = 0; i < number1; i++)
	{
		for (int j = 0; j < number2; j++)
		{
			arr[i][j] = i*j;
		}
	}

	while (1)
	{
		int n, m;
		cout << "������!! ����� ������� ���� �Է����ּ���(����: 113 �ι�) : ";
		cin >> n >> m;

		if (n == 113 || m == 113)
			break;
		else if (n >= number1 || m >= number2)
		{
			cout << "��� ������ �Ѿ����ϴ�! �ٽ��Է����ּ���" << endl << endl;
			continue;
		}

		cout << n << " x " << m << " = " << arr[n][m] << endl << endl;
	}

	return 0;
}