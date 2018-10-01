//#include "DocWriter.h"
#include "HTMLWriter.h"

#include <iostream>

using namespace std;

// DocWriter 에서 웹브라우저로 파일을 만드는것과 폰트를 지정하는 기능이 추가되었다
// 각 클래스의 메모리 구조를 보면
// DocWriter 객체에는 _fileName, _content 멤버가 있고
// HTMLWriter 객체에는 _fileName, _content, _fontName, _fontSize, _fontColor 멤버가 있다(DocWriter 클래스를 상속)
// DocWriter 부모클래스 HTMLWriter 자식클래스

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

	// DocWriter 객체의 크기는 56, HTMLWriter 객체의 크기는 116
	// 자식클래스는 부모클래스의 모든 멤버를 소유하므로 당연히 크기가 커진다
	cout << sizeof(dw) << ", " << sizeof(hw) << endl;

	cout << endl;

	return 0;
}