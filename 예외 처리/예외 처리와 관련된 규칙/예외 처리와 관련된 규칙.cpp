#include <iostream>

using namespace std;

void A();
void B();
void C();

int main()
{
	try
	{
		A();
	}
	catch(int i)
	{
		cout << "예외 = " << i << endl;
	}
	catch (char* c) // catch는 여러개 쓸수있다 // 객체를 사용해서 상황에 맞게 catch문을 쓸수 있다 // throw에서 넘어온 타입에 맞는 catch가 실행이 된다
	{
		cout << "B() 에서 문제발생!" << c << endl;
	}

	return 0;
}

void A()
{
	cout << "A() 시작" << endl;
	B();
	cout << "A() 끝" << endl;
}

void B()
{
	throw " 빼애액!!";

	C();
}

void C()
{
	// 예외는 함수를 건너 뛰어서까지 전달된다
	// 이 뒤에 호출되었던 함수는 어떠한 실행이 남아있던간에 차례대로 종료되고
	// 예외는 자신의 타입에 맞는 catch 블록을 찾을 때까지 함수를 거슬러 올라간다 (못 찾으면 비정상 종료해버린다)
	throw 332;
}