#include "Point.h"
#include <iostream>

using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(COOR_T initialX, COOR_T initialY)
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

// 변화시킬 x, y의 값을 받고 SetX,Y() 함수를 써서(새로운 값이 범위를 넘어설 수도 있기 때문) x,y의 값에 새로운 값을 대입시킨다
void Point::Offset(COOR_T x_delta, COOR_T y_delta)
{
	SetX(x + x_delta);
	SetY(y + y_delta);
}

void Point::Offset(const Point & pt)
{
	Offset(pt.x, pt.y);
}
