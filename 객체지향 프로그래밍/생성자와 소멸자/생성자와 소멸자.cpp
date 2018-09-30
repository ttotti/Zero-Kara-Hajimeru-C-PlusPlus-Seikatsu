#include <iostream>

using namespace std;

// Point 클래스를 정의한다
class Point
{
public:
	int x, y; // 멤버변수

	void Print(); // 멤버함수

	
	Point(); // 생성자 원형 // 생성자는 클래스 안에서도 정의가 가능하다 // 디폴트 생성자
	Point(int initialX, int initialY); // 인자가 있는 생성자
	Point(const Point& pt); // 복사 생성자 // 복사 생성자는 자기 자신의 타입에 대한 레퍼런스를 인자로 받는 생성자다
};

// 생성자를 정의하고 있다 // 생성자에서 하는 일은 변수 x y 를 0으로 초기화 하는 것이다
Point::Point()
{
	cout << "디폴트 생성자 호출!" << endl;
	x = 0;
	y = 0;
}

// 인자가 있는 생성자를 정의하고 있다 // 인자로 넘어온 값을 사용해서 x y를 초기화 한다
Point::Point(int initialX, int initialY)
{
	cout << "인자가 있는 생성자 호출!" << endl;
	x = initialX;
	y = initialY;
}

Point::Point(const Point& pt)
{
	cout << "복사 생성자 호출!" << endl;
	x = pt.x;
	y = pt.y;
}

void Point::Print()
{
	cout << "(" << x << ", " << y << ")" << endl;
}

///////////////////////////////////////////

class String
{
private:
	char* p;

public:
	String(char c[100]);
	String(const String& s);
	String(const String& s,int i);

	int size() const
	{
		return strlen(p);
	}

	void print();
};

String::String(char c[100])
{
	p = c;
}

// 복사 생성자가 단순히 1:1 복사만 하는 경우 // 같은 주소의 문자열을 공유한다 // 얕은복사
// 문제는 그 주소를 해제해야하는 경우 그 주소를 두개 이상의 변수가 공유하고 있는데 해제는 하나씩 하기 때문에 다른 변수들은 이미 해제한 주소를 해제하고 있는 꼴이 된다(소멸자를 참고한다)
String::String(const String& s)
{
	cout << "복사생성자1 호출" << endl;
	p = s.p;
}

// 복사 생성자가 문자열을 복사해주는 경우 // 서로 다른 주소의 문자열을 가지고 있다 // 깊은복사
// 위의 문제를 해결해준다
String::String(const String& s,int i)
{
	cout << "복사생성자2 호출" << endl;
	p = new char[s.size() + 1];
	strcpy(p, s.p);
}

void String::print()
{
	cout << p << endl;
	cout << &p << endl;
}

int main()
{
	Point pt1; // Point 클래스의 객체를 생성한다 // 객체가 생성되면 자동으로 생성자를 호출한다
	Point pt2(3, 5); // 인자가 있는 Point 클래스 생성자를 생성한다 // 생성자는 정의된 시그니처에 따라 어떤 생성자를 호출할지 정해진다(오버로드)

	pt1.Print();
	pt2.Print();

	Point pt3 = pt1; // 다른 객체를 사용해서 초기화하는 경우 복사 생성자가 호출된다 // 이때 복사생성자의 인자는 pt1이 된다
	pt3.Print();

	pt3 = pt2; // 다른 객체를 사용해서 대입하는 경우는 복사 생성자가 호출되지 않는다
	pt3.Print();

	cout << endl;

	////////////////////////////////////

	String str1("Hello Class!");
	str1.print();

	String str2 = str1;
	str2.print();

	String str3(str1, 0);
	str3.print();



	return 0;
}
