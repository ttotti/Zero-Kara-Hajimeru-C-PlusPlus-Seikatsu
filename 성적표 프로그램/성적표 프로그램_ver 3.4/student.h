#ifndef STUDENT_H
#define STUDETN_H

#include <string>
#include "BaseOutput.h"

using namespace std;

// �� ���� �л��� ���� ������ ������ Ŭ����
class Student
{
protected:
	int sNo; // �й�
	string name; // �̸�
	int kor, eng, math; // ����, ����, ���� ����
	float ave; // ���

public:
	// �����ڿ� �ֿ� ��� �Լ� 2�� ����
	Student(int sNo);
	// �ϳ� �̻��� �����Լ��� ������ ������ �ݵ�� �����Լ��� �Ҹ��ڸ� ���� ������ �Ѵ�
	virtual ~Student() {};
	virtual void Input();
	virtual void Show(BaseOutput& out) const;

	// �����ڵ�
	// ��� ������ ���� ������ �ִ�
	int GetStdNumber() const;
	string GetName() const;
	int GetKor() const;
	int GetEng() const;
	int GetMath() const;
	float GetAverage() const;
};

// ��� ��� ��� �л��� ���� ������ ������ Ŭ����
// Student Ŭ������ ��� �޴´�
class EngStudent :public Student
{
	// ��� ���� ������ ������ ��� ������ �߰��ߴ�
protected:
	int hi_eng;

public:
	EngStudent(int sNo);
	// Input(), Show() ����Լ��� �������̵� �ߴ�
	virtual void Input();
	virtual void Show(BaseOutput& out) const;
};

#endif // !STUDENT_H
