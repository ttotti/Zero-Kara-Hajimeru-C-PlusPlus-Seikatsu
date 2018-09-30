#include <iostream>

using namespace std;

class Point
{
public:
	int x, y;

	void Print();

	// ������
	Point();
	Point(int initialX, int initialY);
	Point(const Point& pt);
};

// ������ �ʱ�ȭ
Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int initialX, int initialY)
{
	x = initialX;
	y = initialY;
}

Point::Point(const Point& pt)
{
	x = pt.x;
	y = pt.y;
}

// Point ��ü�� ���ڷ� �䱸�ϴ� �Լ�
void Area(const Point& pt)
{
	// (0,0) �� pt�� �̷�� �簢���� ������ ���Ѵ�
	int area = pt.x*pt.y;

	cout << "(0, 0)�� �̷�� �簢���� ���� = " << area << endl;
}

int main()
{
	int x = 5;
	int y = 7;

	// Area() �Լ��� ȣ���ϱ� ���� Point ��ü�� �����
	//Point temp(x, y);

	// �Լ�ȣ��
	Area(Point(x, y)); // �ӽ� ��ü // �̷��� �ϸ� Point Ÿ���� �ӽ� ��ü�� �����ǰ� �� ��ü�� Point(int,int)�� ���ؼ� �ʱ�ȭ �ȴ� �׸��� �ӽ� ��ü�� ���ڷ� �����Ѵ�
	// �� �ӽð�ü�� �Լ��� ������ �ڵ������� �Ҹ��Ѵ� �׷��� ������ �� ��ü�� �ּҸ� ���ξ��ٰ� ���߿� ���°� �����ϴ�

	return 0;
}