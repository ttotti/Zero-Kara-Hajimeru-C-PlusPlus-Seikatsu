#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
	// 도형을 움직이거나 그리는 함수
	void Move(double x, double y);
	virtual void Draw() const; // virtual 키워드를 앞에 붙이면 가상함수가 된다 (다형성)

	// 생성자
	Shape();
	Shape(double x, double y);

protected:
	double _x, _y;
};

#endif // !SHAPE_H
