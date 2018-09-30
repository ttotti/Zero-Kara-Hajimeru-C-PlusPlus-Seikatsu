#include <iostream>

using namespace std;

// 스마트 포인터 클래스
// C++ 에서는 이런 용도의 스마트포인터를 이미 제공하고있다
// 이거랑 비슷한 원리로 돌아가지만 실제로는 더 많은 기능을 제공한다 (자세한건 http://boost.org 를 참고)
class SmartPointer
{
public:
	const char* ptr; // 이 클래스에는 포인터를 보관할수있는 멤버 변수만 존재
public:
	SmartPointer(char* p)
		:ptr(p)
	{}

	~SmartPointer() // 소멸자에서 멤버 변수 ptr에 보관된 값을 사용해서 메모리를 해제한다 // 소멸자는 반드시 호출된다는 점을 사용
	{
		cout << "메모리가 해제된다(소멸자 호출)\n" << endl;

		delete[] ptr;
	}
};

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

	// 메모리를 스마트 포인터에 보관한다
	// 이 스마트포인터의 객체는 A함수에 존재하므로 A함수가 종료되면 객체도 같이 사라진다 그러므로 객체의 소멸자가 호출된다
	SmartPointer sp(p);

	cout << "예외가 발생하기 전\n";

	B(); // 여기서 예외가 발생하고 A함수가 바로 종료후 catch로 넘어간다

	cout << "예외가 발생한 후" << endl;

	// 메모리를 따로 해제해줄 필요가 없다
	/*delete[] p;
	p = NULL;*/
}

void B()
{
	throw "Exception!!";
}