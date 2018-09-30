#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle()
{
	_radius = 0.0;
}

Circle::Circle(double x, double y, double radius)
{
	_x = x;
	_y = y;
	_radius = radius;
}

void Circle::Draw() const
{
	cout << "[Circle] Position = ( " << _x << ", " << _y << " ) " << "Radius = ( " << _radius << " )" << endl;
}

void Circle::SetRadius(double radius)
{
	_radius = radius;
}
