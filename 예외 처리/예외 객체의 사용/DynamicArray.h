#pragma once

class DynamicArray
{
protected:
	int* arr; // �Ҵ��� �޸� ����
	int size; // �迭�� ���� ����

public:
	DynamicArray();
	DynamicArray(int arraySize);
	~DynamicArray();

	// ������
	void SetAt(int index, int value);
	int GetAt(int index) const;
	int GetSize() const;
};