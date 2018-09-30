#include <iostream>
#include <bitset>

using namespace std;

struct Flags
{
	int a : 3; // ��Ʈ �ʵ� ����ü�� ����� �����ϴ� �޸� ������ ���ϴ� ���� �����Ҽ��ִ�
	int b : 4; // ��Ʈ �ʵ带 ����ϴ� ����� 
	bool c : 1;
	int : 5;
};

///////////////////////////////////////////////////////////////////////////////////

// 16��Ʈ Į�󿡼��� �� ���� ��Ÿ���� ����ü
struct Pixe116
{
	unsigned int blue : 5; // RGB�� ���� 5,6,5 ��Ʈ�� �����ϴ� ����ü�� ����
	unsigned int green : 6;
	unsigned int red : 5;
};

// Pixel16�� unsigned short�� ����� ���� ����ü
union Convert16 // unsigned short Ÿ���� ���� Pixel16 ����ü ������ ��ȯ�ϱ� ���� �뵵 ����ü
{
	Pixe116 pixel;
	unsigned short us;
};

int main()
{
	// �� ���� ������ �����ϴ� ����
	// (������ ���� �־�д�)
	unsigned short color = 0x1234;

	// unsigned short Ÿ���� ���� Pixe16 ����ü Ÿ���� ��ó��
	// �ٷ�� ���ؼ� ����ü�� ����Ѵ�
	Convert16 convert;
	convert.us = color; // convert.us �� color�� �����ϸ� ����ü�� ������ ����� pixel ���� ������ ����
						// ��������� us�� Ÿ���� unsigned short Ÿ�������� convert.pixel �� ���� ���� �� ���� ����ü Pixel16 Ÿ���� ��ó�� ����� �� �ִ�
	cout << "colot = " << bitset<16>(color) << "(" << color << ")" << endl;
	cout << "blue = " << bitset<16>(convert.pixel.blue) << "(" << convert.pixel.blue << ")" << endl;

	return 0;
}