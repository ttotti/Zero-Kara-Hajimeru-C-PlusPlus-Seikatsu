#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
	// ������ �����̰ų� �׸��� �Լ�
	void Move(double x, double y);

	// virtual Ű���带 �տ� ���̸� �����Լ��� �ȴ� (������)
	// �����Լ� �� �ڿ� = 0 �� ���̸� ���������Լ��� �ȴ�
	// ���� �����Լ��� �� �Լ��� ���ǰ� ��� ȣ���Ҽ������� �ڽ� Ŭ�������� �� �Լ��� �������̵� �Ҳ��ϱ� �������� ����ؼ� �� �Լ��� ȣ���ض� �ϴ� ��Ȱ
	virtual void Draw() const = 0;

	// ������
	Shape();
	Shape(double x, double y);

protected:
	double _x, _y;
};

#endif // !SHAPE_H
