#ifndef STUDENTS_H
#define STUDENTS_H

// 링크드 리스트를 사용한다
#include "List.h"

// 성적 정보를 관리하는 클래스
class Students
{
private:
	List students; // 링크드 리스트
	float TotalAve; // 전체 평균
	int NumverOfStudent; // 현재까지 입력한 학생 수

public:
	// 기존의 Setup()과 Teardown() 함수는 생성자와 소멸자로 대체했다
	// 이제 main()에서 시작과 종료 시에 따로 함수를 호출할 필요가 없게 되었다
	Students();
	~Students();

	// students.cpp 에서 대표적인 함수인 AddStudent() 와 ShowAll() 함수를 멤버 함수로 만들었다
	bool AddStudent(bool hi_eng);
	void ShowAll();

	// 이 함수의 주소를 List 객체의 생성자로 넘겨주려면 정적 멤버 함수가 되야 한다
	// 일반 멤버 함수로 만들면 다른 클래스에 주소를 넘겨줄 수 없다 함수의 포인터와 멤버 함수의 포인터는 서로 다른 타입이다
	static void DeleteData(void* data);
};

#endif // !STUDENTS_H

