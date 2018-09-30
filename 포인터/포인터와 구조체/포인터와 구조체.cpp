#include <iostream>

using namespace std;

struct Rectangle
{
	int x, y;
	int width, height;
	int* p; // 구조체 안에 포인터
};

struct Dizzy
{
	int id;
	Dizzy* p;
};

int main()
{
	Rectangle rc = { 100,100,50,50 };

	Rectangle* p = &rc; // 구조체포인터

	(*p).x = 200;
	p->y = 250; // 정의

	cout << "rc = ( " << rc.x << " , " << rc.y <<  ", " << rc.width << ", " << rc.height << " )" << endl;

	rc.p = &rc.x;

	cout << *(rc.p) << endl;

	///////////////////////////////////////

	Dizzy a, b, c; // 포인터를 이용해 구조체를 서로 연결 사용한다 ex)링크드 리스트

	a.id = 1;
	a.p = &b;
	b.id = 2;
	b.p = &c;
	c.id = 3;
	c.p = &a;

	cout << "a.id = " << a.id << endl;
	cout << "b.id = " << a.p->id << endl;
	cout << "c.id = " << a.p->p->id << endl;
	cout << "a.id = " << a.p->p->p->id << endl;

	return 0;
}