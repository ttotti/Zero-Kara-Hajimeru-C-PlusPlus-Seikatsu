#ifndef STUDENTS_H
#define STUDENTS_H

// ��ũ�� ����Ʈ�� ����Ѵ�
#include "List.h"

// ���� ������ �����ϴ� Ŭ����
class Students
{
private:
	List students; // ��ũ�� ����Ʈ
	float TotalAve; // ��ü ���
	int NumverOfStudent; // ������� �Է��� �л� ��

public:
	// ������ Setup()�� Teardown() �Լ��� �����ڿ� �Ҹ��ڷ� ��ü�ߴ�
	// ���� main()���� ���۰� ���� �ÿ� ���� �Լ��� ȣ���� �ʿ䰡 ���� �Ǿ���
	Students();
	~Students();

	// students.cpp ���� ��ǥ���� �Լ��� AddStudent() �� ShowAll() �Լ��� ��� �Լ��� �������
	bool AddStudent(bool hi_eng);
	void ShowAll();

	// �� �Լ��� �ּҸ� List ��ü�� �����ڷ� �Ѱ��ַ��� ���� ��� �Լ��� �Ǿ� �Ѵ�
	// �Ϲ� ��� �Լ��� ����� �ٸ� Ŭ������ �ּҸ� �Ѱ��� �� ���� �Լ��� �����Ϳ� ��� �Լ��� �����ʹ� ���� �ٸ� Ÿ���̴�
	static void DeleteData(void* data);
};

#endif // !STUDENTS_H

