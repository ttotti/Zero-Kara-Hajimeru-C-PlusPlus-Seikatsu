#include <iostream>
#include "menu.h"
#include "students.h"

using namespace std;

// 성적표 프로그램_ver 2.3에는 치명적인 버그가 존재한다
// 링크드 리스트에 담긴 Student 변수들이 올바르게 해제되지 않기 때문이다
// 그 증거로 Student 구조체에 소멸자를 만들어 프로그램을 종료해보면 소멸자가 호출되지 않는다는 거다(메모리 릭)
// 해결을 위해 List.cpp 의 RemoveList()로 간다
int main() // 프로그램을 만들기 전 프로젝트의 뼈대를 먼저 만든다
{
	// 초기화 한다
	Setup();

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
		{
			Teardown(); // 모든 리스트를 제거한다
			cout << endl << "프로그램을 종료합니다" << endl;
			return 0;
		}
		default:
			cout << endl << "올바른 선택을 해주세요!" << endl;
			break;
		}
	}

	return 0;
}