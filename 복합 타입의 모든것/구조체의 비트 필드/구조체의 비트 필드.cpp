#include <iostream>
#include <bitset>

using namespace std;

struct Flags
{
	int a : 3; // 비트 필드 구조체의 멤버가 차지하는 메모리 공간을 원하는 데로 조절할수있다
	int b : 4; // 비트 필드를 사용하는 멤버는 
	bool c : 1;
	int : 5;
};

///////////////////////////////////////////////////////////////////////////////////

// 16비트 칼라에서의 한 점을 나타내는 구조체
struct Pixe116
{
	unsigned int blue : 5; // RGB가 각각 5,6,5 비트씩 차지하는 구조체를 정의
	unsigned int green : 6;
	unsigned int red : 5;
};

// Pixel16과 unsigned short를 멤버로 가진 공용체
union Convert16 // unsigned short 타입의 값을 Pixel16 구조체 값으로 변환하기 위한 용도 공용체
{
	Pixe116 pixel;
	unsigned short us;
};

int main()
{
	// 한 점의 색상을 보관하는 변수
	// (임의의 값을 넣어둔다)
	unsigned short color = 0x1234;

	// unsigned short 타입의 값을 Pixe16 구조체 타입인 것처럼
	// 다루기 위해서 공용체를 사용한다
	Convert16 convert;
	convert.us = color; // convert.us 에 color를 대입하면 공용체기 때문에 멤버인 pixel 에도 영향이 간다
						// 결과적으로 us의 타입은 unsigned short 타입이지만 convert.pixel 을 통해 꺼내 쓸 때는 구조체 Pixel16 타입의 값처럼 사용할 수 있다
	cout << "colot = " << bitset<16>(color) << "(" << color << ")" << endl;
	cout << "blue = " << bitset<16>(convert.pixel.blue) << "(" << convert.pixel.blue << ")" << endl;

	return 0;
}