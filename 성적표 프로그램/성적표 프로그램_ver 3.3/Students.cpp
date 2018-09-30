#include "Students.h"
#include "student.h"
#include <iostream>

using namespace std;

// ������
// List�� �����ڵ� ȣ���Ѵ�
Students::Students()
	// �̸��� ����ؼ� ȥ���� ���� ������ �̰��� ListŬ���� Ÿ���� ��� ������
	// �� �� ������ ��� ������ �����ڸ� ȣ���ϰ� �ִ� List��ü�� �����ڿ� ������ ���� �Լ��� �ּҸ� �Ѱ��ִ� �κ��̴�
	:students(&Students::DeleteData)
{
	TotalAve = 0.0f;
	NumverOfStudent = 0;
}

// �Ҹ���
Students::~Students()
{
	// ���� ���� ���� ����
}

// �л� �� �� �߰��Ѵ�
// ��ȯ�� : �� �̻� �Է��� �� ���� ��� false ��ȯ 
bool Students::AddStudent(bool hi_eng)
{
	// �л� ������ �´� ��ü�� �����Ѵ�
	// bool�� �μ��� ���� �����ϴ� ��ü�� �޶�����
	Student* std;
	if (hi_eng)
		std = new Student(NumverOfStudent + 1);
	else
		std = new EngStudent(NumverOfStudent + 1);

	// ���� ������ �Է¹޴´�
	// �������� ���ؼ� �˸��� ��ü�� ��� �Լ��� ȣ���Ѵ�
	std->Input();

	// ���� ���� ����ؼ� ���ο� ��ü ����� ����Ѵ�
	const int current = NumverOfStudent + 1; // ������� �Է� ���� �л� ��
	const int prev = NumverOfStudent; // ���� ������ �Է¹��� �л� ��

	TotalAve = (TotalAve*prev / current) + (std->GetAverage() / current);

	// �Է� ���� �л� ���� ������Ų��
	NumverOfStudent++;

	// student ����Ʈ�� �� ��带 �߰��Ѵ�
	students.InsertNodeAfter(students.GetTail(), std);

	return false;
}

// ��ü ������ �����ش�
void Students::ShowAll()
{
	// �Ǽ� ��� �ÿ� �Ҽ��� ���� �� �ڸ��� ǥ���ϰ� �Ѵ�
	cout.precision(2);
	cout << fixed;

	// Ÿ��Ʋ �κ��� ����Ѵ�
	cout << endl << "         < ��ü ���� ���� >" << endl;
	cout << "    �й�  �̸�  ����  ����  ����  ��޿���   ���" << endl;

	// ����Ʈ�� �ִ� ��� �л��� ������ ����Ѵ�
	Node* current = students.GetHead()->GetNext();

	while (current != students.GetHead())
	{
		// ���� ����� �����͸� �����´�
		const Student* std = (Student*)current->GetData();

		// ���� ���� ������ ����Ѵ�
		// �������� ���ؼ� ��ü Ÿ�Կ� �˸��� ��� �Լ��� ȣ���Ѵ�
		std->Show();

		// ���� ��带 ����Ų��
		current = current->GetNext();
	}

	cout << "\n��ü ��� = " << TotalAve << endl;
}

// ��ũ�� ����Ʈ�� ������ ���ſ� �Լ�
// ��ũ�� ����Ʈ�� ����� �����͸� ������ �� �� �Լ��� ȣ���Ѵ�
void Students::DeleteData(void * data)
{
	// Student ����ü�� �ٲ㼭 �����Ѵ�
	delete (Student*)data;
}
