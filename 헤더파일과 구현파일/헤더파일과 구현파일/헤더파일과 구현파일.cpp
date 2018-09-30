#include <iostream>
#include <cmath>

#include "Point.h"

using namespace std;

//struct Point // 헤더 파일에 구현
//{
//	int x, y;
//};

//double Distance(Point p1, Point p2);

int main()
{
	Point a = { 0,0 };
	Point b = { 3,4 };

	double dist_a_b = Distance(a, b);

	cout << "{" << a.x << ", " << a.y << "}" << endl;
	cout << "{" << b.x << ", " << b.y << "}" << endl;
	cout << dist_a_b << endl;

	return 0;
}

double Distance(Point p1, Point p2)
{
	double result = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

	return result;
}