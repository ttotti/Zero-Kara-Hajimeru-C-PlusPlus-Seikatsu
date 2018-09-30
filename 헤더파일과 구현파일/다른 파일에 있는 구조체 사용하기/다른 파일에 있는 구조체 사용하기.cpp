#include <iostream>

#include "Point.h"
#include "Example2.h"

using namespace std;

int main()
{
	Point a = { 0,0 };
	Point b = { 3,4 };

	double result;
	result = Distance(a, b);

	cout << result << endl;

	return 0;
}