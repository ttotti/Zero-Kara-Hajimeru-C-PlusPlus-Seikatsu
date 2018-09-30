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
	// throw�� ���ܸ� ������ ����̴�
	// ���������� ���ڿ� ���ͷ��� �����µ� ���ڿ� ���ͷ��� const char* Ÿ���� ���ϻ� �׳� ������ �ϳ� ������ �ǰ� ��ü�� �ϳ� ������ �ȴ�
	// ���� ���� ����� try catch ���� �޴´�
	// ���⼭ ���ܰ� �߻��ϸ� �� ��� �Լ��� ����ǰ� catch �� �Ѿ��
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
