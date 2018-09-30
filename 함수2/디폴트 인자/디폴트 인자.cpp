#include <iostream>

using namespace std;

bool SetFramesPerSec(int fps = 10) // 디폴트 인자 이 인자는 디폴트 값으로 10을 가지고 있다 // 호출하는 사람이 적당한 값을 모르는 경우 길잡이가 되어줄 수 있다
{
	return true;
}

void a(int a, int b = 10, int c = 20); // 올바름 / 디폴트 인자가 오른쪽에 모여있다
//void b(int a = 10, int b = 10, int c); // 오류 / 디폴트 인자가 가운데에만 있음

int main()
{
	SetFramesPerSec(); // 디폴트 값이 있는 경우에도 직접 인자에 값을 넣어주는 것이 가능하다
	a(100, 200); // 성공 / 인자가 3개여도 값을 2개만 입력해도 성공 // 100은 a에 대입되고 200은 b에 대입되고 다른 c는 디폴트 인자로 대입된다

	return 0;
}