#include "DynamicArray.h"
#include "MyException.h"
#include <iostream>

using namespace std;

int main()
{
	try
	{
		// 생성자 내부에서 예외가 발생한다
		DynamicArray arr(100);
	}
	catch (MyException& ex)
	{
		cout << "예외 설명: " << ex.description << endl;
	}

	return 0;
}