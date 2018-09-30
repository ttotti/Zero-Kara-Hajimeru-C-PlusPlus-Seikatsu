#include "Point.h"
#include <iostream>

using namespace std;

class Example
{
public:
	static void count();
};

// void XX() 형태의 함수에 대한 포인터
typedef void(*FP1)(int); // 멤버가 아닌 함수
// void Point::XX() 형태의 함수에 대한 포인터
typedef void(Point::*FP2)(int); // Point클래스의 멤버 함수
typedef void(Point::*FP3)() const; // 가리킬려고 하는 Print() 가 const 속성이므로 함수포인터를 정의할때 뒤에 const를 붙여준다

typedef void(*FP)();

int main()
{
	Point pt(50, 50);

	// FP1 fp1 = &Point::SetX; // 오류
	FP2 fp2 = &Point::SetX;
	(pt.*fp2)(100); // pt 객체를 사용해서 fp2가 가리키는 함수를 호출한다 // 연산자의 우선 순위 때문에 pt.*fp2를 괄호로 감싸주어야 한다

	FP fp3 = &Example::count; // 클래스 Example의 정적 함수를 가리키는 함수포인터 // 정적함수는 void XX() 형태의 함수포인터를 쓸수있다
	(fp3)(); // 정적 함수는 어떤 객체의 멤버함수를 호출할지 정하지않고 그냥 호출이 가능하다

	FP3 fp4 = &Point::Print;
	(pt.*fp4)(); //pt.Print();

	return 0;
}

void Example::count()
{
	cout << "fp3 함수포인터 출력!" << endl;
}
