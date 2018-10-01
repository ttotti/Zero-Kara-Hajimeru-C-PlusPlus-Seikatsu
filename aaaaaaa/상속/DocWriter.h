#ifndef DOCWRITER_H
#define DOCWRITER_H

#include <string>

using namespace std;

class DocWriter
{
public:
	// ������
	DocWriter();
	DocWriter(const string& filename, const string& content);
	~DocWriter();

	// ���� �̸��� ����
	void SetFileName(const string& fileName);

	// ������ �ؽ�Ʈ�� ����
	void SetContent(const string& content);

	// ���Ͽ� �ؽ�Ʈ�� �����Ų��
	void Write();

protected:
	string _fileName;
	string _content;

};

#endif // !DOCWRITER_H

