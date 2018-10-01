//#include "DocWriter.h"
#include "HTMLWriter.h"

#include <iostream>

using namespace std;

// DocWriter ���� ���������� ������ ����°Ͱ� ��Ʈ�� �����ϴ� ����� �߰��Ǿ���
// �� Ŭ������ �޸� ������ ����
// DocWriter ��ü���� _fileName, _content ����� �ְ�
// HTMLWriter ��ü���� _fileName, _content, _fontName, _fontSize, _fontColor ����� �ִ�(DocWriter Ŭ������ ���)
// DocWriter �θ�Ŭ���� HTMLWriter �ڽ�Ŭ����

int main()
{
	DocWriter dw;

	dw.SetFileName("test.txt");
	dw.SetContent("You must be a good programmer~~!");
	dw.Write();

	////////////////////////////////////////

	HTMLWriter hw;

	hw.SetFileName("test.html");
	hw.SetContent("ttotti Hello HTML !");
	hw.SetFont("Arial", 16, "blue");
	hw.Write();

	///////////////////////////////////////////

	HTMLWriter hw2("ttotti.html", "Welcome ttotti");

	hw2.Write();

	///////////////////////////////////////

	// DocWriter ��ü�� ũ��� 56, HTMLWriter ��ü�� ũ��� 116
	// �ڽ�Ŭ������ �θ�Ŭ������ ��� ����� �����ϹǷ� �翬�� ũ�Ⱑ Ŀ����
	cout << sizeof(dw) << ", " << sizeof(hw) << endl;

	cout << endl;

	return 0;
}