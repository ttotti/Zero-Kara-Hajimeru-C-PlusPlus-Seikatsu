#include <iostream>

using namespace std;

// void �����ʹ� ���� �ּҸ� �����ϴ� �뵵�θ� ����Ѵ�
int main()
{
	double i = 400.0;
	void* pv = &i; // void �����ʹ� �ƹ�Ÿ���̳� ����ų �� �ֱ� ������ ����ȯ���̵� ���� �����Ҽ��ִ� ������ Ÿ���� �𸣱⿡ ����Ҽ�����

	int* pi = (int*)pv; // �׷��⿡ ����ȯ�� ���ؼ� �ٸ� ������ ������ ���� �����Ѵ�

	cout << "pv�� ������: " << sizeof(pv) << endl;
	cout << "pi�� ������: " << sizeof(pi) << endl;

	return 0;
}