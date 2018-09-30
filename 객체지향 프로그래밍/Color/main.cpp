#include "Color.h"
#include <iostream>

using namespace std;

int main()
{
	//------------------------------
	// Color 클래스의 기본 기능 사용
	//------------------------------

	// 디폴트 생성자를 사용해서 생성한다
	Color c1;
	c1.Print(); // 내용 확인

	// 인자가 있는 생성자를 사용해서 생성한다
	Color c2(100, 100, 100);
	c2.Print(); // 내용 확인

	// c2의 R 요소를 변경한다
	c2.SetR(255);
	c2.Print(); // 내용 확인

	// c2의 R 요소를 확인한다
	cout << "c2.R = " << (int)c2.GetR() << endl;

	// c2의 전체 밝기를 50만큼 증가시킨다
	c2.AdjustBright(50);
	c2.Print(); // 내용 확인

	// c2의 색상을 32비트 값으로 출력한다
	Color::color32_t color = c2.GetColor32();
	cout << "c2 = " << color << endl;

	// c1의 색상을 32비트 값으로 출력한다
	c1.SetColor32(color);
	c1.Print(); // 내용 확인

	//-----------------
	// 정적 멤버의 사용
	//-----------------

	// 빨간색 객체의 값 확인
	Color::Red.Print();

	// 객체를 빨간색으로 초기화 한다
	Color c3 = Color::Red;
	c3.Print(); // 내용 확인
	
	return 0;
}