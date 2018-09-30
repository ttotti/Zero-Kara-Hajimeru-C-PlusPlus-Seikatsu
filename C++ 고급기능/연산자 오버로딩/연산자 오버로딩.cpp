#include <iostream>
#include "Complex.h"

using namespace std;

// 연산자 오버로딩이 가능한 연산자 및 규칙은 인터넷, 책820p 를 참고한다

// 연산자를 오버로드하는 목적은 어디까지나 클래스의 편리한 사용과 이해하기 쉬운 소스 코드의 생산에 있다

int main()
{
	Complex c1(1, 1);
	Complex c2(2, 2);
	Complex c3(0, 0);

	// + 연산자를 사용한 덧셈
	// 연산자 오버로딩을 이용하여 마치 C++ 기본 타입을 다루는 것처럼 즉 c=a+b 처럼 연산을 수행한다
	c3 = c1 + c2; // c3 = (3, 3)

	// 위의 코드와 동일한 일을 한다
	c3 = c1.operator+(c2);

	Complex c4(1, 1);
	Complex prefix(0, 0);
	Complex postfix(0, 0);

	// 전치 연산
	prefix = c4++; // prefix = c1 = (2,1)

	// 후치 연산
	postfix = ++c4; // postfix = (2,1), c1 = (3,1)

	return 0;
}