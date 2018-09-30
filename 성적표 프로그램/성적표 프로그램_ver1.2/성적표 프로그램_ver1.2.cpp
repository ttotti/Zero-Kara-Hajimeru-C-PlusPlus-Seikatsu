#include <iostream>
#include <iomanip>

using namespace std;

int main() // ���α׷��� ����� �� ������Ʈ�� ���븦 ���� �����
{
	int s1_No, s2_No, s3_No; //�й�
	int s1_Kor, s2_Kor, s3_Kor; // �����
	int s1_Math, s2_Math, s3_Math; // ���м���
	int s1_Eng, s2_Eng, s3_Eng; // �����
	float s1_Avg, s2_Avg, s3_Avg; //�������
	float TotalAve; // ��ü���
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

			if (3 == Numberofstudent)
			{
				cout << endl << "�� �̻� �Է��� �� �����ϴ�";
				break;
			}

			int kor, eng, math;
			cin >> kor >> eng >> math;

			float avg = (kor + eng + math) / 3.0f;

			if (0 == Numberofstudent)
			{
				s1_No = Numberofstudent + 1;
				s1_Kor = kor;
				s1_Eng = eng;
				s1_Math = math;
				s1_Avg = avg;

				TotalAve = s1_Avg;
			}
			else if (1 == Numberofstudent)
			{
				s2_No = Numberofstudent + 1;
				s2_Kor = kor;
				s2_Eng = eng;
				s2_Math = math;
				s2_Avg = avg;

				TotalAve = (s1_Avg + s2_Avg) / (float)Numberofstudent;
			}
			else if (2 == Numberofstudent)
			{
				s3_No = Numberofstudent + 1;
				s3_Kor = kor;
				s3_Eng = eng;
				s3_Math = math;
				s3_Avg = avg;

				TotalAve = (s1_Avg + s2_Avg + s3_Avg) / (float)Numberofstudent;
			}

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
			cout << "    �й�  ����  ����  ����   ���" << endl;
			for (int i = 0; i < Numberofstudent; i++)
			{
				if (0 == i)
				{
					cout << setw(8) << s1_No << setw(6) << s1_Kor << setw(6) << s1_Eng << setw(6) << s1_Math << setw(7) << s1_Avg << endl;
				}
				else if (1 == i)
				{
					cout << setw(8) << s2_No << setw(6) << s2_Kor << setw(6) << s2_Eng << setw(6) << s2_Math << setw(7) << s2_Avg << endl;
				}
				else if (2 == i)
				{
					cout << setw(8) << s3_No << setw(6) << s3_Kor << setw(6) << s3_Eng << setw(6) << s3_Math << setw(7) << s3_Avg << endl;
				}
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