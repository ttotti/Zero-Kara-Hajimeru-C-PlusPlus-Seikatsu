#ifndef STUDENT_H
#define STUDETN_H

#include <string>

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
	virtual void Show() const;

	// 접근자들
	// 멤버 변수의 값을 얻을수 있다
	int GetStdNumber() const;
	string GetName() const;
	int GetKor() const;
	int GetEng() const;
	int GetMath() const;
	float GetAverage() const;
};

// 상속과 다형성이 프로그램을 유지 보수하는데 많은 도움이 된다
// 처음부터 고급영어의 클래스를 만들어 붙이는거보다 상속과 다형성을 이용하면 손쉽게 만들수있다
// 왜냐하면 기존에 있는거에서 고급영어가 늘었을뿐이기 때문이다

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
	virtual void Show() const;
};

#endif // !STUDENT_H
