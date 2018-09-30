#include "Ball.h"
#include <iostream>

using namespace std;

int Ball::_radius = 2;

Ball::Ball()
{
	_x = 0;
	_y = 0;
}

Ball::Ball(int x, int y)
{
	_x = x;
	_y = y;
	_radius = 2;

	SetX(x);
	SetY(y);
}

Ball::Ball(const Ball& b)
{
	_radius = b._radius;
	_x = b._x + (_radius * 2);
	_y = b._y;

	if (_x > 800)
	{
		_x = 800;
		_y = _y + (_radius * 2);

		if (_y > 400)
			_y = _y - (_radius * 4);
	}
}

void Ball::Print()
{
	cout << "(" << _x << ", " << _y << ")" << endl;
}