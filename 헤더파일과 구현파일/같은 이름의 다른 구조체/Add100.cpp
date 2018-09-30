#include "Add100.h"
//#include "Point1.h"
//#include "Point2.h"

struct Point
{
	float x, y;
};

void Add100(Point& p)
{
	p.x += 100;
	p.y += 100;
}