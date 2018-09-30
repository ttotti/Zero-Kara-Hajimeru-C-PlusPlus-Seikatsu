#include "Point.h"
#include <iostream>

using namespace std;

int main()
{
	// 초기화용으로 객체를 만들어둔다
	Point pt(50, 50);

	// 동적으로 객체를 생성한다
	Point* p1 = new Point(); // new 연산자로 할당할 때 생성자가 호출된다!
	Point* p2 = new Point(100,100);
	Point* p3 = new Point(pt);

	// 객체들의 내용을 출력한다
	p1->Print(); // (*p1).Print()
	p2->Print();
	p3->Print();

	cout << sizeof(p1) << ", " << sizeof(p2) << ", " << sizeof(pt) << endl;

	// 동적으로 생성한 객체들을 정리한다
	delete p1; // delete 연산자로 해제할 때 소멸자가 호출된다!
	delete p2;
	delete p3;
	p1 = p2 = p3 = 0;

	return 0;
}