#pragma once

#include "Shape.h"

class Circle :public Shape
{
protected:
	double _radius;

public:
	Circle();
	Circle(double x, double y, double radius);

	void Draw() const;
	void SetRadius(double radius);
};