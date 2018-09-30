#include "DynamicArray.h"
#include "MyException.h"

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
	//if (index < 0 || index >= GetSize())
	//	throw MyException(this, "Out of Range!!!", index);

	if (index < 0 || index >= GetSize())
		throw OutOfRangeException(this, index);

	arr[index] = value;
}

int DynamicArray::GetAt(int index) const
{
	/*if (index < 0 || index >= GetSize())
		throw MyException(this, "Out of Range!!!", index);*/

	if (index < 0 || index >= GetSize())
		throw MemoryException(this, index);

	return arr[index];
}

int DynamicArray::GetSize() const
{
	return size;
}
