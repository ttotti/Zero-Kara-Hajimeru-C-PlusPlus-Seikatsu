#include "Students.h"
#include "student.h"
#include <iostream>

using namespace std;

// 생성자
// List의 생성자도 호출한다
Students::Students()
	// 이름이 비슷해서 혼동할 수도 있지만 이것은 List클래스 타입의 멤버 변수다
	// 즉 이 문장은 멤버 변수의 생성자를 호출하고 있다 List객체의 생성자에 데이터 제거 함수의 주소를 넘겨주는 부분이다
	:students(&Students::DeleteData)
{
	TotalAve = 0.0f;
	NumverOfStudent = 0;
}

// 소멸자
Students::~Students()
{
	// 따로 해줄 것이 없다
}

// 학생 한 명 추가한다
// 반환값 : 더 이상 입력할 수 없는 경우 false 반환 
bool Students::AddStudent(bool hi_eng)
{
	// 학생 종류에 맞는 객체를 생성한다
	// bool값 인수에 따라서 생성하는 객체가 달라진다
	Student* std;
	if (hi_eng)
		std = new Student(NumverOfStudent + 1);
	else
		std = new EngStudent(NumverOfStudent + 1);

	// 개인 정보를 입력받는다
	// 다형성에 의해서 알맞은 객체의 멤버 함수를 호출한다
	std->Input();

	// 기존 값을 사용해서 새로운 전체 평균을 계산한다
	const int current = NumverOfStudent + 1; // 현재까지 입력 받은 학생 수
	const int prev = NumverOfStudent; // 조금 전까지 입력받은 학생 수

	TotalAve = (TotalAve*prev / current) + (std->GetAverage() / current);

	// 입력 받은 학생 수를 증가시킨다
	NumverOfStudent++;

	// student 리스트에 새 노드를 추가한다
	students.InsertNodeAfter(students.GetTail(), std);

	return false;
}

// 전체 성적을 보여준다
void Students::ShowAll()
{
	// 실수 출력 시에 소수점 이하 두 자리만 표시하게 한다
	cout.precision(2);
	cout << fixed;

	// 타이틀 부분을 출력한다
	cout << endl << "         < 전체 성적 보기 >" << endl;
	cout << "    학번  이름  국어  영어  수학  고급영어   평균" << endl;

	// 리스트에 있는 모든 학생의 정보를 출력한다
	Node* current = students.GetHead()->GetNext();

	while (current != students.GetHead())
	{
		// 현재 노드의 데이터를 꺼내온다
		const Student* std = (Student*)current->GetData();

		// 개인 성적 정보를 출력한다
		// 다형성에 의해서 객체 타입에 알맞은 멤버 함수를 호출한다
		std->Show();

		// 다음 노드를 가리킨다
		current = current->GetNext();
	}

	cout << "\n전체 평균 = " << TotalAve << endl;
}

// 링크드 리스트의 데이터 제거용 함수
// 링크드 리스트가 노드의 데이터를 제거할 때 이 함수를 호출한다
void Students::DeleteData(void * data)
{
	// Student 구조체를 바꿔서 제거한다
	delete (Student*)data;
}
