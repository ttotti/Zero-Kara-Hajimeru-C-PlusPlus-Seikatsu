#include <iostream>
#include <cmath>

using namespace std;

class Point // Point Ŭ������ �����Ѵ� // Ŭ������ ���õ� ����(����)�� �ൿ(�Լ�) �� ��Ƴ������̴�
{
public: // ���� ����� ���õ� Ű����
	int x, y; // ��� ����

	void Print() // ��� �Լ�
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}

	float DistanceFromOrigin(); // �Լ� ������ ���ܳ��´� // Ŭ���� �ڵ尡 ��������
};

float Point :: DistanceFromOrigin() // Ŭ���� ���� �ۿ��� ���� ���� ������(::)�� ����ؼ� �Լ��� �����Ѵ�
{
	//return sqrt(float(x*x) + float(y*y));
	return sqrt(pow(x, 2) + pow(y, 2));
}

int main()
{
	// ��ü�� �����Ѵ�
	Point pt1, pt2; // ���������� ���� �� Ŭ������ ����� ���� Ÿ���̴� �׸��� ��ü�� Ŭ���� Ÿ���� ����ؼ� ������ �����̴�

	// pt1�� pt2�� �ʱ�ȭ �Ѵ�
	pt1.x = 100;
	pt1.y = 100;
	pt2.x = 200;
	pt2.y = 200;


	// pt1�� pt2�� ������ ����Ѵ�
	pt1.Print();
	pt2.Print();

	Point pt3 = pt1; // �̹� ������ ��ü pt1�� ���ؼ� pt3�� �ʱ�ȭ �Ѵ� (�ʱ�ȭ)
	pt3.Print();

	pt3 = pt2; // ���� ���� ������� pt2�� ���� �Ѵ� (����) // �ʱ�ȭ �� ������ ���� �ٸ� �����̴�
	pt3.Print();

	pt3 = pt2 = pt1;
	pt3.Print();

	Point c = { 3,4 };
	cout << c.DistanceFromOrigin() << endl;

	return 0;
}
