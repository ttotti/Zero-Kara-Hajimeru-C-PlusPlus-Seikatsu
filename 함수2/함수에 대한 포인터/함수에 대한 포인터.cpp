#include <iostream>

using namespace std;

void Dog()
{
	cout << "I'm a dog." << endl;
}

void Cat()
{
	cout << "I'm a cat." << endl;
}

int sum(int a, int b)
{
	int c;

	c = a + b;

	return c;
}

typedef int(*INT_FUNTION)(int, int); // typedef�� �̿��Ͽ� �Լ��� �����͸� �����ϴ� ���� �����ϰ� ������ִ�
typedef void(*VOID_FUNTION)(char*, int);

VOID_FUNTION Func2;

int main()
{
	void(*p)(); // �Լ��� ���� ������ ������ �����Ѵ�

	p = &Dog; // Dog() �Լ��� ����Ű�� �� �Ŀ� ȣ���Ѵ� // �Լ� �̸��� &�� �ٿ��ָ� �Լ��� �ּҸ� ��ȯ�Ѵ�
	(*p)(); // ȣ��

	p = &Cat;
	(*p)();

	int n;
	int(*pSum)(int,int); // intŸ���� ��ȯ�ϰ� intŸ���� ���ڰ� 2���ִ� �Լ������ͺ���
	pSum = &sum;
	n = (pSum)(1, 2);

	cout << n << endl;

	INT_FUNTION Func1;
	Func1 = &sum;

	cout << Func1(2, 2) << endl;

	return 0;
}