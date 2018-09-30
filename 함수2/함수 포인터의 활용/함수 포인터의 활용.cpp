#include <iostream>

using namespace std;

void ForWindows9x();
void ForWindowsNT();
bool IsWindows9x();
void ImportantFunc();

// 하지만 이 코드는 문제가 있다 // 매번 실행 환경을 검사한다는 점이다 한번만 비교하는것으로 충분하다 // 동일한 코드가 중복되있다 39번~43번 과 47번~51번 줄이 동일한 코드이다
int main()
{
	// 아주 중요한 함수 호출
	ImportantFunc();

	return 0;
}

// Windows 95/98/Me 용 환경에서 호출해야하는 함수
void ForWindows9x()
{
	cout << "Windows 9x용 함수가 호출됨" << endl;
}

// Windows NT/2000/XP 용 환경에서 호출해야하는 함수
void ForWindowsNT()
{
	cout << "Windows NT/2000/XP 용 함수가 호출됨" << endl;
}

// 현재 실행되는 환경을 Windows 9x인지 반환하는 함수
bool IsWindows9x()
{
	return false;
}

// 아주 중요한 일을 하는 함수
void ImportantFunc()
{
	// 버전에 맞는 함수를 호출한다
	if (IsWindows9x())
		ForWindows9x();
	else
		ForWindowsNT();

	// 다시 한번 버전에 맞는 함수를 호출한다
	if (IsWindows9x())
		ForWindows9x();
	else
		ForWindowsNT();
}
