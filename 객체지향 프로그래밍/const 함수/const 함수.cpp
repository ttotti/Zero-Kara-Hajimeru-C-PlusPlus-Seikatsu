#include <iostream>
#include "Point.h"

using namespace std;

void Area(const Point& pt);

int main()
{
	Point pt(-50, 200);

	pt.Print();

	return 0;
}

// 객체를 인자로 넘길때 const Point& 와 같이 const 타입의 레퍼런스로 넘기는것이 일반적이다(함수내에서 객체의 멤버변수의 값을 변경을 하지 않을경우)
// Area() 함수는 멤버변수의 값을 간접적으로 읽기만 할 뿐이기 때문에 const Point& 로 써주는 것은 아주 타당하다
// 덕분에 매개 변수 pt는 const 객체가 되었고 
// const 객체를 사용해서 const가 아닌 멤버변수를 호출하는 것은 불가능하다.. 즉 GetY()는 const가 아니므로 호출할 수 없다
// 가능한 모든 멤버 함수를 const로 만들자
void Area(const Point& pt)
{
	int area = pt.GetX()*pt.GetY();

	cout << "(0, 0)과 이 점이 이루는 사각형의 면적 = " << area << endl;
}