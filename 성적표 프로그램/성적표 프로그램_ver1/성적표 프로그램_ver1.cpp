#include <iostream>

using namespace std;

int main() // ���α׷��� ����� �� ������Ʈ�� ���븦 ���� �����
{
	while (1)
	{
		cout << "\n------ �޴� ------\n";
		cout << "1. �л� ���� �߰�\n";
		cout << "2. ��ü ���� ����" << endl;
		cout << "Q. ���α׷� ����" << endl;
		cout << "-----------------" << endl;
		cout << "���ϴ� �۾��� ��ȣ�� �Է��Ͻÿ�: ";
		
		char select;
		cin >> select;

		switch (select)
		{
		case '1':
			cout << endl << "�л� ���� �߰��� ���õǾ����ϴ�" << endl;
			break;
		case '2':
			cout << endl << "��ü ���� ���Ⱑ ���õǾ����ϴ�" << endl;
			break;
		case 'Q':
		case 'q':
			cout << endl << "���α׷��� �����մϴ�" << endl;
			return 0;
		default:
			cout << endl << "�ùٸ� ������ ���ּ���!" << endl;
			break;
		}
	}

	return 0;
}