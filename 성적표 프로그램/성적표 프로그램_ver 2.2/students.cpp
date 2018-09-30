#include "students.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// �� ���� �л��� ���� ������ ������ ����ü
struct Student
{
	int sNo;
	string name;
	int kor, eng, math;
	float ave;
};

const int MAX_STUDENTS = 100; // 100���� ������ ������ �� �ִ� �迭 ����
Student students[MAX_STUDENTS];

float TotalAve = 0.0f; // ��ü���
int Numberofstudent = 0; // ������� �Էµ� �л� ��

bool AddStudent()
{
	if (MAX_STUDENTS == Numberofstudent)
		return false;

	Student& std = students[Numberofstudent]; // �ҽ��ڵ带 �����ϰ� �ϱ� ���ؼ� ���۷����� ����Ų��

	std.sNo = Numberofstudent + 1;

	cout << "�̸�(�������) ���� ���� ���� ������ �Է��ϼ���: " << endl;
	cin >> std.name >> std.kor >> std.eng >> std.math;

	std.ave = float(std.kor + std.eng + std.math) / 3.0f;

	const int current = Numberofstudent + 1; // ������� �Է¹��� �л� ��
	const int prev = Numberofstudent; // ���� ������ �Է¹��� �л� ��

									  //TotalAve = (TotalAve + std.ave) / (Numberofstudent + 1);
	TotalAve = (TotalAve * prev / current) + (std.ave / current); // ��ü ��� ���ϴ� ��û�� ����

	Numberofstudent++;

	return true;
}

void ShowAll()
{
	cout.precision(2);
	cout << fixed;

	cout << endl << "         < ��ü ���� ���� >" << endl;
	cout << "    �й�  �̸�  ����  ����  ����   ���" << endl;
	for (int i = 0; i < Numberofstudent; i++)
	{
		const Student& std = students[i];

		cout << setw(8) << std.sNo << setw(7) << std.name << setw(5) << std.kor << setw(6) << std.eng << setw(6) << std.math << setw(7) << std.ave << endl;
	}

	cout << endl << "��ü���: " << TotalAve << endl;
	system("pause");
}