#include "Point.h"
#include <iostream>

using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int initialX, int initialY)
{
	/*x = initialX;
	y = initialY;*/

	SetX(initialX);
	SetY(initialY);
}

Point::Point(const Point& pt)
{
	x = pt.x;
	y = pt.y;
}

void Point::Print() const
{
	cout << "(" << x << ", " << y << ")" << endl;
}