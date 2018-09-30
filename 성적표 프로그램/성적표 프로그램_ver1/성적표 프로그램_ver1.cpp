#include <iostream>

using namespace std;

int main() // 프로그램을 만들기 전 프로젝트의 뼈대를 먼저 만든다
{
	while (1)
	{
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
			cout << endl << "학생 성적 추가가 선택되었습니다" << endl;
			break;
		case '2':
			cout << endl << "전체 성적 보기가 선택되었습니다" << endl;
			break;
		case 'Q':
		case 'q':
			cout << endl << "프로그램을 종료합니다" << endl;
			return 0;
		default:
			cout << endl << "올바른 선택을 해주세요!" << endl;
			break;
		}
	}

	return 0;
}