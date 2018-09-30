#include <iostream>

using namespace std;

int main()
{
	const int a = 123; // const속성을 가진 변수는 정의하면서 반드시 초기화를 해주어야 한다

	// a = 456; const속성을 가진 변수는 값을 변경할수없다

	////////////////////////////////////////////////////

	// 사용법 1. 배열의 개수를 변수로 지정하고싶을때 상수속성 const를 사용한다
	const unsigned int arraySize = 100; // 개발도중 배열의 개수가 변경될때 여기부분만 바꿔주면 된다

	char characters[arraySize] = { 0 }; // 배열의 개수는 상수로만 지정할수있다

	for (int i = 0; i < arraySize; i++)
	{
		characters[i] = i + 1;
	}

	// 사용법 2. const가 아니지만 잠깐만 const타입으로 바꾸는 경우 <const를 사용해서 배열을 보호하자> 참고 344쪽

	////////////////////////////////////////////////////

	// 포인터변수를 정의할때 const를 최대 2개까지 포함할수있다 그 이유는 하나는 '포인터변수 자체에 보관한 정보' 또 하나는 '포인터가 가르키는 변수의 정보' 이 2가지 이다

	int i1 = 10;
	int i2 = 20;
	int *p = &i1;

	p = &i2; // ok
	*p = 30; // ok

	int a1 = 10;
	int a2 = 20;
	const int *pp = &a1; // p가 가리키는 변수(값)는 const int 타입이다 라는 의미

	a1 = 20; // ok
	a2 = 30; // ok
	pp = &a2; // ok
	*pp = 30; // fail

	int b1 = 10;
	int b2 = 20;
	int* const ppp = &b1; // int 타입을 가리키는 p는 const 속성을 갖는다 라는 의미

	b1 = 20; // ok
	b2 = 30; // ok
	ppp = &a2; // fail // 포인터 자체가 const 속성을 가지므로 변경이 불가하다
	*ppp = 30; // ok   // 하지만 포인터가 가리키는 값은 const 속성이 아니므로 변경이 가능하다

	const int* const pppp = &b1; // 이경우 당연히 둘다 const의 속성을 가지므로 둘다 변경이 불가하다

	pppp = &a2; // fail 
	*pppp = 30; // fail

	return 0;
}