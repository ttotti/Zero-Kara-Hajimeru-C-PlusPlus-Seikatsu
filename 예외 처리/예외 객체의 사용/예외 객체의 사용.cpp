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
	// try catch �� �׻� ¦�� �̷Ｍ ����Ѵ�
	// catch �� throw�� ���� ���ܸ� �޴� �� �ε� ���� �Ѱ��� Ÿ���� ���� ���� �� �ִ�(�̹� ������ ���ڿ� ���ͷ� const char* Ÿ���� �޵��� �����ߴ�)
	// try�� ���ܰ� �������� ������ �����ϴ� ��Ȱ�� �Ѵ�
	// �� try �ȿ��� �߻��ϴ� ���ܸ� �̾����� catch ���� ������
	try
	{
		// �̰����� �߻��ϴ� ���ܸ� catch�� �Ѿ��
		// ���⼭ ���ܰ� �߻��ϸ� �� ��� �Լ��� ����ǰ� catch �� �Ѿ��
		arr1.SetAt(5, 100);
		arr2.SetAt(5, 100);

		UseMemory();

		arr1.SetAt(8, 100);
		arr2.SetAt(8, 100);

		arr2.SetAt(10, 100);
		arr2.SetAt(10, 100);
	}
	// MyException& Ÿ���� ���ܸ� �޴´� ��ü�� ���ܷ� �������� ���۷����� �޴°� ����
	// ���⼺�� �̿��ؼ� MyException Ŭ������ �ڽ� Ŭ������ ���� ���ڰ� MyException �� ���� �� �ְ� �Ǿ������� �ڽ�Ŭ���� ��θ� ���� �� �ִ�
	// �� �ڽ� Ŭ�������� ���⼭ ���ܸ� �������ִ�
	catch (MyException& ex)
	{
		cout << "&arr1 = " << &arr1 << "\n&arr2 = " << &arr2 << endl;

		// ���� ��ü�l ��� ������ �����ؼ� �پ��� ������ ���� �� �ִ�
		cout << "���ܸ� ���� ��ü�� �ּ� = " << ex.sender << endl; // ��� ��ü �ּҿ��� ���ܰ� �߻��ߴ���
		cout << "���ܿ� ���� ���� = " << ex.description << endl; // ���� �����޽�������
		cout << "�ΰ� ���� = " << ex.info << endl; // �ΰ������� index�� ���� �Ѿ���µ� ���ܰ� �߻��Ҷ� index�� ������ 8�� �Ѿ�°� �˼��ִ�
	}
}

void UseMemory()
{
	// 1000����Ʈ�� �Ҵ��Ϸ��� �����ߴٰ� ����
	throw MemoryException(NULL, 1000);
}