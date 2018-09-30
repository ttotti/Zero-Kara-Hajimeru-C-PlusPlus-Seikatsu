#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	string name;
	int sNo;

	Student(const string& name_arg, int stdNumber);
	~Student();

public:
	static int student_count; // ������� // ��������� ��ü������ �ƴ� Ŭ���� �����̴� // �� ���� Ŭ������ ��ü��� ��� ��ü���� �����ϴ� ����̴�
	static void PrintStdCount();

};

// ���� ��� ����
int Student::student_count = 0;

// ���� ��� �Լ�
void Student::PrintStdCount() // ���� ��� �Լ����� �Ϲ� ����� ������ �� ���� // ������ �Լ� �ȿ��� ��ü�� ����� �� ��ü�� ������� ������ �� �ִ�
{
	cout << "Student ��ü �� = " << student_count << endl;
}

Student::Student(const string& name_arg, int stdNumber)
{
	// �л��� ��ü�� ���� ������Ų�� 
	student_count++;

	name = name_arg;
	sNo = stdNumber;
}

Student::~Student()
{
	// �л� ��ü�� ���� ���ҽ�Ų��
	student_count--;
}

void Func()
{
	Student std1("Limttoitti", 354);
	Student std2("Limtaemin", 345);
	
	Student::PrintStdCount();
} // �Լ��� �����鼭 �Ҹ��ڰ� ȣ��ȴ�

int main()
{
	Student::PrintStdCount(); // Ŭ���� �ܺο��� static ��������� Ŭ���� �����̹Ƿ� (Ŭ�����̸�::�̸�) ���� �����Ѵ�

	Student std("Jeffrey", 123);

	Student::PrintStdCount();

	Func();

	Student::PrintStdCount();

	return 0;
}