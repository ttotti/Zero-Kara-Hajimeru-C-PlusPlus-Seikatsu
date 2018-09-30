#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

#include <iostream>

using namespace std;

int main()
{
	Shape s;
	s.Move(100, 100);
	s.Draw();

	Rectangle r;
	r.Move(200, 100);
	r.Resize(50, 50);
	r.Draw();

	Circle c;
	c.Move(300, 100);
	c.SetRadius(30);
	c.Draw();

	cout << endl;

	// ������ ���� �迭�� �غ��Ѵ�
	Shape* shapes[5] = { NULL };

	// �� Ÿ���� ��ü�� �����ؼ� �迭�� �����Ѵ�
	shapes[0] = new Circle(100, 100, 50);
	shapes[1] = new Rectangle(300, 300, 100, 100);
	shapes[2] = new Rectangle(200, 100, 50, 150);
	shapes[3] = new Circle(100, 300, 150);
	shapes[4] = new Rectangle(200, 200, 200, 200);

	// ���� �ٸ� Ÿ���� ����� �迭�� ����Ѵ�
	// �׷��� ������ �ִ� ����� ���� ���� [shape]��� �����ϴµ� �̴� shape::Draw() �Լ��� ȣ���ߴٴ� ���̴�
	// ���ϴ� ����� ��µ��� �ʴ´�.. �̸� �ذ��ϱ� ���� �����Լ��� ����
	// shape Ŭ������ �ִ� Draw �Լ��� virtual Ű���带 �ٿ� �����Լ��� ����� ���ϴ� ����� ��µȴ�
	for (int i = 0; i < 5; i++)
		shapes[i]->Draw();

	// �� �ڵ�� ���⼭ �������� �Ҵ�Ȱ��� �������ְ� ������
	// ���� �Ҹ��ڰ� �ִٸ� �� �Ҹ��ڴ� �����Լ��� ���������Ѵ� (��: virtual ~Shape() )
	// Ŭ������ �ϳ� �̻��� �����Լ��� �ִ°�� �Ҹ��ڵ� �ݵ�� �����Լ��� ������ �Ѵ�
	for (int i = 1; i < 5; i++)
	{
		delete shapes[i];
		shapes[i] = NULL;
	}

	/*
	// ���� ��� Ŭ������ �̷� �Լ��� �ְ� ���ڷ� Shape�� ������������ �޴´ٸ�
	// �� �Լ��� Shape Ŭ������ ��ӹް��ִ� ��� Ŭ������ ��ü��� ������̳� ����Ҽ��ִ�
	// �̷����� ������ �̴�
	void Controller::MovetoOrigin(Shape* p)
	{
		p->Move(0,0);
		p->Draw();
	}
	*/

	return 0;
}