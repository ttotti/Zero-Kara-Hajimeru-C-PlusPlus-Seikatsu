#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// 한 명의 학생에 대한 정보를 보관할 구조체
struct Student
{
	int sNo;
	string name;
	int kor, eng, math;
	float ave;
};

int main() // 프로그램을 만들기 전 프로젝트의 뼈대를 먼저 만든다
{
	const int MAX_STUDENTS = 100; // 100명의 정보를 보관할 수 있는 배열 정의
	Student students[MAX_STUDENTS];

	float TotalAve = 0.0f; // 전체평균
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

			if (MAX_STUDENTS == Numberofstudent) // 100 명 모두 입력됐으면 무시
			{
				cout << endl << "더 이상 입력할 수 없습니다";
				break;
			}

			Student& std = students[Numberofstudent]; // 소스코드를 간결하게 하기 위해서 레퍼런스로 가리킨다

			std.sNo = Numberofstudent + 1;

			cout << "이름(공백없이) 국어 영어 수학 점수를 입력하세요: " << endl;
			cin >> std.name >> std.kor >> std.eng >> std.math;

			std.ave = float(std.kor + std.eng + std.math) / 3.0f;

			const int current = Numberofstudent + 1; // 현재까지 입력받은 학생 수
			const int prev = Numberofstudent; // 조금 전까지 입력받은 학생 수
			
			//TotalAve = (TotalAve + std.ave) / (Numberofstudent + 1);
			TotalAve = (TotalAve * prev / current) + (std.ave / current); // 전체 평균 구하는 엄청난 공식

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
			cout << "    학번  이름  국어  영어  수학   평균" << endl;
			for (int i = 0; i < Numberofstudent; i++)
			{
				const Student& std = students[i];

				cout << setw(8) << std.sNo << setw(7) << std.name << setw(5) << std.kor << setw(6) << std.eng << setw(6) << std.math << setw(7) << std.ave << endl;
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