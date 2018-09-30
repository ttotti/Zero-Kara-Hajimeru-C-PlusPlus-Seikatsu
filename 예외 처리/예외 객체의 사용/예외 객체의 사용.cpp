#include "DynamicArray.h"
#include "MyException.h"
#include <iostream>

using namespace std;

void UseMemory();
void UseArray(DynamicArray& arr1, DynamicArray& arr2);

int main()
{
	DynamicArray arr1(10);
	DynamicArray arr2(8);

	UseArray(arr1, arr2);

	return 0;
}

void UseArray(DynamicArray& arr1, DynamicArray& arr2) 
{
	// try catch 는 항상 짝을 이뤄서 사용한다
	// catch 는 throw가 던진 예외를 받는 곳 인데 오직 한가지 타입의 값만 받을 수 있다(이번 예제는 문자열 리터럴 const char* 타입을 받도록 지정했다)
	// try는 예외가 던져지는 범위를 지정하는 역활을 한다
	// 즉 try 안에서 발생하는 예외만 이어지는 catch 블럭에 잡힌다
	try
	{
		// 이곳에서 발생하는 예외만 catch로 넘어간다
		// 여기서 예외가 발생하면 그 즉시 함수는 종료되고 catch 로 넘어간다
		arr1.SetAt(5, 100);
		arr2.SetAt(5, 100);

		UseMemory();

		arr1.SetAt(8, 100);
		arr2.SetAt(8, 100);

		arr2.SetAt(10, 100);
		arr2.SetAt(10, 100);
	}
	// MyException& 타입의 예외를 받는다 객체를 예외로 받을때는 레퍼런스로 받는게 좋다
	// 다향성을 이용해서 MyException 클래스에 자식 클래스를 만들어서 인자가 MyException 만 받을 수 있게 되어있지만 자식클래스 모두를 받을 수 있다
	// 그 자식 클래스들은 여기서 예외를 잡을수있다
	catch (MyException& ex)
	{
		cout << "&arr1 = " << &arr1 << "\n&arr2 = " << &arr2 << endl;

		// 예외 객체릐 멤버 변수에 접근해서 다양한 정보를 얻을 수 있다
		cout << "예외를 던진 객체의 주소 = " << ex.sender << endl; // 어떠한 객체 주소에서 예외가 발생했는지
		cout << "예외에 대한 설명 = " << ex.description << endl; // 무슨 오류메시지인지
		cout << "부가 정보 = " << ex.info << endl; // 부가정보로 index의 값이 넘어오는데 예외가 발생할때 index의 값으로 8이 넘어온걸 알수있다
	}
}

void UseMemory()
{
	// 1000바이트를 할당하려다 실패했다고 가정
	throw MemoryException(NULL, 1000);
}