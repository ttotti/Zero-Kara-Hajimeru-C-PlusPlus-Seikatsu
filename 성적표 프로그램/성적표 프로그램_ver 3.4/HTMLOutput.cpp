#include "HTMLOutput.h"
#include <iostream>
#include <iomanip>

using namespace std;

// ��ü������ ���� ������ HTML �� ����Ͽ� ����ϴ°Źۿ� ����

// ������
// filename �����̸�
HTMLOutput::HTMLOutput(STR filename)
{
	columns = 0;

	// ������ ���� �⺻ �±׸� �߰��Ѵ�
	fout.open(filename.c_str());

	fout << "<HTML><HEAD><TITLE>Lim-ttotti Good!!</TITLE></HEAD><BODY><CENTER>";
}

HTMLOutput::~HTMLOutput()
{
	// ������ �±׸� �ְ�
	// ������ �ݴ´�
	fout << "</CENTER></BODY></HTML>";
	fout.close();
}

// ǥ�� ����ϱ� �����Ѵ�
void HTMLOutput::BeginTable(STR title)
{
	// Ÿ��Ʋ�� ����Ѵ�
	fout << "<H3>" << title << "</H3>";

	// ���̺� ���� �±׸� �ִ´�
	fout << "<TABLE bgcolor='slategray' cellspacing='1' cellpadding='4' border='0'>";
}

// ǥ�� ����� ����Ѵ�
void HTMLOutput::PutHeader(string headers[], int number)
{
	// ����� ������ �����Ѵ�
	columns = number;

	// �±׿� �Բ� ����� �����Ѵ�
	fout << "<TR bgcolor='#e0e0ff' align='center'>";
	for (int i = 0; i < number; ++i)
		fout << "<TD>" << headers[i] << "</TD>";
	fout << "</TD>";
}

// ǥ�� ���ڵ带 ����Ѵ�
void HTMLOutput::PutRecord(string record[])
{
	fout << "<TR bgcolor='white' align='right'>";
	for (int i = 0; i < columns; ++i)
		fout << "<TD>" << record[i] << "</TD>";
	fout << "</TR>";
}

// ǥ �׸��⸦ ��ģ��
void HTMLOutput::EndTable()
{
	// ���̺� ���� �±׸� �ִ´�
	fout << "</TABLE>";
}

// ȭ�鿡 ���ڿ��� ����Ѵ�
void HTMLOutput::Write(STR text)
{
	fout << "<P>" << text << "</P>";
}
