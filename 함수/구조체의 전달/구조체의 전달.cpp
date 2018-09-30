#include <iostream>
#include <cmath> // sqrt() 와 pow()의 함수를 사용하기 위한 준비

using namespace std;

struct Point
{
	int x, y;
	// int q, w, e, r, t;
	// int a, s, d;
};

double Distance(const Point& p1, Point* p2); // 구조체 타입의 인자를 받고 double 타입의 반환 값을 갖는 함수 원형
									   // 하지만 생으로 인자를 받으면 나중에 성능 문제가 일어난다!! 예를 들어 인자로 넘기면 함수호출시 각 멤버를 생성 복사하는 것인다
									   // int 타입의 멤버가 10개면 40바이트이다 40바이트 크기의 매개 변수를 모두 복사 생성은 공간적 시간적 성능 저하를 가져온다!
									   // 그러므로 레퍼런스를 쓴다 40바이트씩 되는 구조체 대신 4바이트만 차지하는(건 포인터이다) 레퍼런스(이름만 빌리는것!! 그래도 이득이다)를 사용하는게 이득이다!
									   // 그리고 함수 내에서 고쳐쓰기를 원치 않는다면 const 속성으로 바꾼다

int main()
{
	Point a = { 0,0 };
	Point b = { 3,4 };

	double dist_a_b = Distance(a, &b); // 구조체 타입의 인자를 넘겨준다 구조체 변수의 이름을 넘겨주면 된다

	cout << "(" << a.x << ", " << a.y << ") 와 " << "(" << b.x << ", " << b.y << ") 의 거리 = " << dist_a_b << endl;

	return 0;
}

double Distance(const Point& p1, Point* p2) // 함수가 시작되면 구조체 변수를 생성한다 그리고 생성과 동시에 a 와 b 값으로 초기화한다 // 구조체를 사용해서 초기화하는 경우 각 멤버의 값을 복사한다
{
	cout << sizeof(p1) << endl << sizeof(p2) << endl; // 레퍼런스와 포인터 메모리크기 비교

	double distance;
	distance = sqrt(pow(p1.x - p2->x, 2) + pow(p1.y - p2->y, 2)); // 피타고라스의 정리

	cout << "p1 = " << "{" << p1.x << ", " << p1.y << "}" << endl;
	cout << "p2 = " << "{" << p2->x << ", " << p2->y << "}" << endl;

	return distance;
}