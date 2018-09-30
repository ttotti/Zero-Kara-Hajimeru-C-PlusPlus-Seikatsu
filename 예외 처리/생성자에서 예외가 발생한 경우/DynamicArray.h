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
	// 생성자 내의 모든 코드를 try catch 로 감싼다 생성자에서 발생한 모든 예외를 받기 위해서다
	try
	{
		// 생성자에서 동적으로 메모리를 할당한다
		arr = new int(arraySize);

		// 배열의 길이를 보관
		size = arraySize;

		// 여기서 고의로 예외를 발생시킨다
		throw MemoryException(this, 0);
	}
	// 모든 종류의 예외를 받는다 예외가 발생한 사실을 포착하기 위한 것이다
	// 할당한 메모리를 해제한다 소멸자가 호출되지 않기 때문에 여기서 해제해야한다
	catch (...)
	{
		cout << "여기는 실행된다!!" << endl;

		delete[] arr;
		
		throw; // 받은 예외를 다시 던진다
	}
}

// 언뜻보면 소멸자에서 메모리를 해제할 것 이라고 생각하지만 그렇지 않다
// C++에는 생성자를 올바르게 종료된 경우만 객체를 생성한 것이라고 간주한다
// 생성자는 예외가 발생해 비정상적으로 종료되었으므로 객체는 생성되지않고 객체가 없으므로 소멸자는 호출되지 않는다
// 이를 해결하기 위해 예외를 다시 던지는 걸로 해결한다
DynamicArray::~DynamicArray()
{
	// 소멸자에서의 예외는 반드시 막아야 한다
	// 소멸자에서 예외가 던져지는 경우 프로그램이 비 정상 종료할수있다
	// 그러므로 소멸자 밖으로 예외가 던져지지 않도록 모든 코드를 try catch 로 감싼다
	// 이렇게 잡은 예외는 절대로 소멸자 밖으로 다시 던져서는 안 된다
	try
	{
		cout << "여기는 소멸자다!!" << endl;

		delete[] arr;
		arr = 0;
	}
	catch (...)
	{
	}
}