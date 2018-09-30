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

// �� �Լ����� ������ �ִ� ���ڿ� �迭�� ũ�⺸�� ū �ε����� �޾����� ������ �߻��Ѵ�
// �׷��Ƿ� ���� ó���� �ϵ��� ��ģ��
bool DynamicArray::SetAt(int index, int value)
{
	if (index < 0 || index >= GetSize()) // �Ű� ���� index�� ������ �˻����� ������ �ִٸ� false�� ��ȯ�Ѵ�
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
