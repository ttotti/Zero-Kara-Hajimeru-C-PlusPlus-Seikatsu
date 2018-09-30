#include <iostream>
#include <cmath>

using namespace std;

class Point // Point 클래스를 정의한다 // 클래스는 관련된 정보(변수)와 행동(함수) 를 모아놓은것이다
{
public: // 접근 제어와 관련된 키워드
	int x, y; // 멤버 변수

	void Print() // 멤버 함수
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}

	float DistanceFromOrigin(); // 함수 원형만 남겨놓는다 // 클래스 코드가 간결해짐
};

float Point :: DistanceFromOrigin() // 클래스 정의 밖에서 범위 지정 연산자(::)를 사용해서 함수를 정의한다
{
	//return sqrt(float(x*x) + float(y*y));
	return sqrt(pow(x, 2) + pow(y, 2));
}

int main()
{
	// 객체를 생성한다
	Point pt1, pt2; // 문법적으로 봤을 때 클래스는 사용자 정의 타입이다 그리고 객체는 클래스 타입을 사용해서 정의한 변수이다

	// pt1과 pt2를 초기화 한다
	pt1.x = 100;
	pt1.y = 100;
	pt2.x = 200;
	pt2.y = 200;


	// pt1과 pt2의 내용을 출력한다
	pt1.Print();
	pt2.Print();

	Point pt3 = pt1; // 이미 생성한 객체 pt1을 통해서 pt3을 초기화 한다 (초기화)
	pt3.Print();

	pt3 = pt2; // 위와 같은 방법으로 pt2로 대입 한다 (대입) // 초기화 랑 대입은 서로 다른 연산이다
	pt3.Print();

	pt3 = pt2 = pt1;
	pt3.Print();

	Point c = { 3,4 };
	cout << c.DistanceFromOrigin() << endl;

	return 0;
}
