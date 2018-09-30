#include <iostream>

using namespace std;

class Point
{
public:
	int x, y;

	void Print();

	// 생성자
	Point();
	Point(int initialX, int initialY);
	Point(const Point& pt);
};

// 생성자 초기화
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

// Point 객체를 인자로 요구하는 함수
void Area(const Point& pt)
{
	// (0,0) 과 pt가 이루는 사각형의 면적을 구한다
	int area = pt.x*pt.y;

	cout << "(0, 0)과 이루는 사각형의 면적 = " << area << endl;
}

int main()
{
	int x = 5;
	int y = 7;

	// Area() 함수를 호출하기 위해 Point 객체를 만든다
	//Point temp(x, y);

	// 함수호출
	Area(Point(x, y)); // 임시 객체 // 이렇게 하면 Point 타입의 임시 객체가 생성되고 그 객체는 Point(int,int)에 의해서 초기화 된다 그리고 임시 객체를 인자로 전달한다
	// 이 임시객체는 함수가 끝나면 자동적으로 소멸한다 그렇기 때문에 이 객체의 주소를 얻어두었다가 나중에 쓰는건 위험하다

	return 0;
}