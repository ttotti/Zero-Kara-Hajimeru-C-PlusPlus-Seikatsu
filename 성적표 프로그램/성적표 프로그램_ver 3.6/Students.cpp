#include "Students.h"
#include "student.h"
#include "BaseOutput.h"
#include "ConsoleOutput.h"
#include "HTMLOutput.h"
#include "TextOutput.h"
#include <sstream>
#include <iostream>
#include <memory> // 스마트 포인터를 사용하기 위한 헤더파일

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
	Student* std = NULL;

	try 
	{
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
	}
	// 타입에 상관 없이 모든 예외를 받는다
	// 이렇게 하면 예외가 발생한 경우에도 메모리 릭은 발생하지 않는다
	// 또한 발생한 예외 객체도 AddStudent() 함수 밖으로 고스한히 전달된다
	// 하지만 이 방법은 그렇게 좋은 것이 못 된다 이런 경우에는 스마트포인터를 사용하는 것이 훨씬 권장할 만한 방법이다
	catch (...)
	{
		// 예외가 발생한 경우 std에 보관한 학생 객체를 제거한다
		delete std;
		std = NULL;

		// 예외를 다시 던진다
		throw;
	}

	return false;
}

// 전체 성적을 보여준다
// 출력할 곳을 지정하는 인자를 받는다
// 이제 ShowAll 함수는 출력할 학생들의 정보를 가져오는 일 만 한다
// 여기서 가져온 정보로 각각 포멧에 맞게 다른곳에서 출력하게 된다
void Students::ShowAll(FORMAT fmt)
{
	// 출력 형식에 맞는 객체를 생성한다
	// BaseOutput* out;

	// 예외를 대비해서 스마트 포인터를 사용한다
	// 소스를 간결하게 하기 위해 타입을 새로 정의한다
	// 스마트 포인터 타입으로 out 변수를 정의했다 // 기존에는 BaseOutput* 타입이였다
	typedef auto_ptr<BaseOutput> POUT;
	POUT out;

	// 출력 형식에 맞는 객체를 생성한다
	// fmt 인자의 값에 따라서 객체를 생성하고 out변수에 그 주소를 담는다
	// 이때 POUT 타입으로 명시적인 형변환을 해줄 필요가 있다
	if (TEXTFILE == fmt)
		out = (POUT) new TextOutput("report.txt");
	else if (HTMLFILE == fmt)
		out = (POUT) new HTMLOutput("report.html");
	else
		out = (POUT) new ConsoleOutput;

	// 성적표의 출력을 시작한다
	out->BeginTable("< 전체 성적 보기 >");

	// 헤더 부분을 출력한다
	string header[7] = { "학번","이름","국어","영어","수학","고급영어","평균" };
	out->PutHeader(header, 7);

	// 리스트에 있는 모든 학생의 정보를 출력한다
	Node* current = students.GetHead()->GetNext();

	while (current != students.GetHead())
	{
		// 현재 노드의 데이터를 꺼내온다
		const Student* std = (Student*)current->GetData();

		// 개인 성적 정보를 출력한다
		// 다형성에 의해서 객체 타입에 알맞은 멤버 함수를 호출한다
		std->Show(*out);

		// 다음 노드를 가리킨다
		current = current->GetNext();
	}

	// 성적표의 출력을 마친다
	out->EndTable();

	// 전체 평균 정보를 하나의 문자열로 만든다
	// stringstream 클래스를 쓰기 위해서 헤더파일 <sstream> 추가해야한다
	// 자세한 정보는 인터넷과 책 참고
	stringstream ss;
	ss.precision(2);
	ss << fixed;
	ss << "전체 평균 = " << TotalAve;

	// 출력 객체에 문자열을 보낸다
	out->Write(ss.str());

	// 출력 객체를 제거한다
	// 위에서 스마트 포인터를 사용해 예외에서 안전한 코드를 만들었다
	// 그렇기에 출력 객체를 해제하던 코드는 필요없다
	// delete out;
	// out = NULL;
}

// 링크드 리스트의 데이터 제거용 함수
// 링크드 리스트가 노드의 데이터를 제거할 때 이 함수를 호출한다
void Students::DeleteData(void * data)
{
	// Student 구조체를 바꿔서 제거한다
	delete (Student*)data;
}
