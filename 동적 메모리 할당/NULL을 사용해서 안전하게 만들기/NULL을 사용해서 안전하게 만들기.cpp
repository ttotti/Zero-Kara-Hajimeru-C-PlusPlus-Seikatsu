#include <iostream>

using namespace std;

int main()
{
	short* p = new short[100]; // 메모리 할당 총 200 바이트를 할당한다

	cout << "p = " << p << endl;

	delete[] p; // 할당한 메모리를 해제한다
	p = NULL; // 해제했으므로 p는 아무것도 가리키고 있지 않다 그래서 안전하게 NULL값을 넣어준다

	cout << "p = " << p << endl;

	delete[] p; // 이미 해제한 메모리를 두번 해제할수없다 이 경우 치명적인 오류가 발생한다 하지만 위에서 안전하게 NULL값을 넣어주었으므로 위험하지 않다
	p = NULL;

	return 0;
}