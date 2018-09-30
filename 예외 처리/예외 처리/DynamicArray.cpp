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

// 이 함수에는 문제가 있다 인자에 배열의 크기보다 큰 인덱스를 받았을때 오류가 발생한다
// 그러므로 예외 처리를 하도록 고친다
bool DynamicArray::SetAt(int index, int value)
{
	if (index < 0 || index >= GetSize()) // 매개 변수 index의 범위를 검사한후 문제가 있다면 false를 반환한다
		return false;

	arr[index] = value;
}

int DynamicArray::GetAt(int index) const
{
	return arr[index];
}

int DynamicArray::GetSize() const
{
	return size;
}
