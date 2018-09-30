#include <iostream>

using namespace std;

class Point
{
private:
	int x, y; // ��� ������ �ܺο��� ������ �Ұ��ϰ� ������� // ���� ��������� �ܺο��� ������ �Ұ��ϰ� ����°��� ����

public:
	// ��� �Լ�
	void Print();

	// ������
	Point();
	Point(int initialX, int initialY);
	Point(const Point& pt);
	 
	// ������ // ��� ���� x,y�� ���� �аų� ������ �� �ִ� ������
	void SetX(int value) // �Է��� ���� ������ ������ ��� ��� �ùٸ� ������ �����ؼ� �����Ѵ�
	{ 
		if (value < 0)
			x = 0;
		else if (value > 100)
			x = 100;
		else
			x = value;
	}
	void SetY(int value) { y = value; }
	int GetX() { return x; }
	int GetY() { return y; }

};

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int initialX, int initialY)
{
	/*x = initialX;
	y = initialY;*/

	SetX(initialX); // �����ڿ����� �����ڸ� ����Ҽ��ִ�
	SetY(initialY);
}

Point::Point(const Point& pt)
{
	x = pt.x;
	y = pt.y;
}

void Point::Print()
{
	cout << "(" << x << ", " << y << ")" << endl;
}

int main()
{
	Point pt;

	pt.SetX(120);
	pt.SetY(100);

	cout << "pt.x = " << pt.GetX() << endl;
	cout << "pt.y = " << pt.GetY() << endl;

	Point pt2(-50, 200);

	pt2.Print();

	return 0;
}