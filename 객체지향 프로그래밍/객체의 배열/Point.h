#ifndef POINT_H
#define POiNT_H

class Point
{
private:
	int x, y;

public:
	void Print() const;
	void Offset(int x_delta, int y_delta); // 오버로드된 Offset() 함수 원형 두 개를 추가
	void Offset(const Point& pt);

	Point();
	Point(int initialX, int initialY);
	Point(const Point& pt);

	void SetX(int value);
	void SetY(int value);
	int GetX() const { return x; }
	int GetY() { return y; }

};

inline void Point::SetX(int value)
{
	if (value < 0) x = 0;
	else if (value > 100) x = 100;
	else x = value;
}

inline void Point::SetY(int value)
{
	if (value < 0) y = 0;
	else if (value > 100) y = 100;
	else y = value;
}


#endif // !POINT_H