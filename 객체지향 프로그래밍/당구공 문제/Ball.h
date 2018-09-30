#ifndef BALL_H
#define BALL_H

class Ball
{
private:
	int _x, _y;
	static int _radius; // �������

public:
	void Print();

	Ball();
	Ball(int x, int y);
	Ball(const Ball& b);

	void SetX(int value) // �ڵ����� �ζ����Լ��� �ȴ�
	{
		if (value < 0)
			_x = 0;
		else if (value > 800)
			_x = 800;
		else
			_x = value;
	}
	void SetY(int value)
	{
		if (value < 0)
			_y = 0;
		else if (value > 400)
			_y = 400;
		else
			_y = value;
	}
	int GetX() { return _x; }
	int GetY() { return _y; }

};

#endif // !BALL_H

