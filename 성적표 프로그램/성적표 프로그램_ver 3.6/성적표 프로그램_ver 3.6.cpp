#include "students.h"
#include "menu.h"
#include <iostream>
using namespace std;


int main()
{
	// Students ��ü�� �����.
	Students s;

	// ���α׷��� ������ ������ �޴��� �����ְ�
	// �۾��� ó���Ѵ�.
	while (1)
	{
		// ���ܸ� �������� �޾Ƽ� ó���ϴ� �ڵ嵵 �ۼ��ؾ��Ѵ� �׷��� ��� �޾ƾ� �ұ�?
		// TextOutput�� �����ڿ��� ������ ���ܸ� ���� �� �ִ� ���� �� ������ �ִ�
		// TextOutput ��ü�� �����ϴ� Student::ShowAll() �Լ����� ���� ���� �ְ� �� �Լ��� ȣ���ϴ� main() �Լ����� ���� �� �ִ�
		// �� ���α׷������� �� ���� �ۿ� ������ �ٸ� ������Ʈ���� �� ���� �ĺ��� ������ �� �ִ�
		// �װ� �����ϴ°� ��������� �����ϴ� ���� �����̴� ���ܸ� �޾Ƽ� ��� ó������ �ƴ� ������ ������ �ȴ�
		// �� ���α׷��� main() �Լ����� ���ܸ� �޾� ó���ߴ�
		// �ֳ��ϸ� main() �Լ��� �� ���ܸ� �޾Ƽ� ���� ������ ����ڿ��� ������� �Ѵ� �� ����� �˰� �ֱ� �����̴�
		try
		{
		// �޴��� �����ش�.
		MENU select;
		select = ShowMenu();


		// ���õ� ���� ���� ó��
		switch (select)
		{
		case MENU_ADD_STUDENT:
		case MENU_ADD_STDUENT_ENG:
			// �л� ���� �߰�
		{
			// �л� ���� �߰� �Լ��� ȣ���Ѵ�.
			// (�Ϲ� �л��̶�� true�� ���ڷ� �ѱ��)
			bool succeeded;
			succeeded = s.AddStudent((MENU_ADD_STUDENT == select ? true : false));

			// ����� �˸���.
			if (!succeeded)
				cout << "\n�л� ������ �ùٸ��� �ԷµǾ����ϴ�.\n";
			else
				cout << "\n�� �̻� �Է��� �� �����ϴ�.\n";

			break;
		}
		case MENU_SHOW_ALL:
			// ��ü ���� ����
		{
			// ��ü ���� ���� �Լ��� ȣ���Ѵ�.
			s.ShowAll(Students::CONSOLE);
			break;
		}
		case MENU_SAVE_TEXT:
			// �ؽ�Ʈ ���Ϸ� ��ü ���� ����
		{
			// ��ü ���� ���� �Լ��� ȣ���Ѵ�.
			s.ShowAll(Students::TEXTFILE);

			cout << "\n�ؽ�Ʈ ������ ����Ǿ����ϴ�.\n";
			break;
		}
		case MENU_SAVE_HTML:
			// HTML ���Ϸ� ��ü ���� ����
		{
			// ��ü ���� ���� �Լ��� ȣ���Ѵ�.
			s.ShowAll(Students::HTMLFILE);

			cout << "\nHTML ������ ����Ǿ����ϴ�.\n";
			break;
		}
		case MENU_QUIT:
			// ����
		{
			// ����� ���ҽ��� ���������� �ʾƵ� �ȴ�.
			// Teardown();

			cout << "\n���α׷��� �����մϴ�.\n";
		}
		return 0;
		}// switch�� ��
		}// try�� ��

		// exception& Ÿ���� ���ܸ� �޴´�
		// bad_alloc�� ����� C++�� ���ܵ�� MyException ��ü ��� �̰����� ���� �� �ִ�
		catch (exception& e)
		{
			// ���� ������ ����ϰ� ��� �����Ѵ�
			// ������ �߻��� ����� �˸��� ��ü���� ������ ����Ѵ�
			cout << "\n[���� �� ���� ������ �߻��߽��ϴ�]\n";
			cout << "=> " << e.what() << "\n\n";
		}

	}

	return 0;
}
