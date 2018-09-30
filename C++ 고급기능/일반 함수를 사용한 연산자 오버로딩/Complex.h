#pragma once

class Complex
{
private:
	int real;		// 실수부
	int imaginary;  // 허수부

public:
	// 생성자
	// 실수부와 허수부의 값을 받아서 멤버 변수에 보관하는 생성자
	Complex(int realPart, int imaginaryPart)
		:real(realPart), imaginary(imaginaryPart)
	{
	}

	// 이 코드가 의미하는 바는 다음과 같다
	// Complex operator+(const Complex& left, const Complex& right) 와 같은 원형을 갖는 함수를 Complex 클래스의 친구로 만들겠다는 뜻이다
	// 친구로 지정한 함수에서는 Complex 클래스의 모든 멤버에 접근할 수 있게 된다
	// 일반 함수를 사용해서 연산자를 오버로딩할 때는 이렇게 friend 키워드를 사용해서 지정해주는 것이 일반적이다
	// 물론 굳이 사용할 필요가 없다면 사용하지 않아도 상관 없다
	// friend 키워드를 사용하여 멤버 변수를 직접 접근하는 대신 접근자를 사용해도 된다
	friend Complex operator+(const Complex& left, const Complex& right);

	// 접근자
	// 실수부와 허수부의 값을 쓰거나 읽을 수 있는 접근자
	int Real(int realPart)
	{
		real = realPart;
		return real;
	}
	int Imaginary(int ImaginaryPart)
	{
		imaginary = ImaginaryPart;
		return imaginary;
	}

	int Real() const { return real; }
	int Imaginary() const { return imaginary; }
};