#include <iostream>

using namespace std;

int main()
{
	unsigned int scores[10] = { 10,100,94,36,72,88,60,60,80,24 };

	float TotalAve = 0.0f;

	cout << "���� �����!!!!" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i+1 << "�� ���� ����: " << scores[i] << endl<<endl;
		TotalAve += scores[i];
	}
	TotalAve = TotalAve / 10.0f;

	cout << "��ü ���: " << TotalAve << endl;

	cout << "Ż����� : ";
	for (int i = 0; i < 10; i++)
	{
		if (scores[i] < TotalAve)
		{
			cout << i+1 << "�� ����  ";
			scores[i] = 0;
		}
	}

	cout << endl;

	int select;
	cout << "������� ���Ͻø� 1��  " << "�����Ͻð� ������ 2���� �����ּ���" << endl;
	cin >> select;

	switch (select)
	{
	case 1:
	{
		for (int i = 0; i < 10; i++)
		{
			if (scores[i] == 0)
				continue;

			cout << i+1 << "�� ���� ����: " << scores[i] << endl << endl;
		}
		break;
	}
	case 2:
		return 0;
	default:
		cout << "�ٽ� �Է����ּ���" << endl;
		break;
	}

	return 0;
}