#ifndef HTMLWriter_H
#define HTMLWriter_H

// DocWriter Ŭ������ ��ӹޱ� ���� ��������� �����Ѵ�
#include "DocWriter.h"

// DocWriter Ŭ������ ��ӹ޴� ����� �����ش�
class HTMLWriter :public DocWriter
{
protected:
	string _fontName;
	int _fontSize;
	string _fontColor;

public:
	HTMLWriter();
	// ���ڰ� �ִ� �����ڸ� �߰��ߴ� DocWriter Ŭ������ �����ڷ� �������ַ��� �Ѵ�
	HTMLWriter(const string& fileName, const string& content);
	~HTMLWriter();

	// �ؽ�Ʈ�� ���Ϸ� �����Ų��
	// �θ� Ŭ������ virtual �� Ű���尡 �ִٸ� �Ⱥٿ��� ������ ���̴°� �Ϲ����̴�
	virtual void Write();
	

	// ��Ʈ�� ������, ������ �����Ѵ�
	void SetFont(const string& fontName, int fontSize, const string& fontColor);

};

#endif // !HTMLWriter_H

