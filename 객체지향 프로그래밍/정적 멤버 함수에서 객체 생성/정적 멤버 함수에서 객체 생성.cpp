#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	string name;
	int sNo;

	void Print();

private:
	Student(const string& name_arg, int stdNumber);

public:
	static int studentNumber; // 학생의 번호를 자동으로 부여하기위해
	static Student* CreateStudent(const string& name_arg); // private 속성인 생성자를 정적멤버함수를 통해 접근할려고한다
};

int Student::studentNumber = 0;

Student* Student::CreateStudent(const string& name_arg)
{
	// private 속성은 클래스 내부에서 접근이 가능하다
	// 그걸 이용해서 정적 멤버 함수로 동적 할당한 후 그 주소를 반환한다
	Student* p = new Student(name_arg, studentNumber++);

	return p;
}

Student::Student(const string& name_arg, int stdNumber)
{
	name = name_arg;
	sNo = stdNumber;
}

void Student::Print()
{
	cout << "(name = " << name << ", Std.Num. = " << sNo << ")" << endl;
}

int main()
{
	// 학생 객체를 세 개 생성한다
	Student* p1, *p2, *p3;

	p1 = Student::CreateStudent("임태민");
	p2 = Student::CreateStudent("박찬엽");
	p3 = Student::CreateStudent("윤명준");

	p1->Print();
	p2->Print();
	p3->Print();

	// 객체를 동적으로 생성했으므로 해제해준다
	delete p1;
	delete p2;
	delete p3;
	p1 = p2 = p3 = NULL;

	return 0;
}