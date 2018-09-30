#include <iostream>
#include "Complex.h"

using namespace std;

// ������ �����ε��� ������ ������ �� ��Ģ�� ���ͳ�, å820p �� �����Ѵ�

// �����ڸ� �����ε��ϴ� ������ �������� Ŭ������ ���� ���� �����ϱ� ���� �ҽ� �ڵ��� ���꿡 �ִ�

int main()
{
	Complex c1(1, 1);
	Complex c2(2, 2);
	Complex c3(0, 0);

	// + �����ڸ� ����� ����
	// ������ �����ε��� �̿��Ͽ� ��ġ C++ �⺻ Ÿ���� �ٷ�� ��ó�� �� c=a+b ó�� ������ �����Ѵ�
	c3 = c1 + c2; // c3 = (3, 3)

	// ���� �ڵ�� ������ ���� �Ѵ�
	c3 = c1.operator+(c2);

	Complex c4(1, 1);
	Complex prefix(0, 0);
	Complex postfix(0, 0);

	// ��ġ ����
	prefix = c4++; // prefix = c1 = (2,1)

	// ��ġ ����
	postfix = ++c4; // postfix = (2,1), c1 = (3,1)

	return 0;
}