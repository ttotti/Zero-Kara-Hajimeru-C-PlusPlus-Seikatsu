#include "menu.h"
#include <iostream>

using namespace std;

MENU ShowMenu()
{
	while (1)
	{
		system("cls");
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
			return MENU_ADD_STUDENT;
		case '2':
			return MENU_SHOW_ALL;
		case 'q':
		case 'Q':
			return MENU_QUIT;
		default:
			cout << endl << "�ùٸ� ���� �Է����ּ���!" << endl;
			break;
		}

		return MENU_QUIT; // �� ������ ����� �������� �ʴ´�
	}
}