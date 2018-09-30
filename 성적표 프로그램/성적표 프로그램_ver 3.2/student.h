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
	void Input();
	void Show() const;

	// �����ڵ�
	// ��� ������ ���� ������ �ִ�
	int GetStdNumber() const;
	string GetName() const;
	int GetKor() const;
	int GetEng() const;
	int GetMath() const;
	float GetAverage() const;
};

#endif // !STUDENT_H
