#ifndef RECT_H
#define RECT_H

#include "Point.h"

class Rect
{
public:
	// 생성자
	Rect();
	Rect(const Point& topLeft, const Point& botRight);
	Rect(int left, int top, int right, int bottom);
	~Rect();

	// 각 점의 값 지정/얻기
	void SetTopLeft(const Point& topLeft);
	void SetBottomRight(const Point& bottomRight);
	void SetRect(int left, int top, int right, int bottom);
	Point GetTopLeft()const;
	Point GetBottomRight()const;
	void GetRect(int& left, int& top, int& right, int& bottom);

	// 넓이 높이 계산
	int GetWidth() const;
	int GetHeight() const;

	// 값 출력
	void Print() const;

protected:
	Point _topLeft;
	Point _bottomRight;
};

#endif // !RECT_H

