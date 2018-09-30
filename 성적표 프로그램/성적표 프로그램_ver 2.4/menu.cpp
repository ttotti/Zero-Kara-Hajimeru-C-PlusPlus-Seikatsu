#include "menu.h"
#include <iostream>

using namespace std;

MENU ShowMenu()
{
	while (1)
	{
		system("cls");
		cout << "\n------ 메뉴 ------\n";
		cout << "1. 학생 성적 추가\n";
		cout << "2. 전체 성적 보기" << endl;
		cout << "Q. 프로그램 종료" << endl;
		cout << "-----------------" << endl;
		cout << "원하는 작업의 번호를 입력하시오: ";

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
			cout << endl << "올바른 값을 입력해주세요!" << endl;
			break;
		}

		return MENU_QUIT; // 이 문장은 절대로 실행하지 않는다
	}
}