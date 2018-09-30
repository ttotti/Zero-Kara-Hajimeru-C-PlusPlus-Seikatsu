#ifndef HTMLOUTPUT_H
#define HTMLOUTPUT_H

#include "BaseOutput.h"
#include <fstream>

using namespace std;

class HTMLOutput :public BaseOutput
{
protected:
	int columns;
	ofstream fout;

public:
	HTMLOutput(STR filename);
	virtual ~HTMLOutput();

	virtual void BeginTable(STR title);
	virtual void PutHeader(string headers[], int number);
	virtual void PutRecord(string record[]);
	virtual void EndTable();
	virtual void Write(STR text);
};

#endif // !HTMLOUTPUT_H

