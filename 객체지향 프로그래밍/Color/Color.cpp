#include "Color.h"
#include <iostream>

using namespace std;

const Color Color::Black(0, 0, 0);
const Color Color::White(255, 255, 255);
const Color Color::Green(0, 255, 0);
const Color Color::Blue(0, 0, 255);
const Color Color::Red(255, 0, 0);
const Color Color::Yellow(255, 255, 0);
const Color Color::Violet(255, 0, 255);
const Color Color::Gray(127, 127, 127);

Color::Color()
{
	// 처음 색상의 값으로 초기화 한다
	R = defR;
	G = defG;
	B = defB;
}

Color::Color(element_t R, element_t G, element_t B)
{
	// 각 인자로 초기화 한다
	// 멤버 변수와 매개 변수의 이름이 겹치므로 this를 사용한다
	this->R = R;
	this->G = G;
	this->B = B;
}

void Color::SetR(element_t val)
{
	R = val;
}

void Color::SetG(element_t val)
{
	G = val;
}

void Color::SetB(element_t val)
{
	B = val;
}

Color::element_t Color::GetR() const
{
	return R;
}

Color::element_t Color::GetG() const
{
	return G;
}

Color::element_t Color::GetB() const
{
	return B;
}

void Color::SetColor32(color32_t val)
{
	// 공용체를 사용해서 쉽게 만들수 있다.
	union
	{
		element_t rgb[4];
		color32_t color32;
	} temp;

	// 공용체의 32비트 정수 부분에 매개변수를 대입
	temp.color32 = val;

	// RGB의 값을 읽어서 대입한다.
	R = temp.rgb[0];
	G = temp.rgb[1];
	B = temp.rgb[2];
}

Color::color32_t Color::GetColor32() const
{
	// 공용체를 사용해서 쉽게 만들수 있다.
	union
	{
		element_t rgb[4];
		color32_t color32;
	} temp;

	// 공용체의rgb 부분에 값 입력
	temp.rgb[0] = R;
	temp.rgb[1] = G;
	temp.rgb[2] = B;

	// 32 비트 정수 부분을 읽어서 반환한다.
	return temp.color32;
}

void Color::AdjustBright(int delta)
{
	R = PutInRange(R + delta);
	G = PutInRange(G + delta);
	B = PutInRange(B + delta);
}

void Color::Print(bool endLine) const
{
	cout << "(R = " << (int)R << ", G = " << (int)G << ", B = " << (int)B << ")";

	if (endLine == true)
		cout << endl;
}

int Color::PutInRange(int val)
{
	if (val < 0)
		val = 0;
	else if (val > 255)
		val = 255;

	return val;
}
