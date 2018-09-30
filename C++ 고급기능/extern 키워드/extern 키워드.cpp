#include <iostream>

using namespace std;

// 프로그램을 만들다보면 다른 파일에서 정의한 전역 변수에 접근할 일이 생긴다
// 예를 들어서 성적표 프로그램에서 전체 학생 수를 출력해야 하는데 그 변수가 다른 파일에 있는 전역 변수에 보관되어 있다면
// 해당 전역 변수에 접근해서 읽어와야 한다
// 그러기 위해 전역 변수에 접근하기 위한 준비 작업을 해야하는데
// 그 키워드가 extern 이다

// extern 키워드를 사용해여 다른 파일에 있는 전역변수를 읽어온다
// extern 키워드를 제외하고는 a.cpp에서 ga 변수를 정의하는 코드와 동일하다
extern int ga;

// 이 부분을 그냥 void Func() 라고 고쳐도 동일한 의미를 가진다
extern void Func();

int main()
{
	cout << "a.cpp 의 전역변수 ga : " << ga << endl;

	// 다른 파일에 있는 전역 변수에 접근
	ga = 200;

	cout << "main 함수에서 접근 후 a.cpp 의 전역변수 ga : " << ga << endl;

	// 다른 파일에 있는 함수 사용
	Func(); // 성공

	return 0;
}