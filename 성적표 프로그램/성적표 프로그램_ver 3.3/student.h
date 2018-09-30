#ifndef STUDENT_H
#define STUDETN_H

#include <string>

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
	virtual void Show() const;

	// �����ڵ�
	// ��� ������ ���� ������ �ִ�
	int GetStdNumber() const;
	string GetName() const;
	int GetKor() const;
	int GetEng() const;
	int GetMath() const;
	float GetAverage() const;
};

// ��Ӱ� �������� ���α׷��� ���� �����ϴµ� ���� ������ �ȴ�
// ó������ ��޿����� Ŭ������ ����� ���̴°ź��� ��Ӱ� �������� �̿��ϸ� �ս��� ������ִ�
// �ֳ��ϸ� ������ �ִ°ſ��� ��޿�� �þ������̱� �����̴�

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
	virtual void Show() const;
};

#endif // !STUDENT_H
