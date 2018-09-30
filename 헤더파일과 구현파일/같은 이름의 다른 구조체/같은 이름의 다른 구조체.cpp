#include <iostream>

//#include "Point1.h"
//#include "Point2.h"
#include "Add100.h"

using namespace std;

struct Point
{
	int x, y;
};

int main()
{
	Point pt = { 0,0 };
	Add100(pt);

	cout << pt.x << ", " << pt.y << endl;

	return 0;
}