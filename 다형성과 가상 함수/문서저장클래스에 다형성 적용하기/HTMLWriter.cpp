#include "HTMLWriter.h"
#include <fstream>
#include <iostream>

using namespace std;

HTMLWriter::HTMLWriter()
{
	_fileName = "NoName.html";
	
	_fontName = "굴림";
	_fontSize = 3;
	_fontColor = "black";

	cout << "HTML 생성자 호출" << endl;
}

// 초기화 리스트를 사용해서 부모클래스의 생성자를 호출한다 이때 부모클래스의 이름을 사용한다
// 포함의 경우 객체의 이름을 사용했다
// 여기서 부모클래스의 생성자가 먼저 호출이되고 그 다음 자식클래스가 호출이된다 (부모클래스 호출 -> 자식클래스 호출)
// 그러므로 소멸자의 호출순서는 그 반대가 된다 (자식클래스 소멸 -> 부모클래스 소멸)
HTMLWriter::HTMLWriter(const string & fileName, const string & content)
	:DocWriter(fileName, content)
{
	_fontName = "굴림";
	_fontSize = 3;
	_fontColor = "black";

	cout << "HTML 생성자 호출" << endl;
}

HTMLWriter::~HTMLWriter()
{
	cout << "HTML 소멸자 호출" << endl;
}

void HTMLWriter::Write()
{
	// 파일에 텍스트를 저장시킨다
	ofstream of(_fileName.c_str());

	// HTML 헤더 부분을 저장한다
	of << "<HTML><HEAD><TITLE>This document was generated by HTMLWriter</TITLE> </HEAD><BODY>";
	of << "<H1>Content</H1>";

	// 폰트 태그를 시작한다
	of << "<Font name='" << _fontName << " size='" << _fontSize << "color='" << _fontColor << "'>";

	// 텍스트를 저장한다
	of << _content;
	
	// 폰트 태그를 닫는다
	of << "</FONT>";

	// HTML을 마무리 한다
	of << "</BODY></HTML>";
}

// 폰트를 지정한다
void HTMLWriter::SetFont(const string & fontName, int fontSize, const string & fontColor)
{
	_fontName = fontName;
	_fontSize = fontSize;
	_fontColor = fontColor;
}
