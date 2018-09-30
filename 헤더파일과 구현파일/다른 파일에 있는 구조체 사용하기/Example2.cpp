#include "Example2.h"

double Distance(const Point& p1, const Point& p2)
{
	double result = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

	return result;
}