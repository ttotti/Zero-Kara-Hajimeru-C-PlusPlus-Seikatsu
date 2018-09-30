#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle()
{
	_width = _helght = 0.0;
}

Rectangle::Rectangle(double x, double y, double width, double height)
{
	_x = x;
	_y = y;
	_width = width;
	_helght = height;
}

void Rectangle::Draw() const
{
	cout << "[Rectangle] Position = ( " << _x << ", " << _y << " ) " << "Size = ( " << _width << ", " << _helght << " )" << endl;
}

void Rectangle::Resize(double width, double height)
{
	_width = width;
	_helght = height;
}

