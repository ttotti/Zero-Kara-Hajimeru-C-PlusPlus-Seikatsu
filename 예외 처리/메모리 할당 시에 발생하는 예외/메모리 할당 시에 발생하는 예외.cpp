#include <new> // bad_alloc 를 사용하기 위한 헤더 파일
#include <iostream>

using namespace std;

// 동적으로 메모리를 할당할때 컴퓨터에 충분한 메모리가 남아있지 않을때 new, new[] 연산자는 bad_alloc 라는 예외를 던진다
// 원래는 new, new[] 연산자를 사용할 때마다 반드시 예외 처리를 해야한다
// 지금까지는 그렇게 하지 않았지만 프로그램은 다양한 컴퓨터에서 실행되고
// 또한 프로그램 실행중에는 무슨일이 일어날지 모르기 때문에 항상 예외가 발생할수 있다는 가정을 하고 만들어야한다
// 예외처리는 중요하다
int main()
{
	try
	{
		// 많은 양의 메모리를 할당한다
		char* p = new char[0xfffffff0];
	}
	// bad_alloc& 타입으로 에외를 받는다
	catch (bad_alloc& ex)
	{
		// 이 클래스에는 예외에 대한 설명 문자열을 반환하는 what()이라는 멤버 함수가 있다
		cout << ex.what() << endl;
	}

	return 0;
}