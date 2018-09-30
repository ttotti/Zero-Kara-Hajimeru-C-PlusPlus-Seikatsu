#include "HTMLOutput.h"
#include "MyException.h"
#include <iostream>
#include <iomanip>

using namespace std;

// 전체적으로 얻은 정보를 HTML 언어를 사용하여 출력하는거밖에 없다

// 생성자
// filename 파일이름
HTMLOutput::HTMLOutput(STR filename)
{
	columns = 0;

	// 파일을 열고 기본 태그를 추가한다
	fout.open(filename.c_str());

	// 파일을 여는데 실패한 경우 예외를 던진다.
	if (false == fout.is_open())
		throw MyException(filename + "을 열 수 없습니다.");

	fout << "<HTML><HEAD><TITLE>Lim-ttotti Good!!</TITLE></HEAD><BODY><CENTER>";
}

HTMLOutput::~HTMLOutput()
{
	// 마무리 태그를 넣고
	// 파일을 닫는다
	fout << "</CENTER></BODY></HTML>";
	fout.close();
}

// 표를 출력하기 시작한다
void HTMLOutput::BeginTable(STR title)
{
	// 타이틀을 출력한다
	fout << "<H3>" << title << "</H3>";

	// 테이블 시작 태그를 넣는다
	fout << "<TABLE bgcolor='slategray' cellspacing='1' cellpadding='4' border='0'>";
}

// 표의 헤더를 출력한다
void HTMLOutput::PutHeader(string headers[], int number)
{
	// 헤더의 개수를 보관한다
	columns = number;

	// 태그와 함께 헤더를 삽입한다
	fout << "<TR bgcolor='#e0e0ff' align='center'>";
	for (int i = 0; i < number; ++i)
		fout << "<TD>" << headers[i] << "</TD>";
	fout << "</TD>";
}

// 표의 레코드를 출력한다
void HTMLOutput::PutRecord(string record[])
{
	fout << "<TR bgcolor='white' align='right'>";
	for (int i = 0; i < columns; ++i)
		fout << "<TD>" << record[i] << "</TD>";
	fout << "</TR>";
}

// 표 그리기를 마친다
void HTMLOutput::EndTable()
{
	// 테이블 마감 태그를 넣는다
	fout << "</TABLE>";
}

// 화면에 문자열을 출력한다
void HTMLOutput::Write(STR text)
{
	fout << "<P>" << text << "</P>";
}
