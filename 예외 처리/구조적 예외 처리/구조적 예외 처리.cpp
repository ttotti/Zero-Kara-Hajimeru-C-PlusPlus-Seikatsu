#include "DynamicArray.h"
#include <iostream>

using namespace std;

void UseArray(DynamicArray& arr);

int main()
{
	DynamicArray arr(10);

	UseArray(arr);

	return 0;
}

void UseArray(DynamicArray& arr)
{
	// try catch �� �׻� ¦�� �̷Ｍ ����Ѵ�
	// catch �� throw�� ���� ���ܸ� �޴� �� �ε� ���� �Ѱ��� Ÿ���� ���� ���� �� �ִ�(�̹� ������ ���ڿ� ���ͷ� const char* Ÿ���� �޵��� �����ߴ�)
	// try�� ���ܰ� �������� ������ �����ϴ� ��Ȱ�� �Ѵ�
	// �� try �ȿ��� �߻��ϴ� ���ܸ� �̾����� catch ���� ������
	try
	{
		// �̰����� �߻��ϴ� ���ܸ� catch�� �Ѿ��
		// ���⼭ ���ܰ� �߻��ϸ� �� ��� �Լ��� ����ǰ� catch �� �Ѿ��
		arr.SetAt(5, 100);
		arr.SetAt(8, 100);
		arr.SetAt(10, 100);
	}
	catch (const char* ex)
	{
		cout << "���� ���� : " << ex << endl;
	}
}

