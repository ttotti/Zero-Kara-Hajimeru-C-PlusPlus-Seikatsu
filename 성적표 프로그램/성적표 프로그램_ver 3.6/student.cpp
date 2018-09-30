#include "student.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits> // numeric_limits<streamsize>::max() 를 사용하기 위한 헤더파일

using namespace std;

// 생성자
// sNo : 학번
Student::Student(int sNo)
{
	// 학번 대입
	this->sNo = sNo;

	// 나머지 멤버 초기화
	kor = eng = math = 0;
	ave = 0.0f;
}

// 개인 정보를 입력 받는다
// 프로그램을 실행하고 메뉴에서 작업의 번호나 점수를 입력받을 때 cin 객체에 정수가 아닌 'a' 와 같은 문자가 입력되면
// 그 이후에 cin 객체는 우리의 요구를 무시한체 무한히 메뉴만 출력하거나 다른 오류가 일어나게 된다
// 그것은 쉽게말해 cin가 파업한 것이다
// cin 객체를 사용해서 정수 값을 입력 받을 때는 항상 이런 식으로 해주어야한다
// 자세한건 인터넷과 <스트림의 상태> 881p 를 참고한다
void Student::Input()
{
	// 정수 입력을 위한 반복
	// 올바른 입력이 들어올 때까지 반복한다
	while (1)
	{
		cout << "이름(공백없이) 국어, 영어, 수학 점수를 입력하세요 : " << endl;
		cin >> name >> kor >> eng >> math;

		// 문제가 없다면 반복을 끝낸다
		// 멤버 함수 good() 은 cin 객체의 상태를 점검하는 함수다
		// cin 객체가 파업 상태라면 false 를 반환한다
		if (cin.good())
			break;

		// 문제가 있다면 cin 객체를 초기화 한다
		// cin 객체가 파업 상태라면 다시 정상으로 되돌릴 필요가 있다
		// 멤버 함수 clear()는 파업 상태를 지우고 정상 상태로 만든다
		cin.clear();
		// 멤버함수 ignore()는 cin 객체에 입력한 값들을 지워버리는 함수다
		// 함수안에 인자로 넣어준 값은 모든 입력 값을 지우기 위해서 써준 것인데 일단 외워두자 // 헤더파일 <limits> 포함
		cin.ignore(numeric_limits<streamsize>::max()), '\n');

		// 안내 메시지를 출력한다
		cout << "[입력이 잘못되었습니다] \n";
	}

	// 개인 평균을 계산한다
	ave = float(kor + eng + math) / 3.0f;
}

// 개인 정보를 화면에 출력한다
void Student::Show(BaseOutput& out) const
{
	// 값을 모두 하나의 문자열로 만든다
	stringstream ss;
	ss.precision(2);
	ss << fixed;
	ss << sNo << " " << name << " " << kor << " " << eng << " " << math << " - " << ave;

	// 7개의 문자열을 가진 배열을 만들고 초기화 한다
	string record[7];
	for (int i = 0; i < 7; i++)
		ss >> record[i];

	// 출력 객체에 보낸다
	out.PutRecord(record);
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

// 생성자
EngStudent::EngStudent(int sNo)
	:Student(sNo)
{
	hi_eng = 0;
}

void EngStudent::Input()
{
	while (1)
	{
		cout << "이름(공백없이) 국어, 영어, 수학, 고급영어 점수를 입력하세요 : " << endl;
		cin >> name >> kor >> eng >> math >> hi_eng;

		if (cin.good())
			break;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "[입력이 잘못되었습니다] \n";
	}
	// 개인 평균을 계산한다
	ave = float(kor + eng + math+hi_eng) / 4.0f;
}

void EngStudent::Show(BaseOutput& out) const
{
	// 값을 모두 하나의 문자열로 만든다.
	stringstream ss;
	ss.precision(2);
	ss << fixed;
	ss << sNo << " " << name << " " << kor << " ";
	ss << eng << " " << math << " " << hi_eng << " " << ave;

	// 7개의 문자열을 가진 배열을 만들고 초기화한다.
	string record[7];
	for (int i = 0; i < 7; ++i)
		ss >> record[i];

	// 출력 객체에 보낸다.
	out.PutRecord(record);
}
