#include "DynamicArray.h"
#include <iostream>

using namespace std;

int main()
{
	DynamicArray arr(10);

	for (int i = 0; i < 10; ++i)
	{
		arr.SetAt(i, (i + 1) * 10);
	}

	cout << "Size of arr = " << arr.GetSize() << endl;

	for (int i = 9; i >= 0; --i)
	{
		cout << "arr[ " << i << " ] = " << arr.GetAt(i) << endl;
	}

	// �迭 ������ ū ���� �־����� ������ �߻������ʵ��� ���ܸ޽����� �����ش�
	// ������ �̷� ����� �Լ��� ȣ���Ҷ����� �Ź� �̷��� �˻��ؾ��Ѵٴ� ���� ���ŷӴ�
	// �׸��� �� �Լ��� ��� ��ȯ���� void ���� bool �� �ٲ�µ� �ٸ� ��ȯŸ���̿��ٸ� ������ �뵵�� ��� �� �� ���ٴ� ���� �ִ�
	// �̷� ������ �ذ��ϱ� ���� C++�� �����ϴ� ������ ���� ó���� �ִ�
	if (!arr.SetAt(20, 0))
		cout << "index�� ���� ���� �� �迭 ������ ŭ�ϴ�!" << endl;

	return 0;
}