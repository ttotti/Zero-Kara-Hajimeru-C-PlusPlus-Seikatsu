#include <iostream>

using namespace std;

// 함수 포인터의 활용1 의 개선
// ForWindows9x()나 ForWindowsNT()를 가리킬 수 있는 포인터 타입을 정의하자
typedef void(*SYSTEM_FUNC)();

void ForWindows9x();
void ForWindowsNT();
bool IsWindows9x();
void ImportantFunc(SYSTEM_FUNC pfnSyst);

int main()
{
	SYSTEM_FUNC pfn;

	if (IsWindows9x()) // 버전을 확인하고 알맞은 함수의 주소를 포인터에 넣어둔다 // 더 이상 검사할일은 없어진다 // 필요할때 포인터를 통해 함수를 호출하면 된다
		pfn = &ForWindows9x;
	else
		pfn = &ForWindowsNT;

	// 아주 중요한 함수 호출
	ImportantFunc(pfn); // 함수의 포인터를 인자로 넘겨준다 // 바로 이 부분이 '야 여기 함수의 주소 있으니까 필요하면 호출해' 라고 말하는 부분이다

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
void ImportantFunc(SYSTEM_FUNC pfnSyst)
{
	(*pfnSyst)();

	(*pfnSyst)();
}
