#include "students.h"
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

const int MAX_STUDENTS = 100; // 100명의 정보를 보관할 수 있는 배열 정의
Student students[MAX_STUDENTS];

float TotalAve = 0.0f; // 전체평균
int Numberofstudent = 0; // 현재까지 입력된 학생 수

bool AddStudent()
{
	if (MAX_STUDENTS == Numberofstudent)
		return false;

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

	return true;
}

void ShowAll()
{
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
	system("pause");
}