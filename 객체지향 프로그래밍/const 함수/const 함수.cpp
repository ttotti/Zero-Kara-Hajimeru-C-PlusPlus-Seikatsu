#include <iostream>
#include "Point.h"

using namespace std;

void Area(const Point& pt);

int main()
{
	Point pt(-50, 200);

	pt.Print();

	return 0;
}

// ��ü�� ���ڷ� �ѱ涧 const Point& �� ���� const Ÿ���� ���۷����� �ѱ�°��� �Ϲ����̴�(�Լ������� ��ü�� ��������� ���� ������ ���� �������)
// Area() �Լ��� ��������� ���� ���������� �б⸸ �� ���̱� ������ const Point& �� ���ִ� ���� ���� Ÿ���ϴ�
// ���п� �Ű� ���� pt�� const ��ü�� �Ǿ��� 
// const ��ü�� ����ؼ� const�� �ƴ� ��������� ȣ���ϴ� ���� �Ұ����ϴ�.. �� GetY()�� const�� �ƴϹǷ� ȣ���� �� ����
// ������ ��� ��� �Լ��� const�� ������
void Area(const Point& pt)
{
	int area = pt.GetX()*pt.GetY();

	cout << "(0, 0)�� �� ���� �̷�� �簢���� ���� = " << area << endl;
}