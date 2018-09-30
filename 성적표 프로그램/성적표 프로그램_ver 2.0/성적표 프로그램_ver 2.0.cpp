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

int main() // ���α׷��� ����� �� ������Ʈ�� ���븦 ���� �����
{
	const int MAX_STUDENTS = 100; // 100���� ������ ������ �� �ִ� �迭 ����
	Student students[MAX_STUDENTS];

	float TotalAve = 0.0f; // ��ü���
	int Numberofstudent = 0; // ������� �Էµ� �л� ��

	while (1)
	{
		cout << "\n------ �޴� ------\n";
		cout << "1. �л� ���� �߰�\n";
		cout << "2. ��ü ���� ����" << endl;
		cout << "Q. ���α׷� ����" << endl;
		cout << "-----------------" << endl;
		cout << "���ϴ� �۾��� ��ȣ�� �Է��Ͻÿ�: ";

		char select;
		cin >> select;

		switch (select)
		{
		case '1':
		{
			cout << endl << "�л� ���� �߰��� ���õǾ����ϴ�" << endl;

			if (MAX_STUDENTS == Numberofstudent) // 100 �� ��� �Էµ����� ����
			{
				cout << endl << "�� �̻� �Է��� �� �����ϴ�";
				break;
			}

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

			cout << endl << "�л� ������ �ùٸ��� �ԷµǾ����ϴ�" << endl;

			break;
		}
		case '2':
		{
			cout << endl << "��ü ���� ���Ⱑ ���õǾ����ϴ�" << endl;

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

			break;
		}
		case 'Q':
		case 'q':
			cout << endl << "���α׷��� �����մϴ�" << endl;
			return 0;
		default:
			cout << endl << "�ùٸ� ������ ���ּ���!" << endl;
			break;
		}
	}

	return 0;
}