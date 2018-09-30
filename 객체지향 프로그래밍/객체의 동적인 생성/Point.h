#ifndef POINT_H
#define POiNT_H

class Point
{
public:
	enum { MAX_X = 100, MIN_X = 0, MAX_Y = 100, MIN_Y = 0 }; // 열거체 // 기존과 다른점은 클래스소속이다
	typedef int COOR_T; // 열거체와 마찬가지로 클래스 안에서만 통용하는 타입을 재정의하는데 사용할수있다 //수정이 쉽다

	void Print() const;
	void Offset(COOR_T x_delta, COOR_T y_delta); // 오버로드된 Offset() 함수 원형 두 개를 추가
	void Offset(const Point& pt);

	Point();
	Point(COOR_T initialX, COOR_T initialY);
	Point(const Point& pt);

	void SetX(COOR_T value);
	void SetY(COOR_T value);
	COOR_T GetX() const { return x; }
	COOR_T GetY() { return y; }

private:
	COOR_T x, y;
};

inline void Point::SetX(COOR_T value)
{
	if (value < MIN_X) x = 0;
	else if (value > MAX_X) x = 100;
	else x = value;
}

inline void Point::SetY(COOR_T value)
{
	if (value < MIN_Y) y = 0;
	else if (value > MAX_X) y = 100;
	else y = value;
}


#endif // !POINT_H