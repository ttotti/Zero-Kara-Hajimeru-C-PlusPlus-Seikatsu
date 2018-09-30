#include "Point.h"
#include <iostream>

using namespace std;

class Example
{
public:
	static void count();
};

// void XX() ������ �Լ��� ���� ������
typedef void(*FP1)(int); // ����� �ƴ� �Լ�
// void Point::XX() ������ �Լ��� ���� ������
typedef void(Point::*FP2)(int); // PointŬ������ ��� �Լ�
typedef void(Point::*FP3)() const; // ����ų���� �ϴ� Print() �� const �Ӽ��̹Ƿ� �Լ������͸� �����Ҷ� �ڿ� const�� �ٿ��ش�

typedef void(*FP)();

int main()
{
	Point pt(50, 50);

	// FP1 fp1 = &Point::SetX; // ����
	FP2 fp2 = &Point::SetX;
	(pt.*fp2)(100); // pt ��ü�� ����ؼ� fp2�� ����Ű�� �Լ��� ȣ���Ѵ� // �������� �켱 ���� ������ pt.*fp2�� ��ȣ�� �����־�� �Ѵ�

	FP fp3 = &Example::count; // Ŭ���� Example�� ���� �Լ��� ����Ű�� �Լ������� // �����Լ��� void XX() ������ �Լ������͸� �����ִ�
	(fp3)(); // ���� �Լ��� � ��ü�� ����Լ��� ȣ������ �������ʰ� �׳� ȣ���� �����ϴ�

	FP3 fp4 = &Point::Print;
	(pt.*fp4)(); //pt.Print();

	return 0;
}

void Example::count()
{
	cout << "fp3 �Լ������� ���!" << endl;
}
