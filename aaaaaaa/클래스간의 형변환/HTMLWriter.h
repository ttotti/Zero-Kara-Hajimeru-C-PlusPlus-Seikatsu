#ifndef HTMLWriter_H
#define HTMLWriter_H

// DocWriter Ŭ������ ��ӹޱ� ���� ��������� �����Ѵ�
#include "DocWriter.h"

// DocWriter Ŭ������ ��ӹ޴� ����� �����ش�
class HTMLWriter :public DocWriter
{
public:
	HTMLWriter();
	// ���ڰ� �ִ� �����ڸ� �߰��ߴ� DocWriter Ŭ������ �����ڷ� �������ַ��� �Ѵ�
	HTMLWriter(const string& fileName, const string& content);
	~HTMLWriter();

	// �ؽ�Ʈ�� ���Ϸ� �����Ų��
	void Write();

	// ��Ʈ�� ������, ������ �����Ѵ�
	void SetFont(const string& fontName, int fontSize, const string& fontColor);

protected:
	string _fontName;
	int _fontSize;
	string _fontColor;
};

#endif // !HTMLWriter_H

