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

	// Ŭ���� ���ο� �Լ������� ������ �ڵ����� �ζ��� �Լ��� �ȴ�
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

// Ŭ���� �ܺο��� �ζ��� �Լ��� �����ϰ������ inline Ű���带 �ٿ��ش�
// �ܺο��� �����ϴ� �ζ��� �Լ��� �ݵ�� ������Ͽ� �־�� �Ѵ�
inline void Point::SetY(int value)
{
	if (value < 0) y = 0;
	else if (value > 100) y = 100;
	else y = value;
}

#endif // !POINT_H

