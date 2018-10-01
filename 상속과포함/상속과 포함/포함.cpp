#include "Rect.h"
#include <iostream>

using namespace std;

int main()
{
	Rect rc1;

	rc1.Print();

	rc1.SetRect(10, 20, 30, 40);

	rc1.Print();

	rc1.SetTopLeft(Point(-20, -20));

	rc1.Print();

	cout << rc1.GetWidth() << ", " << rc1.GetHeight() << endl << endl;

	Rect rc2(Point(50, 60), Point(70, 80));
	Rect rc3(10, 20, 30, 40);

	rc2.Print();
	rc3.Print();

	return 0;
}