#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
	// 각 RGB 요소를 보관하는데 사용할 타입
	// 현재로서는 0~255의 범위를 갖는다
	typedef unsigned char element_t;

	// 32비트 색상의 타입
	typedef unsigned long color32_t;

	// 처음 생성 시 갖게 되는 기본색(현재 흰색)
	enum { defR = 255, defG = 255, defB = 255 };

public:
	// 생성자
	Color();
	Color(element_t R, element_t G, element_t B);

	// 접근자
	void SetR(element_t val);
	void SetG(element_t val);
	void SetB(element_t val);
	element_t GetR() const;
	element_t GetG() const;
	element_t GetB() const;

	// RGB의 값을 32비트 정수로 만들어서 반환/지정
	// 32비트 중에서 24비트만 사용한다
	// 즉 RGB 각 요소별로 8비트씩 차지
	void SetColor32(color32_t val);
	color32_t GetColor32() const;

	// 전체 밝기를 변화시킨다
	void AdjustBright(int delta);

	// 값을 출력한다
	// endLine == true이면 엔터도 찍어준다
	void Print(bool endLine = true) const;

protected:
	// 범위를 벗어난 값을 0~255 안의 범위로 만들어준다
	// 소스 코드의 중복을 막기 위해서 사용할 수 있다
	int PutInRange(int val);

protected:
	// 색상은 RGB로 보관한다
	unsigned char R;
	unsigned char G;
	unsigned char B;

public:
	// 자주 쓰이는 색상을 정적 멤버로 만들어준다
	static const Color Black;
	static const Color White;
	static const Color Green;
	static const Color Blue;
	static const Color Red;
	static const Color Yellow;
	static const Color Violet;
	static const Color Gray;
};

#endif // !COLOR_H

