#include <iostream>
#include "menu.h"
#include "students.h"

using namespace std;

// 성적표 프로그램_ver 2.3에는 치명적인 버그가 존재한다
// 링크드 리스트는 노드에 포함된 데이터의 타입을 알지않고 범용성을 잃지 않게 해야한다
// 그렇다면 Student에서 제거용 함수를 만들고 그 주소를 List로 넘겨서 List에서 함수의 주소로 호출하는것이다
// 하지만 이 프로그램처럼 함수의 포인터를 사용한 구조가 최선의 해결책은 아니라는 점이다
// 한눈에 보기도 불편하고 링크드 리스트를 사용하려는 곳마다(코드) DeleteData() 같은 함수를 만들어서 넘겨주어야 한다는점도 단점이다

// 하지만 제한된 환경에서 자기 욕심대로 프로그램을 수정하지못하는 경우나 수정할 시간이 없다거나 호환성을 위해 C++ 고급기능을 사용할 수 없는경우에
// 최소한의 노력으로 버그를 해결하는 방법을 보여주었다
// 최선의 해결책이라고 장담할수는 없지만 C++에서 링크드 리스트같은 자료구조를 만들때는 템플릿을 사용하는 것이 일반적이다

// 그리고 이 코드의 구조는 실제로도 자주 사용한다 즉 함수포인터의 적절한 사용법에 대한 학습을 위한것이다

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