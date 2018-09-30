#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

#include <iostream>

using namespace std;

int main()
{
	Shape s;
	s.Move(100, 100);
	s.Draw();

	Rectangle r;
	r.Move(200, 100);
	r.Resize(50, 50);
	r.Draw();

	Circle c;
	c.Move(300, 100);
	c.SetRadius(30);
	c.Draw();

	cout << endl;

	// 도형을 담을 배열을 준비한다
	Shape* shapes[5] = { NULL };

	// 각 타입의 객체를 생성해서 배열에 보관한다
	shapes[0] = new Circle(100, 100, 50);
	shapes[1] = new Rectangle(300, 300, 100, 100);
	shapes[2] = new Rectangle(200, 100, 50, 150);
	shapes[3] = new Circle(100, 300, 150);
	shapes[4] = new Rectangle(200, 200, 200, 200);

	// 각각 다른 타입이 들었는 배열을 출력한다
	// 그런데 문제가 있다 결과를 보면 전부 [shape]라고 시작하는데 이는 shape::Draw() 함수를 호출했다는 뜻이다
	// 원하는 결과가 출력되지 않는다.. 이를 해결하기 위해 가상함수를 쓴다
	// shape 클래스에 있는 Draw 함수에 virtual 키워드를 붙여 가상함수로 만들면 원하는 결과가 출력된다
	for (int i = 0; i < 5; i++)
		shapes[i]->Draw();

	// 이 코드는 여기서 동적으로 할당된것을 해제해주고 있지만
	// 만약 소멸자가 있다면 그 소멸자는 가상함수로 만들어줘야한다 (예: virtual ~Shape() )
	// 클래스에 하나 이상의 가상함수가 있는경우 소멸자도 반드시 가상함수로 만들어야 한다
	for (int i = 1; i < 5; i++)
	{
		delete shapes[i];
		shapes[i] = NULL;
	}

	/*
	// 만약 어느 클래스에 이런 함수가 있고 인자로 Shape의 포인터형으로 받는다면
	// 이 함수는 Shape 클래스에 상속받고있는 모든 클래스의 객체라면 어느것이나 사용할수있다
	// 이런것이 다형성 이다
	void Controller::MovetoOrigin(Shape* p)
	{
		p->Move(0,0);
		p->Draw();
	}
	*/

	return 0;
}