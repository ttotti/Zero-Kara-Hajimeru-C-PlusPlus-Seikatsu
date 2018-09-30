#ifndef DOCWRITER_H
#define DOCWRITER_H

#include <string>

using namespace std;

class DocWriter
{
protected:
	string _fileName;
	string _content;

public:
	// 생성자
	DocWriter();
	DocWriter(const string& filename, const string& content);
	~DocWriter();

	// 파일 이름을 지정
	void SetFileName(const string& fileName);

	// 저장할 텍스트를 지정
	void SetContent(const string& content);

	// 파일에 텍스트를 저장시킨다
	virtual void Write();


};

#endif // !DOCWRITER_H

