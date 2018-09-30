#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	string name;
	int sNo;

	Student(const string& name_arg, int stdNumber);
	~Student();

public:
	static int student_count; // 정적멤버 // 정적멤버는 객체소유가 아닌 클래스 소유이다 // 즉 같은 클래스의 객체라면 모든 객체에서 공유하는 멤버이다
	static void PrintStdCount();

};

// 정적 멤버 변수
int Student::student_count = 0;

// 정적 멤버 함수
void Student::PrintStdCount() // 정적 멤버 함수에서 일반 멤버에 접근할 수 없다 // 하지만 함수 안에서 객체를 만들고 그 객체의 멤버에는 접근할 수 있다
{
	cout << "Student 객체 수 = " << student_count << endl;
}

Student::Student(const string& name_arg, int stdNumber)
{
	// 학생의 객체의 수를 증가시킨다 
	student_count++;

	name = name_arg;
	sNo = stdNumber;
}

Student::~Student()
{
	// 학생 객체의 수를 감소시킨다
	student_count--;
}

void Func()
{
	Student std1("Limttoitti", 354);
	Student std2("Limtaemin", 345);
	
	Student::PrintStdCount();
} // 함수가 끝나면서 소멸자가 호출된다

int main()
{
	Student::PrintStdCount(); // 클래스 외부에서 static 정적멤버는 클래스 소유이므로 (클래스이름::이름) 으로 접근한다

	Student std("Jeffrey", 123);

	Student::PrintStdCount();

	Func();

	Student::PrintStdCount();

	return 0;
}