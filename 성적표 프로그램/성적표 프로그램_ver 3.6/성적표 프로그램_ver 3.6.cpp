#include "students.h"
#include "menu.h"
#include <iostream>
using namespace std;


int main()
{
	// Students 객체를 만든다.
	Students s;

	// 프로그램이 종료할 때까지 메뉴로 보여주고
	// 작업을 처리한다.
	while (1)
	{
		// 예외를 던졌으니 받아서 처리하는 코드도 작성해야한다 그런데 어디서 받아야 할까?
		// TextOutput의 생성자에서 던져진 예외를 받을 수 있는 곳은 두 군데가 있다
		// TextOutput 객체를 생성하는 Student::ShowAll() 함수에서 받을 수도 있고 저 함수를 호출하는 main() 함수에서 받을 수 있다
		// 이 프로그램에서는 두 군데 밖에 없지만 다른 프로젝트에는 더 많은 후보가 존재할 수 있다
		// 그걸 결정하는건 상식적으로 생각하는 것이 정답이다 예외를 받아서 어떻게 처리할지 아는 곳에서 받으면 된다
		// 이 프로그램은 main() 함수에서 예외를 받아 처리했다
		// 왜냐하면 main() 함수는 이 예외를 받아서 예외 내용을 사용자에게 보여줘야 한다 는 사실을 알고 있기 때문이다
		try
		{
		// 메뉴를 보여준다.
		MENU select;
		select = ShowMenu();


		// 선택된 값에 따라서 처리
		switch (select)
		{
		case MENU_ADD_STUDENT:
		case MENU_ADD_STDUENT_ENG:
			// 학생 성적 추가
		{
			// 학생 성적 추가 함수를 호출한다.
			// (일반 학생이라면 true를 인자로 넘긴다)
			bool succeeded;
			succeeded = s.AddStudent((MENU_ADD_STUDENT == select ? true : false));

			// 결과를 알린다.
			if (!succeeded)
				cout << "\n학생 성적이 올바르게 입력되었습니다.\n";
			else
				cout << "\n더 이상 입력할 수 없습니다.\n";

			break;
		}
		case MENU_SHOW_ALL:
			// 전체 성적 보기
		{
			// 전체 성적 보기 함수를 호출한다.
			s.ShowAll(Students::CONSOLE);
			break;
		}
		case MENU_SAVE_TEXT:
			// 텍스트 파일로 전체 성적 저장
		{
			// 전체 성적 보기 함수를 호출한다.
			s.ShowAll(Students::TEXTFILE);

			cout << "\n텍스트 파일이 저장되었습니다.\n";
			break;
		}
		case MENU_SAVE_HTML:
			// HTML 파일로 전체 성적 저장
		{
			// 전체 성적 보기 함수를 호출한다.
			s.ShowAll(Students::HTMLFILE);

			cout << "\nHTML 파일이 저장되었습니다.\n";
			break;
		}
		case MENU_QUIT:
			// 종료
		{
			// 사용한 리소스를 정리해주지 않아도 된다.
			// Teardown();

			cout << "\n프로그램을 종료합니다.\n";
		}
		return 0;
		}// switch의 끝
		}// try의 끝

		// exception& 타입의 예외를 받는다
		// bad_alloc을 비롯한 C++의 예외들과 MyException 객체 모두 이곳에서 받을 수 있다
		catch (exception& e)
		{
			// 에외 내용을 출력하고 계속 진행한다
			// 문제가 발생한 사실을 알리고 구체적인 이유도 출력한다
			cout << "\n[다음 과 같은 문제가 발생했습니다]\n";
			cout << "=> " << e.what() << "\n\n";
		}

	}

	return 0;
}
