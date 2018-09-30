#include <iostream>

using namespace std;

void Dog()
{
	cout << "I'm a dog." << endl;
}

void Cat()
{
	cout << "I'm a cat." << endl;
}

int sum(int a, int b)
{
	int c;

	c = a + b;

	return c;
}

typedef int(*INT_FUNTION)(int, int); // typedef를 이용하여 함수의 포인터를 정의하는 일을 간단하게 만들수있다
typedef void(*VOID_FUNTION)(char*, int);

VOID_FUNTION Func2;

int main()
{
	void(*p)(); // 함수에 대한 포인터 변수를 정의한다

	p = &Dog; // Dog() 함수를 가리키게 한 후에 호출한다 // 함수 이름에 &를 붙여주면 함수의 주소를 반환한다
	(*p)(); // 호출

	p = &Cat;
	(*p)();

	int n;
	int(*pSum)(int,int); // int타입을 반환하고 int타입의 인자가 2개있는 함수포인터변수
	pSum = &sum;
	n = (pSum)(1, 2);

	cout << n << endl;

	INT_FUNTION Func1;
	Func1 = &sum;

	cout << Func1(2, 2) << endl;

	return 0;
}