#include <iostream>

using namespace std;

void A();
void B();

int main()
{
	try
	{
		A();
	}
	catch (const char* ex)
	{
		cout << "���� ���� : " << ex << endl;
	}

	return 0;
}

void A()
{
	char* p = new char(100);

	cout << "���ܰ� �߻��ϱ� ��";

	B(); // ���⼭ ���ܰ� �߻��ϰ� A�Լ��� �ٷ� ������ catch�� �Ѿ��

	cout << "���ܰ� �߻��� ��" << endl;

	// ������ ���ܰ� �߻��� ���������� �������ϰ� A�Լ��� ����ȴ�
	// �̷��� �޸𸮰� ���������� ������ �޸𸮰� ���� ��Ȳ�� �Ͼ�µ� �̰� �޸� �� �̶�� �Ѵ�
	delete[] p;
	p = NULL;
}

void B()
{
	throw "Exception!!";
}