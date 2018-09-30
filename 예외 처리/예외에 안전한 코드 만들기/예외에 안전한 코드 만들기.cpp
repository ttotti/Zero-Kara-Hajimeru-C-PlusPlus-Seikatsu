#include <iostream>

using namespace std;

void A();
void B();

int main()
{
	try
	{
		A();
	}
	catch (const char* ex)
	{
		cout << "예외 잡음 : " << ex << endl;
	}

	return 0;
}

void A()
{
	char* p = new char(100);

	cout << "예외가 발생하기 전";

	B(); // 여기서 예외가 발생하고 A함수가 바로 종료후 catch로 넘어간다

	cout << "예외가 발생한 후" << endl;

	// 위에서 예외가 발생해 동적변수를 해제못하고 A함수가 종료된다
	// 이렇게 메모리가 해제해주지 않을때 메모리가 새는 상황이 일어나는데 이걸 메모리 릭 이라고 한다
	delete[] p;
	p = NULL;
}

void B()
{
	throw "Exception!!";
}