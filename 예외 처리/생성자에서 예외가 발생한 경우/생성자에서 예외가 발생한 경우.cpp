#include "DynamicArray.h"
#include "MyException.h"
#include <iostream>

using namespace std;

int main()
{
	try
	{
		// ������ ���ο��� ���ܰ� �߻��Ѵ�
		DynamicArray arr(100);
	}
	catch (MyException& ex)
	{
		cout << "���� ����: " << ex.description << endl;
	}

	return 0;
}