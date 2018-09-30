#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
	// 도형을 움직이거나 그리는 함수
	void Move(double x, double y);

	// virtual 키워드를 앞에 붙이면 가상함수가 된다 (다형성)
	// 가상함수 맨 뒤에 = 0 을 붙이면 순수가상함수가 된다
	// 순수 가상함수란 이 함수는 정의가 없어서 호출할수없지만 자식 클래스에서 이 함수를 오버라이딩 할꺼니까 다형성을 사용해서 이 함수를 호출해라 하는 역활
	virtual void Draw() const = 0;

	// 생성자
	Shape();
	Shape(double x, double y);

protected:
	double _x, _y;
};

#endif // !SHAPE_H
