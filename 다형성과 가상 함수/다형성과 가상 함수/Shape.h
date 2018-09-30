#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
	// ������ �����̰ų� �׸��� �Լ�
	void Move(double x, double y);
	virtual void Draw() const; // virtual Ű���带 �տ� ���̸� �����Լ��� �ȴ� (������)

	// ������
	Shape();
	Shape(double x, double y);

protected:
	double _x, _y;
};

#endif // !SHAPE_H
