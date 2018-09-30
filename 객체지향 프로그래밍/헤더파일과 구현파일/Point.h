#ifndef POINT_H
#define POiNT_H

class Point
{
private:
	int x, y;

public:
	void Print();

	Point();
	Point(int initialX, int initialY);
	Point(const Point& pt);

	// 클래스 내부에 함수내용을 적으면 자동으로 인라인 함수가 된다
	void SetX(int value)
	{
		if (value < 0) x = 0;
		else if (value > 100) x = 100;
		else x = value;
	}
	void SetY(int value);
	int GetX() { return x; }
	int Gety() { return y; }

};

// 클래스 외부에서 인라인 함수를 정의하고싶을때 inline 키워드를 붙여준다
// 외부에서 정의하는 인라인 함수는 반드시 헤더파일에 있어야 한다
inline void Point::SetY(int value)
{
	if (value < 0) y = 0;
	else if (value > 100) y = 100;
	else y = value;
}

#endif // !POINT_H

