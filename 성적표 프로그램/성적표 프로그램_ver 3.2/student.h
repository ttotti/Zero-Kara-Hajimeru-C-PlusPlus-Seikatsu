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
	void Input();
	void Show() const;

	// 접근자들
	// 멤버 변수의 값을 얻을수 있다
	int GetStdNumber() const;
	string GetName() const;
	int GetKor() const;
	int GetEng() const;
	int GetMath() const;
	float GetAverage() const;
};

#endif // !STUDENT_H
