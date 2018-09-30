#include <iostream>
#include "menu.h"
#include "students.h"

using namespace std;

// ����ǥ ���α׷�_ver 2.3���� ġ������ ���װ� �����Ѵ�
// ��ũ�� ����Ʈ�� ��� Student �������� �ùٸ��� �������� �ʱ� �����̴�
// �� ���ŷ� Student ����ü�� �Ҹ��ڸ� ����� ���α׷��� �����غ��� �Ҹ��ڰ� ȣ����� �ʴ´ٴ� �Ŵ�(�޸� ��)
// �ذ��� ���� List.cpp �� RemoveList()�� ����
int main() // ���α׷��� ����� �� ������Ʈ�� ���븦 ���� �����
{
	// �ʱ�ȭ �Ѵ�
	Setup();

	while (1)
	{
		MENU select;
		select = ShowMenu();

		switch (select)
		{
		case MENU_ADD_STUDENT:
		{
			cout << endl << "�л� ���� �߰��� ���õǾ����ϴ�" << endl;

			if (AddStudent())
				cout << endl << "�л� ������ �ùٸ��� �ԷµǾ����ϴ�" << endl;
			else
				cout << "�� �̻� �Է��� �� �����ϴ�" << endl;

			break;
		}
		case MENU_SHOW_ALL:
		{
			cout << endl << "��ü ���� ���Ⱑ ���õǾ����ϴ�" << endl;

			ShowAll();

			break;
		}
		case MENU_QUIT:
		{
			Teardown(); // ��� ����Ʈ�� �����Ѵ�
			cout << endl << "���α׷��� �����մϴ�" << endl;
			return 0;
		}
		default:
			cout << endl << "�ùٸ� ������ ���ּ���!" << endl;
			break;
		}
	}

	return 0;
}