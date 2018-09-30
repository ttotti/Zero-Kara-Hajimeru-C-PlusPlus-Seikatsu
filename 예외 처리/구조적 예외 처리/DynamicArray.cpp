#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
}

DynamicArray::DynamicArray(int arraySize)
{
	arr = new int[arraySize];

	size = arraySize;
}

DynamicArray::~DynamicArray()
{
	delete[] arr;
	arr = 0;
}

void DynamicArray::SetAt(int index, int value)
{
	// throw는 예외를 던지는 명령이다
	// 예제에서는 문자열 리터럴을 던졌는데 문자열 리터럴은 const char* 타입의 값일뿐 그냥 정수를 하나 던져도 되고 객체를 하나 던져도 된다
	// 던진 예외 명령은 try catch 에서 받는다
	// 여기서 예외가 발생하면 그 즉시 함수는 종료되고 catch 로 넘어간다
	if (index < 0 || index >= GetSize())
		throw "Out of Range!!!";

	arr[index] = value;
}

int DynamicArray::GetAt(int index) const
{
	if (index < 0 || index >= GetSize())
		throw "Out of Range!!!";

	return arr[index];
}

int DynamicArray::GetSize() const
{
	return size;
}
