#include <memory> // auto_ptr를 사용하기 위한 헤더 파일

using namespace std;

int main()
{
	// 스마트 포인터 생성
	// int 타입을 가리킬 수 있는 스마트 포인터 p 를 정의한다
	// int 타입의 값을 하나 할당해서 생성자에 인자로 넘겨준다
	// auto_ptr 에는 new[] 연산자를 사용해서 할당된 메모리의 주소를 보관할 수 없다
	// 예제처럼 new 연산자를 사용해서 할당된 메모리만을 관리할 수 있다 이 밖에도 많은 단점이 존재한다
	// 자세한건 http://boost.org 를 참고한다
	auto_ptr<int> p(new int);

	// 스마틑 포인터 사용
	// 스마트 포인터 객체가 마치 진짜 포인터 처럼 사용할 수 있다
	// 이렇게 할당한 메모리는 스마트 포인터에 의해서 관리된다
	*p = 100;

	// 메모리를 따로 해제줄 필요가 없다

	return 0;
}