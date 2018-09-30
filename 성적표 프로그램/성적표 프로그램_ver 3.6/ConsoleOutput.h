#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H

#include "BaseOutput.h"

class ConsoleOutput :public BaseOutput
{
protected:
	// 가상함수이기에 이 코드는 this->StdOut()을 줄여놓은거나 마찬가지다
	virtual ostream& StdOut();

protected:
	int columns; // 헤더의 개수

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

