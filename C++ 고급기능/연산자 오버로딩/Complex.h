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

	// 연산자 오버로딩
	// operator+ 와 같은 함수의 이름은 규칙으로 정해진 것이다
	// 만약 - 연산자를 오버로딩 하고싶다면 operator- 함수를 만들면 된다
	// 연산자를 오버로딩하는 방법은 단순한데 두 피연산자를 어떻게 매칭하는지를 정확히 해둘 필요가 있다
	// 왼쪽 피연산자는 자기자신(this) 이 되고 오른쪽 피연산자는 right 매개 변수가 된다
	Complex operator+(const Complex& right)
	{
		// 실수부와 허수부를 각각 더한다
		int real = this->real + right.real;
		int imag = this->imaginary + right.imaginary;

		// 결과를 보관한 복소수 객체를 반환한다
		// 실수부와 허수부 각각의 합을 이용해서 새로운 객체를 만든다 이 임시 객체의 값을 반환한다
		return Complex(real, imag);
	}

	// 뺄셈 연산자 오버로딩
	Complex operator-(const Complex& right)
	{
		int real = this->real - right.imaginary;
		int imag = this->imaginary - right.imaginary;

		return Complex(real, imag);
	}

	////////////////////////////////////////////

	// 이 예제의 핵심은 전치 연산과 후치 연산의 경우를 별로의 함수로 만든다는 점이다
	// 그리고 후치 연산임을 알리기 위해서 int 타입의 연산자를 하나 두었다는 점도 중요하다
	// 멤버 함수를 사용해서 피연산자가 하나인 연산자들을 오버로딩할 때는
	// 전치 연산자를 오버로딩한 경우처럼 인자가 없는 원형을 사용해야 하고
	// ++, -- 의 후치 연산만 이 규칙에서 예외가 되는 것이다

	// 연산자 오버로딩의 규칙에 대한 자세한것은 인터넷, 책 820p 를 참고한다

	// ++c 의 경우 (전치 연산)
	// ++c 와 같이 써주었을 때 이 함수가 호출된다 인자가 아무것도 없다는 점을 잘 봐둘 필요가 있다
	Complex operator++()
	{
		// 전치 연산이므로 자기 자신의 값을 먼저 증가시킨 후에 값을 반환한다
		// 실수부의 값을 먼저 더한다
		this->real++;

		// 현재 값을 반환한다
		return *this;
	}

	// c++의 경우 (후치 연산)
	// c++ 와 같이 써주었을 때 이 함수가 호출된다
	// int 타입의 이름 없는 인자를 눈여겨 보자 이 인자가 있는 함수는 후치 연산을 할 때 호출된다
	Complex operator++(int)
	{
		// 후치 연산이므로 증가되기 전의 값을 반환하게 구현했다
		// 현재 값을 먼저 보관한다
		Complex prev(this->real, this->imaginary);

		// 실수부의 값을 더한다
		this->real++;

		// 보관한 값을 반환한다
		return prev;
	}

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