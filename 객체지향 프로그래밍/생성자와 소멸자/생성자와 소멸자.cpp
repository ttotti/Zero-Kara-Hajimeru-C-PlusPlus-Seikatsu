#include <iostream>

using namespace std;

// Point Ŭ������ �����Ѵ�
class Point
{
public:
	int x, y; // �������

	void Print(); // ����Լ�

	
	Point(); // ������ ���� // �����ڴ� Ŭ���� �ȿ����� ���ǰ� �����ϴ� // ����Ʈ ������
	Point(int initialX, int initialY); // ���ڰ� �ִ� ������
	Point(const Point& pt); // ���� ������ // ���� �����ڴ� �ڱ� �ڽ��� Ÿ�Կ� ���� ���۷����� ���ڷ� �޴� �����ڴ�
};

// �����ڸ� �����ϰ� �ִ� // �����ڿ��� �ϴ� ���� ���� x y �� 0���� �ʱ�ȭ �ϴ� ���̴�
Point::Point()
{
	cout << "����Ʈ ������ ȣ��!" << endl;
	x = 0;
	y = 0;
}

// ���ڰ� �ִ� �����ڸ� �����ϰ� �ִ� // ���ڷ� �Ѿ�� ���� ����ؼ� x y�� �ʱ�ȭ �Ѵ�
Point::Point(int initialX, int initialY)
{
	cout << "���ڰ� �ִ� ������ ȣ��!" << endl;
	x = initialX;
	y = initialY;
}

Point::Point(const Point& pt)
{
	cout << "���� ������ ȣ��!" << endl;
	x = pt.x;
	y = pt.y;
}

void Point::Print()
{
	cout << "(" << x << ", " << y << ")" << endl;
}

///////////////////////////////////////////

class String
{
private:
	char* p;

public:
	String(char c[100]);
	String(const String& s);
	String(const String& s,int i);

	int size() const
	{
		return strlen(p);
	}

	void print();
};

String::String(char c[100])
{
	p = c;
}

// ���� �����ڰ� �ܼ��� 1:1 ���縸 �ϴ� ��� // ���� �ּ��� ���ڿ��� �����Ѵ� // ��������
// ������ �� �ּҸ� �����ؾ��ϴ� ��� �� �ּҸ� �ΰ� �̻��� ������ �����ϰ� �ִµ� ������ �ϳ��� �ϱ� ������ �ٸ� �������� �̹� ������ �ּҸ� �����ϰ� �ִ� ���� �ȴ�(�Ҹ��ڸ� �����Ѵ�)
String::String(const String& s)
{
	cout << "���������1 ȣ��" << endl;
	p = s.p;
}

// ���� �����ڰ� ���ڿ��� �������ִ� ��� // ���� �ٸ� �ּ��� ���ڿ��� ������ �ִ� // ��������
// ���� ������ �ذ����ش�
String::String(const String& s,int i)
{
	cout << "���������2 ȣ��" << endl;
	p = new char[s.size() + 1];
	strcpy(p, s.p);
}

void String::print()
{
	cout << p << endl;
	cout << &p << endl;
}

int main()
{
	Point pt1; // Point Ŭ������ ��ü�� �����Ѵ� // ��ü�� �����Ǹ� �ڵ����� �����ڸ� ȣ���Ѵ�
	Point pt2(3, 5); // ���ڰ� �ִ� Point Ŭ���� �����ڸ� �����Ѵ� // �����ڴ� ���ǵ� �ñ״�ó�� ���� � �����ڸ� ȣ������ ��������(�����ε�)

	pt1.Print();
	pt2.Print();

	Point pt3 = pt1; // �ٸ� ��ü�� ����ؼ� �ʱ�ȭ�ϴ� ��� ���� �����ڰ� ȣ��ȴ� // �̶� ����������� ���ڴ� pt1�� �ȴ�
	pt3.Print();

	pt3 = pt2; // �ٸ� ��ü�� ����ؼ� �����ϴ� ���� ���� �����ڰ� ȣ����� �ʴ´�
	pt3.Print();

	cout << endl;

	////////////////////////////////////

	String str1("Hello Class!");
	str1.print();

	String str2 = str1;
	str2.print();

	String str3(str1, 0);
	str3.print();



	return 0;
}
