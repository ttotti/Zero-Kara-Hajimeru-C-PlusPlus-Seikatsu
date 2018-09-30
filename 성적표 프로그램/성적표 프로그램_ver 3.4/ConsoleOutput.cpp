#include "ConsoleOutput.h"
#include <iostream>
#include <iomanip>

using namespace std;

ostream & ConsoleOutput::StdOut()
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return cout;
}

// 생성자
ConsoleOutput::ConsoleOutput()
{
}

// 소멸자
ConsoleOutput::~ConsoleOutput()
{
}

// 표를 출력하기 시작한다
// title 표의 제목
void ConsoleOutput::BeginTable(STR title)
{
	// 제목을 출력한다
	StdOut() << "\n\t\t\t" << title << endl;
}

// 표의 헤더를 출력한다
// (해더들, 헤더의 개수)
void ConsoleOutput::PutHeader(string headers[], int number)
{
	columns = number;

	for (int i = 0; i < number; ++i)
		StdOut() << setw(9) << headers[i];

	StdOut() << "\n";
}

// 표와 레코드를 출력한다
// record 레코드 한 사람의 데이터를 의미한다
void ConsoleOutput::PutRecord(string record[])
{
	for (int i = 0; i < columns; ++i)
		StdOut() << setw(9) << record[i];

	StdOut() << "\n";
}

// 표 그리기를 마친다
void ConsoleOutput::EndTable()
{
	// 하는 일 없음 그냥 한 칸 띄워준다
	StdOut() << "\n";
}

// 화면에 문자열을 출력한다
void ConsoleOutput::Write(STR text)
{
	StdOut() << text << "\n";
}
