#include <iostream>
#include <iomanip>

using namespace std;

int main() // 프로그램을 만들기 전 프로젝트의 뼈대를 먼저 만든다
{
	int s1_No, s2_No, s3_No; //학번
	int s1_Kor, s2_Kor, s3_Kor; // 국어성적
	int s1_Math, s2_Math, s3_Math; // 수학성적
	int s1_Eng, s2_Eng, s3_Eng; // 영어성적
	float s1_Avg, s2_Avg, s3_Avg; //개인평균
	float TotalAve; // 전체평균
	int Numberofstudent = 0; // 현재까지 입력된 학생 수

	while (1)
	{
		cout << "\n------ 메뉴 ------\n";
		cout << "1. 학생 성적 추가\n";
		cout << "2. 전체 성적 보기" << endl;
		cout << "Q. 프로그램 종료" << endl;
		cout << "-----------------" << endl;
		cout << "원하는 작업의 번호를 입력하시오: ";

		char select;
		cin >> select;

		switch (select)
		{
		case '1':
		{
			cout << endl << "학생 성적 추가가 선택되었습니다" << endl;

			if (3 == Numberofstudent)
			{
				cout << endl << "더 이상 입력할 수 없습니다";
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

			cout << endl << "학생 성적이 올바르게 입력되었습니다" << endl;

			break;
		}
		case '2':
		{
			cout << endl << "전체 성적 보기가 선택되었습니다" << endl;

			cout.precision(2);
			cout << fixed;

			cout << endl << "         < 전체 성적 보기 >" << endl;
			cout << "    학번  국어  영어  수학   평균" << endl;
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

			cout << endl << "전체평균: " << TotalAve << endl;

			break;
		}
		case 'Q':
		case 'q':
			cout << endl << "프로그램을 종료합니다" << endl;
			return 0;
		default:
			cout << endl << "올바른 선택을 해주세요!" << endl;
			break;
		}
	}

	return 0;
}