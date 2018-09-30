#include <iostream>
#include "Ball.h"

using namespace std;

int main()
{
	Ball ball(801, 398);
	Ball newball = ball;
	Ball balls[4] = { Ball(0,0),Ball(20,0),Ball(40,0),Ball(60,0) };

	ball.Print();
	newball.Print();

	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		balls[i].Print();
	}

	cout << endl;
	cout << sizeof(ball) << ", " << sizeof(newball) << ", " << sizeof(balls) << endl; // static 변수를 쓰니 메모리가 줄었음..

	cout << endl;
}