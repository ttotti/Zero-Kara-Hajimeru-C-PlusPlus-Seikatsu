#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle :public Shape
{
protected:
	double _width;
	double _helght;

public:
	void Draw() const;
	void Resize(double width, double height);

	Rectangle();
	Rectangle(double x, double y, double width, double height);
};

#endif // !RECTANGLE_H

