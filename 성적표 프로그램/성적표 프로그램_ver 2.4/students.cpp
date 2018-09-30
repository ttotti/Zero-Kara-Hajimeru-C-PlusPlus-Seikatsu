#include "students.h"
#include "List.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Student
{
	int sNo;
	string name;
	int kor, eng, math;
	float ave;

	~Student()
	{
		cout << "Student::~Student()" << endl;
	}
};

List* students = NULL;

float TotalAve = 0.0f; // 전체평균
int Numberofstudent = 0; // 현재까지 입력된 학생 수

bool AddStudent()
{
	Student* std = new Student; // 링크드 리스트에 보관하기 위해 변수를 하나 동적할당 해준다

	std->sNo = Numberofstudent + 1;

	cout << "이름(공백없이) 국어 영어 수학 점수를 입력하세요: " << endl;
	cin >> std->name >> std->kor >> std->eng >> std->math;

	std->ave = float(std->kor + std->eng + std->math) / 3.0f;

	const int current = Numberofstudent + 1; // 현재까지 입력받은 학생 수
	const int prev = Numberofstudent; // 조금 전까지 입력받은 학생 수

	TotalAve = (TotalAve * prev / current) + (std->ave / current); // 전체 평균 구하는 엄청난 공식

	Numberofstudent++;

	InsertNodeAfter(GetTail(students), std); // 리스트에 새 노드를 추가한다

	return true;
}

void ShowAll()
{
	cout.precision(2);
	cout << fixed;

	cout << endl << "         < 전체 성적 보기 >" << endl;
	cout << "    학번  이름  국어  영어  수학   평균" << endl;

	// 리스트에 있는 모든 학생의 정보를 출력한다
	Node* current = students->head->next; // 헤드 노드의 다음 노드부터 탐색을 시작한다
	while (current != students->head) // 한바퀴를 돈다
	{
		// 현재 노드의 데이터를 꺼내온다
		const Student* std = (Student*)GetData(current);

		// 출력
		cout << setw(8) << std->sNo << setw(7) << std->name << setw(5) << std->kor << setw(6) << std->eng << setw(6) << std->math << setw(7) << std->ave << endl;

		// 다음 노드를 가리킨다
		current = GetNext(current);
	}

	cout << endl << "전체평균: " << TotalAve << endl;
	system("pause");
}

// 링크드 리스트의 데이터 제거용 함수
// 링크드 리스트가 노드의 데이터를 제거 할 때 이 함수를 호출한다
void DeleteData(void* data) // data인자를 통해 해제하려는 데이터를 전달한다
{
	// Student 구조체를 바꿔서 제거한다
	delete (Student*)data; // Student 타입으로 형변환해서 해제한다 이렇게 하면 소멸자가 올바르게 호출된다
}

// 초기화한다
// 이 함수는 main() 함수에 의해서 프로그램이 시작될 때 호출한다
void Setup()
{
	// 리스트를 생성한다
	// 데이터 제거 함수를 인자로 넘겨준다
	// 링크드 리스트를 생성할 때 앞에서 만든 DeleteData() 함수의 주소를 넘겨준다
	// 링크드 리스트는 함수의 포인터를 사용해서 이 주소를 보관해둘 것이다
	students = CreateList(&DeleteData);
}

// 사용한 리소스를 정리한다
void Teardown()
{
	// 리스트를 정리한다
	RemoveList(students, true);
}
