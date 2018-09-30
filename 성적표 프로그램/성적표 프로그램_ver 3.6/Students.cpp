#include "Students.h"
#include "student.h"
#include "BaseOutput.h"
#include "ConsoleOutput.h"
#include "HTMLOutput.h"
#include "TextOutput.h"
#include <sstream>
#include <iostream>
#include <memory> // ����Ʈ �����͸� ����ϱ� ���� �������

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
	Student* std = NULL;

	try 
	{
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
	}
	// Ÿ�Կ� ��� ���� ��� ���ܸ� �޴´�
	// �̷��� �ϸ� ���ܰ� �߻��� ��쿡�� �޸� ���� �߻����� �ʴ´�
	// ���� �߻��� ���� ��ü�� AddStudent() �Լ� ������ ������ ���޵ȴ�
	// ������ �� ����� �׷��� ���� ���� �� �ȴ� �̷� ��쿡�� ����Ʈ�����͸� ����ϴ� ���� �ξ� ������ ���� ����̴�
	catch (...)
	{
		// ���ܰ� �߻��� ��� std�� ������ �л� ��ü�� �����Ѵ�
		delete std;
		std = NULL;

		// ���ܸ� �ٽ� ������
		throw;
	}

	return false;
}

// ��ü ������ �����ش�
// ����� ���� �����ϴ� ���ڸ� �޴´�
// ���� ShowAll �Լ��� ����� �л����� ������ �������� �� �� �Ѵ�
// ���⼭ ������ ������ ���� ���信 �°� �ٸ������� ����ϰ� �ȴ�
void Students::ShowAll(FORMAT fmt)
{
	// ��� ���Ŀ� �´� ��ü�� �����Ѵ�
	// BaseOutput* out;

	// ���ܸ� ����ؼ� ����Ʈ �����͸� ����Ѵ�
	// �ҽ��� �����ϰ� �ϱ� ���� Ÿ���� ���� �����Ѵ�
	// ����Ʈ ������ Ÿ������ out ������ �����ߴ� // �������� BaseOutput* Ÿ���̿���
	typedef auto_ptr<BaseOutput> POUT;
	POUT out;

	// ��� ���Ŀ� �´� ��ü�� �����Ѵ�
	// fmt ������ ���� ���� ��ü�� �����ϰ� out������ �� �ּҸ� ��´�
	// �̶� POUT Ÿ������ ������� ����ȯ�� ���� �ʿ䰡 �ִ�
	if (TEXTFILE == fmt)
		out = (POUT) new TextOutput("report.txt");
	else if (HTMLFILE == fmt)
		out = (POUT) new HTMLOutput("report.html");
	else
		out = (POUT) new ConsoleOutput;

	// ����ǥ�� ����� �����Ѵ�
	out->BeginTable("< ��ü ���� ���� >");

	// ��� �κ��� ����Ѵ�
	string header[7] = { "�й�","�̸�","����","����","����","��޿���","���" };
	out->PutHeader(header, 7);

	// ����Ʈ�� �ִ� ��� �л��� ������ ����Ѵ�
	Node* current = students.GetHead()->GetNext();

	while (current != students.GetHead())
	{
		// ���� ����� �����͸� �����´�
		const Student* std = (Student*)current->GetData();

		// ���� ���� ������ ����Ѵ�
		// �������� ���ؼ� ��ü Ÿ�Կ� �˸��� ��� �Լ��� ȣ���Ѵ�
		std->Show(*out);

		// ���� ��带 ����Ų��
		current = current->GetNext();
	}

	// ����ǥ�� ����� ��ģ��
	out->EndTable();

	// ��ü ��� ������ �ϳ��� ���ڿ��� �����
	// stringstream Ŭ������ ���� ���ؼ� ������� <sstream> �߰��ؾ��Ѵ�
	// �ڼ��� ������ ���ͳݰ� å ����
	stringstream ss;
	ss.precision(2);
	ss << fixed;
	ss << "��ü ��� = " << TotalAve;

	// ��� ��ü�� ���ڿ��� ������
	out->Write(ss.str());

	// ��� ��ü�� �����Ѵ�
	// ������ ����Ʈ �����͸� ����� ���ܿ��� ������ �ڵ带 �������
	// �׷��⿡ ��� ��ü�� �����ϴ� �ڵ�� �ʿ����
	// delete out;
	// out = NULL;
}

// ��ũ�� ����Ʈ�� ������ ���ſ� �Լ�
// ��ũ�� ����Ʈ�� ����� �����͸� ������ �� �� �Լ��� ȣ���Ѵ�
void Students::DeleteData(void * data)
{
	// Student ����ü�� �ٲ㼭 �����Ѵ�
	delete (Student*)data;
}
