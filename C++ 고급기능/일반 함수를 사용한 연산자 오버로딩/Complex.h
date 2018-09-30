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

	// �� �ڵ尡 �ǹ��ϴ� �ٴ� ������ ����
	// Complex operator+(const Complex& left, const Complex& right) �� ���� ������ ���� �Լ��� Complex Ŭ������ ģ���� ����ڴٴ� ���̴�
	// ģ���� ������ �Լ������� Complex Ŭ������ ��� ����� ������ �� �ְ� �ȴ�
	// �Ϲ� �Լ��� ����ؼ� �����ڸ� �����ε��� ���� �̷��� friend Ű���带 ����ؼ� �������ִ� ���� �Ϲ����̴�
	// ���� ���� ����� �ʿ䰡 ���ٸ� ������� �ʾƵ� ��� ����
	// friend Ű���带 ����Ͽ� ��� ������ ���� �����ϴ� ��� �����ڸ� ����ص� �ȴ�
	friend Complex operator+(const Complex& left, const Complex& right);

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