#include <iostream>

using namespace std;

void A();
void B();
void C();

int main()
{
	try
	{
		A();
	}
	catch(int i)
	{
		cout << "���� = " << i << endl;
	}
	catch (char* c) // catch�� ������ �����ִ� // ��ü�� ����ؼ� ��Ȳ�� �°� catch���� ���� �ִ� // throw���� �Ѿ�� Ÿ�Կ� �´� catch�� ������ �ȴ�
	{
		cout << "B() ���� �����߻�!" << c << endl;
	}

	return 0;
}

void A()
{
	cout << "A() ����" << endl;
	B();
	cout << "A() ��" << endl;
}

void B()
{
	throw " ���־�!!";

	C();
}

void C()
{
	// ���ܴ� �Լ��� �ǳ� �پ���� ���޵ȴ�
	// �� �ڿ� ȣ��Ǿ��� �Լ��� ��� ������ �����ִ����� ���ʴ�� ����ǰ�
	// ���ܴ� �ڽ��� Ÿ�Կ� �´� catch ����� ã�� ������ �Լ��� �Ž��� �ö󰣴� (�� ã���� ������ �����ع�����)
	throw 332;
}