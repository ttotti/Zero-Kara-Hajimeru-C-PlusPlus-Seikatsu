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

// ��ȭ��ų x, y�� ���� �ް� SetX,Y() �Լ��� �Ἥ(���ο� ���� ������ �Ѿ ���� �ֱ� ����) x,y�� ���� ���ο� ���� ���Խ�Ų��
void Point::Offset(int x_delta, int y_delta)
{
	SetX(x + x_delta);
	SetY(y + y_delta);
}

void Point::Offset(const Point & pt)
{
	Offset(pt.x, pt.y);
}
