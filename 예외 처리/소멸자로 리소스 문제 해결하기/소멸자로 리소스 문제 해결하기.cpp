#include <iostream>

using namespace std;

// ����Ʈ ������ Ŭ����
// C++ ������ �̷� �뵵�� ����Ʈ�����͸� �̹� �����ϰ��ִ�
// �̰Ŷ� ����� ������ ���ư����� �����δ� �� ���� ����� �����Ѵ� (�ڼ��Ѱ� http://boost.org �� ����)
class SmartPointer
{
public:
	const char* ptr; // �� Ŭ�������� �����͸� �����Ҽ��ִ� ��� ������ ����
public:
	SmartPointer(char* p)
		:ptr(p)
	{}

	~SmartPointer() // �Ҹ��ڿ��� ��� ���� ptr�� ������ ���� ����ؼ� �޸𸮸� �����Ѵ� // �Ҹ��ڴ� �ݵ�� ȣ��ȴٴ� ���� ���
	{
		cout << "�޸𸮰� �����ȴ�(�Ҹ��� ȣ��)\n" << endl;

		delete[] ptr;
	}
};

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

	// �޸𸮸� ����Ʈ �����Ϳ� �����Ѵ�
	// �� ����Ʈ�������� ��ü�� A�Լ��� �����ϹǷ� A�Լ��� ����Ǹ� ��ü�� ���� ������� �׷��Ƿ� ��ü�� �Ҹ��ڰ� ȣ��ȴ�
	SmartPointer sp(p);

	cout << "���ܰ� �߻��ϱ� ��\n";

	B(); // ���⼭ ���ܰ� �߻��ϰ� A�Լ��� �ٷ� ������ catch�� �Ѿ��

	cout << "���ܰ� �߻��� ��" << endl;

	// �޸𸮸� ���� �������� �ʿ䰡 ����
	/*delete[] p;
	p = NULL;*/
}

void B()
{
	throw "Exception!!";
}