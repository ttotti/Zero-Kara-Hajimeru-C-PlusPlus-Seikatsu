#include "student.h"
#include <iostream>
#include <iomanip>

using namespace std;

// ������
// sNo : �й�
Student::Student(int sNo)
{
	// �й� ����
	this->sNo = sNo;

	// ������ ��� �ʱ�ȭ
	kor = eng = math = 0;
	ave = 0.0f;
}

// ���� ������ �Է� �޴´�
void Student::Input()
{
	cout << "�̸�(�������) ����, ����, ���� ������ �Է��ϼ��� : " << endl;
	cin >> name >> kor >> eng >> math;

	// ���� ����� ����Ѵ�
	ave = float(kor + eng + math) / 3.0f;
}

// ���� ������ ȭ�鿡 ����Ѵ�
void Student::Show() const
{
	cout << setw(8) << sNo << setw(7) << name 
		<< setw(5) << kor << setw(6) << eng 
		<< setw(6) << math << setw(7) << ave << endl;
}

int Student::GetStdNumber() const
{
	return sNo;
}

string Student::GetName() const
{
	return name;
}

int Student::GetKor() const
{
	return kor;
}

int Student::GetEng() const
{
	return eng;
}

int Student::GetMath() const
{
	return math;
}

float Student::GetAverage() const
{
	return ave;
}

//------------------------------------------
// EngStudent
//------------------------------------------

// ������
EngStudent::EngStudent(int sNo)
	:Student(sNo)
{
	hi_eng = 0;
}

void EngStudent::Input()
{
	cout << "�̸�(�������) ����, ����, ����, ��޿��� ������ �Է��ϼ��� : " << endl;
	cin >> name >> kor >> eng >> math >> hi_eng;

	// ���� ����� ����Ѵ�
	ave = float(kor + eng + math+hi_eng) / 4.0f;
}

void EngStudent::Show() const
{
	cout << setw(8) << sNo << setw(7) << name
		<< setw(5) << kor << setw(6) << eng
		<< setw(6) << math << setw(7) << hi_eng
		<< setw(7) << ave << endl;
}
