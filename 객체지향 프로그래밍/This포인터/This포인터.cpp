#include <iostream>

using namespace std;

class WhoAmI
{
public:
	int id;

	WhoAmI(int id);
	void ShowTourseif() const;
	static void TestThis();
};

WhoAmI::WhoAmI(int id)
{
	// id = id_arg;
	// this �����ͷ� �̸��浹�� �ذ��Ҽ��ִ�
	// this->id �� ��������� �ǹ�
	// id �� �Ű�����(�μ�)�� �ǹ�
	this->id = id;
}

void WhoAmI::ShowTourseif() const
{
	// this�� �ڱ��ڽ��� ����Ų�� // ���������� ������ this�� ����� �ּҰ��� �����Ѵ�(this�� �ڱ��ڽ��� ���̹Ƿ� �ٲܼ����� �� const)
	// ����� �ƴ� �Լ��� This �����Ͱ� ����
	cout << "(ID = " << id << ", this = " << this << ")" << endl;
}

void WhoAmI::TestThis()
{
	// static ��������Լ����� this�� ����
	// This �����ʹ� ����Լ��� ������ ��ü�� ����Ű�°� �ε�
	// ��������Լ��� ��ü�� ������ �ƴϱ� ������ this �����Ͱ� ���� ���̴�
	// cout << "this = " << this << endl;
}

int main()
{
	WhoAmI obj1(1);
	WhoAmI obj2(2);
	WhoAmI obj3(3);

	obj1.ShowTourseif();
	obj2.ShowTourseif();
	obj3.ShowTourseif();

	cout << "&obj1 = " << &obj1 << endl;
	cout << "&obj2 = " << &obj2 << endl;
	cout << "&obj3 = " << &obj3 << endl;

	return 0;
}