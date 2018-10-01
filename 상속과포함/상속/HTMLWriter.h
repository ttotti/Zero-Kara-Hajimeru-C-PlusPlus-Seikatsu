#ifndef HTMLWriter_H
#define HTMLWriter_H

// DocWriter 클래스를 상속받기 위해 헤더파일을 포함한다
#include "DocWriter.h"

// DocWriter 클래스를 상속받는 방법을 보여준다
class HTMLWriter :public DocWriter
{
public:
	HTMLWriter();
	// 인자가 있는 생성자를 추가했다 DocWriter 클래스의 생성자로 전달해주려고 한다
	HTMLWriter(const string& fileName, const string& content);
	~HTMLWriter();

	// 텍스트를 파일로 저장시킨다
	void Write();

	// 폰트와 사이즈, 색상을 지정한다
	void SetFont(const string& fontName, int fontSize, const string& fontColor);

protected:
	string _fontName;
	int _fontSize;
	string _fontColor;
};

#endif // !HTMLWriter_H

