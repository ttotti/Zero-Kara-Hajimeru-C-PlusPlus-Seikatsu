#include "Point.h"
#include <iostream>

using namespace std;

int main()
{
	// �ʱ�ȭ������ ��ü�� �����д�
	Point pt(50, 50);

	// �������� ��ü�� �����Ѵ�
	Point* p1 = new Point(); // new �����ڷ� �Ҵ��� �� �����ڰ� ȣ��ȴ�!
	Point* p2 = new Point(100,100);
	Point* p3 = new Point(pt);

	// ��ü���� ������ ����Ѵ�
	p1->Print(); // (*p1).Print()
	p2->Print();
	p3->Print();

	cout << sizeof(p1) << ", " << sizeof(p2) << ", " << sizeof(pt) << endl;

	// �������� ������ ��ü���� �����Ѵ�
	delete p1; // delete �����ڷ� ������ �� �Ҹ��ڰ� ȣ��ȴ�!
	delete p2;
	delete p3;
	p1 = p2 = p3 = 0;

	return 0;
}