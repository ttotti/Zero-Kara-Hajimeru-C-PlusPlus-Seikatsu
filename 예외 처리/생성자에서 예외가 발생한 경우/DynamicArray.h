#pragma once

#include <iostream>
#include "MyException.h"

using namespace std;

class DynamicArray
{
public:
	int* arr;
	int size;

	DynamicArray(){}
	DynamicArray(int arraySize);

	~DynamicArray();
};

DynamicArray::DynamicArray(int arraySize)
{
	// ������ ���� ��� �ڵ带 try catch �� ���Ѵ� �����ڿ��� �߻��� ��� ���ܸ� �ޱ� ���ؼ���
	try
	{
		// �����ڿ��� �������� �޸𸮸� �Ҵ��Ѵ�
		arr = new int(arraySize);

		// �迭�� ���̸� ����
		size = arraySize;

		// ���⼭ ���Ƿ� ���ܸ� �߻���Ų��
		throw MemoryException(this, 0);
	}
	// ��� ������ ���ܸ� �޴´� ���ܰ� �߻��� ����� �����ϱ� ���� ���̴�
	// �Ҵ��� �޸𸮸� �����Ѵ� �Ҹ��ڰ� ȣ����� �ʱ� ������ ���⼭ �����ؾ��Ѵ�
	catch (...)
	{
		cout << "����� ����ȴ�!!" << endl;

		delete[] arr;
		
		throw; // ���� ���ܸ� �ٽ� ������
	}
}

// ��溸�� �Ҹ��ڿ��� �޸𸮸� ������ �� �̶�� ���������� �׷��� �ʴ�
// C++���� �����ڸ� �ùٸ��� ����� ��츸 ��ü�� ������ ���̶�� �����Ѵ�
// �����ڴ� ���ܰ� �߻��� ������������ ����Ǿ����Ƿ� ��ü�� ���������ʰ� ��ü�� �����Ƿ� �Ҹ��ڴ� ȣ����� �ʴ´�
// �̸� �ذ��ϱ� ���� ���ܸ� �ٽ� ������ �ɷ� �ذ��Ѵ�
DynamicArray::~DynamicArray()
{
	// �Ҹ��ڿ����� ���ܴ� �ݵ�� ���ƾ� �Ѵ�
	// �Ҹ��ڿ��� ���ܰ� �������� ��� ���α׷��� �� ���� �����Ҽ��ִ�
	// �׷��Ƿ� �Ҹ��� ������ ���ܰ� �������� �ʵ��� ��� �ڵ带 try catch �� ���Ѵ�
	// �̷��� ���� ���ܴ� ����� �Ҹ��� ������ �ٽ� �������� �� �ȴ�
	try
	{
		cout << "����� �Ҹ��ڴ�!!" << endl;

		delete[] arr;
		arr = 0;
	}
	catch (...)
	{
	}
}