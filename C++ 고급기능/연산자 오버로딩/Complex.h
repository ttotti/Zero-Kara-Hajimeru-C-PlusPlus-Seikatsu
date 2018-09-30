#pragma once

class Complex
{
private:
	int real;		// �Ǽ���
	int imaginary;  // �����

public:
	// ������
	// �Ǽ��ο� ������� ���� �޾Ƽ� ��� ������ �����ϴ� ������
	Complex(int realPart, int imaginaryPart)
		:real(realPart), imaginary(imaginaryPart)
	{
	}

	// ������ �����ε�
	// operator+ �� ���� �Լ��� �̸��� ��Ģ���� ������ ���̴�
	// ���� - �����ڸ� �����ε� �ϰ�ʹٸ� operator- �Լ��� ����� �ȴ�
	// �����ڸ� �����ε��ϴ� ����� �ܼ��ѵ� �� �ǿ����ڸ� ��� ��Ī�ϴ����� ��Ȯ�� �ص� �ʿ䰡 �ִ�
	// ���� �ǿ����ڴ� �ڱ��ڽ�(this) �� �ǰ� ������ �ǿ����ڴ� right �Ű� ������ �ȴ�
	Complex operator+(const Complex& right)
	{
		// �Ǽ��ο� ����θ� ���� ���Ѵ�
		int real = this->real + right.real;
		int imag = this->imaginary + right.imaginary;

		// ����� ������ ���Ҽ� ��ü�� ��ȯ�Ѵ�
		// �Ǽ��ο� ����� ������ ���� �̿��ؼ� ���ο� ��ü�� ����� �� �ӽ� ��ü�� ���� ��ȯ�Ѵ�
		return Complex(real, imag);
	}

	// ���� ������ �����ε�
	Complex operator-(const Complex& right)
	{
		int real = this->real - right.imaginary;
		int imag = this->imaginary - right.imaginary;

		return Complex(real, imag);
	}

	////////////////////////////////////////////

	// �� ������ �ٽ��� ��ġ ����� ��ġ ������ ��츦 ������ �Լ��� ����ٴ� ���̴�
	// �׸��� ��ġ �������� �˸��� ���ؼ� int Ÿ���� �����ڸ� �ϳ� �ξ��ٴ� ���� �߿��ϴ�
	// ��� �Լ��� ����ؼ� �ǿ����ڰ� �ϳ��� �����ڵ��� �����ε��� ����
	// ��ġ �����ڸ� �����ε��� ���ó�� ���ڰ� ���� ������ ����ؾ� �ϰ�
	// ++, -- �� ��ġ ���길 �� ��Ģ���� ���ܰ� �Ǵ� ���̴�

	// ������ �����ε��� ��Ģ�� ���� �ڼ��Ѱ��� ���ͳ�, å 820p �� �����Ѵ�

	// ++c �� ��� (��ġ ����)
	// ++c �� ���� ���־��� �� �� �Լ��� ȣ��ȴ� ���ڰ� �ƹ��͵� ���ٴ� ���� �� ���� �ʿ䰡 �ִ�
	Complex operator++()
	{
		// ��ġ �����̹Ƿ� �ڱ� �ڽ��� ���� ���� ������Ų �Ŀ� ���� ��ȯ�Ѵ�
		// �Ǽ����� ���� ���� ���Ѵ�
		this->real++;

		// ���� ���� ��ȯ�Ѵ�
		return *this;
	}

	// c++�� ��� (��ġ ����)
	// c++ �� ���� ���־��� �� �� �Լ��� ȣ��ȴ�
	// int Ÿ���� �̸� ���� ���ڸ� ������ ���� �� ���ڰ� �ִ� �Լ��� ��ġ ������ �� �� ȣ��ȴ�
	Complex operator++(int)
	{
		// ��ġ �����̹Ƿ� �����Ǳ� ���� ���� ��ȯ�ϰ� �����ߴ�
		// ���� ���� ���� �����Ѵ�
		Complex prev(this->real, this->imaginary);

		// �Ǽ����� ���� ���Ѵ�
		this->real++;

		// ������ ���� ��ȯ�Ѵ�
		return prev;
	}

	// ������
	// �Ǽ��ο� ������� ���� ���ų� ���� �� �ִ� ������
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