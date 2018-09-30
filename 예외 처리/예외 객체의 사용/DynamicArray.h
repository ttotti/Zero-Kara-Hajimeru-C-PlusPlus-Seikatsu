#pragma once

class DynamicArray
{
protected:
	int* arr; // 할당한 메모리 보관
	int size; // 배열의 길이 보관

public:
	DynamicArray();
	DynamicArray(int arraySize);
	~DynamicArray();

	// 생성자
	void SetAt(int index, int value);
	int GetAt(int index) const;
	int GetSize() const;
};