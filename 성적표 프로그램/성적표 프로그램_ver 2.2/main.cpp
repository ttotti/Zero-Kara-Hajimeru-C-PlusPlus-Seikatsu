#include <iostream>
#include "menu.h"
#include "students.h"

using namespace std;

int main() // 프로그램을 만들기 전 프로젝트의 뼈대를 먼저 만든다
{
	while (1)
	{
		MENU select;
		select = ShowMenu();

		switch (select)
		{
		case MENU_ADD_STUDENT:
		{
			cout << endl << "학생 성적 추가가 선택되었습니다" << endl;

			if (AddStudent())
				cout << endl << "학생 성적이 올바르게 입력되었습니다" << endl;
			else
				cout << "더 이상 입력할 수 없습니다" << endl;

			break;
		}
		case MENU_SHOW_ALL:
		{
			cout << endl << "전체 성적 보기가 선택되었습니다" << endl;

			ShowAll();

			break;
		}
		case MENU_QUIT:
			cout << endl << "프로그램을 종료합니다" << endl;
			return 0;
		default:
			cout << endl << "올바른 선택을 해주세요!" << endl;
			break;
		}
	}

	return 0;
}