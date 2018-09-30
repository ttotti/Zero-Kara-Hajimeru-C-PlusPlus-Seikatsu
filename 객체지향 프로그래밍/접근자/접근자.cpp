#include <iostream>

using namespace std;

class Point
{
private:
	int x, y; // 멤버 변수를 외부에서 접근이 불가하게 만들었다 // 보통 멤버변수는 외부에서 접근을 불가하게 만드는것이 좋다

public:
	// 멤버 함수
	void Print();

	// 생성자
	Point();
	Point(int initialX, int initialY);
	Point(const Point& pt);
	 
	// 접근자 // 멤버 변수 x,y의 값을 읽거나 변경할 수 있는 접근자
	void SetX(int value) // 입력한 값이 지정된 범위를 벗어난 경우 올바른 값으로 변경해서 대입한다
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

	SetX(initialX); // 생성자에서도 접근자를 사용할수있다
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