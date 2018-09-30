#include "Color.h"
#include <iostream>

using namespace std;

int main()
{
	//------------------------------
	// Color Ŭ������ �⺻ ��� ���
	//------------------------------

	// ����Ʈ �����ڸ� ����ؼ� �����Ѵ�
	Color c1;
	c1.Print(); // ���� Ȯ��

	// ���ڰ� �ִ� �����ڸ� ����ؼ� �����Ѵ�
	Color c2(100, 100, 100);
	c2.Print(); // ���� Ȯ��

	// c2�� R ��Ҹ� �����Ѵ�
	c2.SetR(255);
	c2.Print(); // ���� Ȯ��

	// c2�� R ��Ҹ� Ȯ���Ѵ�
	cout << "c2.R = " << (int)c2.GetR() << endl;

	// c2�� ��ü ��⸦ 50��ŭ ������Ų��
	c2.AdjustBright(50);
	c2.Print(); // ���� Ȯ��

	// c2�� ������ 32��Ʈ ������ ����Ѵ�
	Color::color32_t color = c2.GetColor32();
	cout << "c2 = " << color << endl;

	// c1�� ������ 32��Ʈ ������ ����Ѵ�
	c1.SetColor32(color);
	c1.Print(); // ���� Ȯ��

	//-----------------
	// ���� ����� ���
	//-----------------

	// ������ ��ü�� �� Ȯ��
	Color::Red.Print();

	// ��ü�� ���������� �ʱ�ȭ �Ѵ�
	Color c3 = Color::Red;
	c3.Print(); // ���� Ȯ��
	
	return 0;
}