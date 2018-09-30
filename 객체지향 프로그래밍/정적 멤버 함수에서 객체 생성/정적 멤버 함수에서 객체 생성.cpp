#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	string name;
	int sNo;

	void Print();

private:
	Student(const string& name_arg, int stdNumber);

public:
	static int studentNumber; // �л��� ��ȣ�� �ڵ����� �ο��ϱ�����
	static Student* CreateStudent(const string& name_arg); // private �Ӽ��� �����ڸ� ��������Լ��� ���� �����ҷ����Ѵ�
};

int Student::studentNumber = 0;

Student* Student::CreateStudent(const string& name_arg)
{
	// private �Ӽ��� Ŭ���� ���ο��� ������ �����ϴ�
	// �װ� �̿��ؼ� ���� ��� �Լ��� ���� �Ҵ��� �� �� �ּҸ� ��ȯ�Ѵ�
	Student* p = new Student(name_arg, studentNumber++);

	return p;
}

Student::Student(const string& name_arg, int stdNumber)
{
	name = name_arg;
	sNo = stdNumber;
}

void Student::Print()
{
	cout << "(name = " << name << ", Std.Num. = " << sNo << ")" << endl;
}

int main()
{
	// �л� ��ü�� �� �� �����Ѵ�
	Student* p1, *p2, *p3;

	p1 = Student::CreateStudent("���¹�");
	p2 = Student::CreateStudent("������");
	p3 = Student::CreateStudent("������");

	p1->Print();
	p2->Print();
	p3->Print();

	// ��ü�� �������� ���������Ƿ� �������ش�
	delete p1;
	delete p2;
	delete p3;
	p1 = p2 = p3 = NULL;

	return 0;
}