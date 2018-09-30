#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H

#include "BaseOutput.h"

class ConsoleOutput :public BaseOutput
{
protected:
	// �����Լ��̱⿡ �� �ڵ�� this->StdOut()�� �ٿ������ų� ����������
	virtual ostream& StdOut();

protected:
	int columns; // ����� ����

public:
	ConsoleOutput();
	virtual ~ConsoleOutput();

	virtual void BeginTable(STR title);
	virtual void PutHeader(string headers[], int number);
	virtual void PutRecord(string record[]);
	virtual void EndTable();
	virtual void Write(STR text);
};

#endif // !CONSOLEOUTPUT_H

