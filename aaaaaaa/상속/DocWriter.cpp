#include "DocWriter.h"
#include <fstream> // 파일입출력 작업을 위해서 ofstream 클래스를 사용해야 하는데 여기서 그 준비를 한다
#include <iostream>

using namespace std;

DocWriter::DocWriter()
{
	_fileName = "NoName.txt";
	_content = "There is no content";

	cout << "DocWriter 생성자 호출" << endl;
}

DocWriter::DocWriter(const string & filename, const string & content)
{
	_fileName = filename;
	_content = content;

	cout << "DocWriter 생성자 호출" << endl;
}

DocWriter::~DocWriter()
{
	cout << "DocWriter 소멸자 호출" << endl;
}

// 파일 이름을 지정
void DocWriter::SetFileName(const string & fileName)
{
	_fileName = fileName;
}

// 저장할 텍스트를 지정
void DocWriter::SetContent(const string & content)
{
	_content = content;
}

// 파일에 텍스트를 저장시킨다
void DocWriter::Write()
{
	// 파일을 연다
	ofstream of(_fileName.c_str());

	// 간단한 헤더를 출력한다
	of << "# Content #\n\n";

	// 텍스트를 있는 그대로 저장한다
	of << _content;
}
