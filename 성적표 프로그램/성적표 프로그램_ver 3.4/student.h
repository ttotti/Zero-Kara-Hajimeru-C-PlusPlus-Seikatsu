#ifndef STUDENT_H
#define STUDETN_H

#include <string>
#include "BaseOutput.h"

using namespace std;

// 한 명의 학생에 대한 정보를 관리할 클래스
class Student
{
protected:
	int sNo; // 학번
	string name; // 이름
	int kor, eng, math; // 국어, 영어, 수학 점수
	float ave; // 평균

public:
	// 생성자와 주요 멤버 함수 2개 선언
	Student(int sNo);
	// 하나 이상의 가상함수를 가지고 있으면 반드시 가상함수인 소멸자를 갖게 만들어야 한다
	virtual ~Student() {};
	virtual void Input();
	virtual void Show(BaseOutput& out) const;

	// 접근자들
	// 멤버 변수의 값을 얻을수 있다
	int GetStdNumber() const;
	string GetName() const;
	int GetKor() const;
	int GetEng() const;
	int GetMath() const;
	float GetAverage() const;
};

// 고급 영어를 듣는 학생에 대한 정보를 관리할 클래스
// Student 클래스를 상속 받는다
class EngStudent :public Student
{
	// 고급 영어 점수를 보관할 멤버 변수를 추가했다
protected:
	int hi_eng;

public:
	EngStudent(int sNo);
	// Input(), Show() 멤버함수를 오버라이드 했다
	virtual void Input();
	virtual void Show(BaseOutput& out) const;
};

#endif // !STUDENT_H
