#ifndef TEXTOUTPUT_H
#define TEXTOUTPUT_H

#include "ConsoleOutput.h"
#include <fstream>

using namespace std;

// �ؽ�Ʈ�� ����ϴ� ���� Console Ŭ������ HTML Ŭ���� ó�� Ŭ������ ���� ������ �� ������ ����� �ִ�
// �ٷ� ConsoleOutput Ŭ������ ��ӹ޴°��̴�
// �ܼ� â�� ���� ����Ҷ� ����ϴ� cout ��ü�� ostream Ŭ���� Ÿ���̴�
// �׸��� ���Ͽ� ���� ����Ҷ��� ofstream Ŭ������ ����Ѵ�
// �߿��Ѱ��� �� �� Ŭ������ �θ� �ڽ� ���迡 �ִ� ostream Ŭ������ ofstream�� �θ� Ŭ������ �ǰ� �������� ����ؼ� �� Ŭ������ �ٷ���� �ִ�
// �� ostream Ŭ���� ��ü cout�� ���� ����ϴ� �ڵ� �״�� ����ؼ� ofstream ��ü�� ���� ����ϰ� ���� �� �ִ�
class TextOutput :public ConsoleOutput
{
protected:
	ofstream fout;

protected:
	virtual ostream& StdOut();

public:
	TextOutput(STR filename);
	virtual ~TextOutput();
};

#endif // !TEXTOUTPUT_H

