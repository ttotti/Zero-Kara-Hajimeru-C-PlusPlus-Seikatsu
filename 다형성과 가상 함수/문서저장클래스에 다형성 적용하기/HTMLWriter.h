#ifndef HTMLWriter_H
#define HTMLWriter_H

// DocWriter 클래스를 상속받기 위해 헤더파일을 포함한다
#include "DocWriter.h"

// DocWriter 클래스를 상속받는 방법을 보여준다
class HTMLWriter :public DocWriter
{
protected:
	string _fontName;
	int _fontSize;
	string _fontColor;

public:
	HTMLWriter();
	// 인자가 있는 생성자를 추가했다 DocWriter 클래스의 생성자로 전달해주려고 한다
	HTMLWriter(const string& fileName, const string& content);
	~HTMLWriter();

	// 텍스트를 파일로 저장시킨다
	// 부모 클래스에 virtual 의 키워드가 있다면 안붙여도 되지만 붙이는게 일반적이다
	virtual void Write();
	

	// 폰트와 사이즈, 색상을 지정한다
	void SetFont(const string& fontName, int fontSize, const string& fontColor);

};

#endif // !HTMLWriter_H

