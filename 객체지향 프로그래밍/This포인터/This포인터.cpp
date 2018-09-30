#include <iostream>

using namespace std;

class WhoAmI
{
public:
	int id;

	WhoAmI(int id);
	void ShowTourseif() const;
	static void TestThis();
};

WhoAmI::WhoAmI(int id)
{
	// id = id_arg;
	// this 포인터로 이름충돌을 해결할수있다
	// this->id 는 멤버변수를 의미
	// id 는 매개변수(인수)를 의미
	this->id = id;
}

void WhoAmI::ShowTourseif() const
{
	// this는 자기자신을 가리킨다 // 내부적으로 포인터 this를 만들어 주소값을 대입한다(this는 자기자신의 값이므로 바꿀수없다 즉 const)
	// 멤버가 아닌 함수에 This 포인터가 없다
	cout << "(ID = " << id << ", this = " << this << ")" << endl;
}

void WhoAmI::TestThis()
{
	// static 정적멤버함수에는 this가 없다
	// This 포인터는 멤버함수를 소유한 객체를 가리키는것 인데
	// 정적멤버함수는 객체의 소유가 아니기 때문에 this 포인터가 없는 것이다
	// cout << "this = " << this << endl;
}

int main()
{
	WhoAmI obj1(1);
	WhoAmI obj2(2);
	WhoAmI obj3(3);

	obj1.ShowTourseif();
	obj2.ShowTourseif();
	obj3.ShowTourseif();

	cout << "&obj1 = " << &obj1 << endl;
	cout << "&obj2 = " << &obj2 << endl;
	cout << "&obj3 = " << &obj3 << endl;

	return 0;
}