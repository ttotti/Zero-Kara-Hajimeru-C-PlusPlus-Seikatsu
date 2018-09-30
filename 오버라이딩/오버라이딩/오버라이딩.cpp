#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

#include <iostream>

using namespace std;

int main()
{
	// �ϳ� �̻��� ���� ���� �Լ��� ���� Ŭ������ �߻�Ŭ������ �Ҹ��µ�
	// �߻� Ŭ������ ��ü�� ����°��� �Ұ����ϴ�
	// �߻� Ŭ������ ��ü�� �����ؼ� ����ϱ� ���� �뵵�� �ƴ� �������� ���� �θ� Ŭ�����μ��� �뵵�� ������ �ִ�
	// Shape s;

	// ������ ���� �迭�� �غ��Ѵ�
	Shape* shapes[5] = { NULL };

	// �� Ÿ���� ��ü�� �����ؼ� �迭�� �����Ѵ�
	shapes[0] = new Circle(100, 100, 50);
	shapes[1] = new Rectangle(300, 300, 100, 100);
	shapes[2] = new Rectangle(200, 100, 50, 150);
	shapes[3] = new Circle(100, 300, 150);
	shapes[4] = new Rectangle(200, 200, 200, 200);

	// ���� ���� �Լ��� ���ǵ� Draw()�� �� �ڽ�Ŭ�������� �������̵� �Ǽ� ���°͵��̴�
	for (int i = 0; i < 5; i++)
		shapes[i]->Draw();

	for (int i = 1; i < 5; i++)
	{
		delete shapes[i];
		shapes[i] = NULL;
	}

	return 0;
}