#include "DynamicArray.h"
#include <iostream>

using namespace std;

void UseArray(DynamicArray& arr);

int main()
{
	DynamicArray arr(10);

	UseArray(arr);

	return 0;
}

void UseArray(DynamicArray& arr)
{
	// try catch 는 항상 짝을 이뤄서 사용한다
	// catch 는 throw가 던진 예외를 받는 곳 인데 오직 한가지 타입의 값만 받을 수 있다(이번 예제는 문자열 리터럴 const char* 타입을 받도록 지정했다)
	// try는 예외가 던져지는 범위를 지정하는 역활을 한다
	// 즉 try 안에서 발생하는 예외만 이어지는 catch 블럭에 잡힌다
	try
	{
		// 이곳에서 발생하는 예외만 catch로 넘어간다
		// 여기서 예외가 발생하면 그 즉시 함수는 종료되고 catch 로 넘어간다
		arr.SetAt(5, 100);
		arr.SetAt(8, 100);
		arr.SetAt(10, 100);
	}
	catch (const char* ex)
	{
		cout << "예외 종류 : " << ex << endl;
	}
}

