#include "Shape.h"
#include <iostream>

using namespace std;

Shape::Shape()
{
	_x = _y = 0.0;
}

Shape::Shape(double x, double y)
{
	_x = x;
	_y = y;
}

void Shape::Move(double x, double y)
{
	_x = x;
	_y = y;
}

// 부모클래스에서 Draw() 함수가 순수가상함수이기 때문에 정의가 없어야 한다
//void Shape::Draw() const
//{
//	cout << "[Shape] Position = ( " << _x << ", " << _y << " )" << endl;
//}

