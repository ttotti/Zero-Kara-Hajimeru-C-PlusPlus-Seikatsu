#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

#include <iostream>

using namespace std;

int main()
{
	// 하나 이상의 순수 가상 함수를 가진 클래스는 추상클래스라 불리는데
	// 추상 클래스는 객체를 만드는것이 불가능하다
	// 추상 클래스는 객체를 생성해서 사용하기 위한 용도가 아닌 다형성을 위핸 부모 클래스로서의 용도를 가지고 있다
	// Shape s;

	// 도형을 담을 배열을 준비한다
	Shape* shapes[5] = { NULL };

	// 각 타입의 객체를 생성해서 배열에 보관한다
	shapes[0] = new Circle(100, 100, 50);
	shapes[1] = new Rectangle(300, 300, 100, 100);
	shapes[2] = new Rectangle(200, 100, 50, 150);
	shapes[3] = new Circle(100, 300, 150);
	shapes[4] = new Rectangle(200, 200, 200, 200);

	// 순수 가상 함수로 정의된 Draw()는 각 자식클래스에서 오버라이딩 되서 나온것들이다
	for (int i = 0; i < 5; i++)
		shapes[i]->Draw();

	for (int i = 1; i < 5; i++)
	{
		delete shapes[i];
		shapes[i] = NULL;
	}

	return 0;
}