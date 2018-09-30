#include <iostream>

using namespace std;

union MyUnion // ����ü ����ü�� ����ϰ� �������� ��� ����� ���� �޸� ������ �ڸ���´�
{
	int i;
	void* p;
	char c;
};

int main()
{
	MyUnion uni; // ���� ������ ����ϱ⶧���� ����ü�� ũ��� ����� ���� ũ�Ⱑ ū ����� ũ��� ��������

	cout << "&uni.i = " << &uni.i << endl; // �ΰ��� ����� �ּҰ� ����
	cout << "&uni.p = " << &uni.p << endl;

	uni.i = 0x12345678; // �� ����� ���� ������ �ٸ� ������� ������ ��ģ��
	cout << hex;
	cout << "uni.i = " << uni.i << endl;
	cout << "uni.p = " << uni.p << endl;

	uni.p = (void*)0x87654321; // �̰Ͷ��� �ٸ� ����� ������ ��ģ��
	cout << "uni.i = " << uni.i << endl;
	cout << "uni.p = " << uni.p << endl;


	uni.i = 0x12345678;
	uni.c = 0x90;
	cout << "uni.i = " << uni.i << endl;
	cout << "uni.c = " << (int)uni.c << endl;

	return 0;
}