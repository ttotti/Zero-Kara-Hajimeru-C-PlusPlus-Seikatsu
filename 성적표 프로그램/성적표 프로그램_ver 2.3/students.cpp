#include "students.h"
#include "List.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Student
{
	int sNo;
	string name;
	int kor, eng, math;
	float ave;

	~Student()
	{
		cout << "Student::~Student()" << endl;
	}
};

List* students = NULL;

float TotalAve = 0.0f; // ��ü���
int Numberofstudent = 0; // ������� �Էµ� �л� ��

bool AddStudent()
{
	Student* std = new Student; // ��ũ�� ����Ʈ�� �����ϱ� ���� ������ �ϳ� �����Ҵ� ���ش�

	std->sNo = Numberofstudent + 1;

	cout << "�̸�(�������) ���� ���� ���� ������ �Է��ϼ���: " << endl;
	cin >> std->name >> std->kor >> std->eng >> std->math;

	std->ave = float(std->kor + std->eng + std->math) / 3.0f;

	const int current = Numberofstudent + 1; // ������� �Է¹��� �л� ��
	const int prev = Numberofstudent; // ���� ������ �Է¹��� �л� ��

	TotalAve = (TotalAve * prev / current) + (std->ave / current); // ��ü ��� ���ϴ� ��û�� ����

	Numberofstudent++;

	InsertNodeAfter(GetTail(students), std); // ����Ʈ�� �� ��带 �߰��Ѵ�

	return true;
}

void ShowAll()
{
	cout.precision(2);
	cout << fixed;

	cout << endl << "         < ��ü ���� ���� >" << endl;
	cout << "    �й�  �̸�  ����  ����  ����   ���" << endl;

	// ����Ʈ�� �ִ� ��� �л��� ������ ����Ѵ�
	Node* current = students->head->next; // ��� ����� ���� ������ Ž���� �����Ѵ�
	while (current != students->head) // �ѹ����� ����
	{
		// ���� ����� �����͸� �����´�
		const Student* std = (Student*)GetData(current);

		// ���
		cout << setw(8) << std->sNo << setw(7) << std->name << setw(5) << std->kor << setw(6) << std->eng << setw(6) << std->math << setw(7) << std->ave << endl;

		// ���� ��带 ����Ų��
		current = GetNext(current);
	}

	cout << endl << "��ü���: " << TotalAve << endl;
	system("pause");
}

// �ʱ�ȭ�Ѵ�
void Setup()
{
	// ����Ʈ�� �����Ѵ�
	students = CreateList();
}

// ����� ���ҽ��� �����Ѵ�
void Teardown()
{
	// ����Ʈ�� �����Ѵ�
	RemoveList(students, true);
}