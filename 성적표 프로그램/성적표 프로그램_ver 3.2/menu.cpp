#include "menu.h"
#include <iostream>
using namespace std;

// �޴��� �����ְ�, ���ð��� ��ȯ�Ѵ�.
// ��ȯ�� : ���õ� �޴� �׸�
MENU ShowMenu()
{
	// �ùٸ� �޴��� �� ������ �ݺ��Ѵ�.
	while(1)
	{
		// �޴� �����ֱ�
		cout << "\n------ �޴� ------\n";
		cout << "1. �л� ���� �߰�\n";
		cout << "2. ��ü ���� ����\n";
		cout << "Q. ���α׷� ����\n";
		cout << "------------------\n\n";
		cout << "���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ";

		// �۾� �Է¹ޱ�
		char select;
		cin >> select;

		switch( select)
		{
		case '1': 
			return MENU_ADD_STUDENT;
		case '2':
			return MENU_SHOW_ALL;
		case 'q':
		case 'Q':
			return MENU_QUIT;
		default:
			// �� ���� ����
			cout << "\n�ùٸ� ���� �Է����ּ���.\n";
			break;
		}
	}

	// �� ������ ����� ������� �ʴ´�.
	return MENU_QUIT;
}

