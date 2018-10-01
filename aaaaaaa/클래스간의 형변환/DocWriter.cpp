#include "DocWriter.h"
#include <fstream> // ��������� �۾��� ���ؼ� ofstream Ŭ������ ����ؾ� �ϴµ� ���⼭ �� �غ� �Ѵ�
#include <iostream>

using namespace std;

DocWriter::DocWriter()
{
	_fileName = "NoName.txt";
	_content = "There is no content";

	cout << "DocWriter ������ ȣ��" << endl;
}

DocWriter::DocWriter(const string & filename, const string & content)
{
	_fileName = filename;
	_content = content;

	cout << "DocWriter ������ ȣ��" << endl;
}

DocWriter::~DocWriter()
{
	cout << "DocWriter �Ҹ��� ȣ��" << endl;
}

// ���� �̸��� ����
void DocWriter::SetFileName(const string & fileName)
{
	_fileName = fileName;
}

// ������ �ؽ�Ʈ�� ����
void DocWriter::SetContent(const string & content)
{
	_content = content;
}

// ���Ͽ� �ؽ�Ʈ�� �����Ų��
void DocWriter::Write()
{
	// ������ ����
	ofstream of(_fileName.c_str());

	// ������ ����� ����Ѵ�
	of << "# Content #\n\n";

	// �ؽ�Ʈ�� �ִ� �״�� �����Ѵ�
	of << _content;
}
