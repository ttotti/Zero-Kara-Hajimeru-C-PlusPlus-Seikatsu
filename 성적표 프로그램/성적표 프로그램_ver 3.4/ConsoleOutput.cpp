#include "ConsoleOutput.h"
#include <iostream>
#include <iomanip>

using namespace std;

ostream & ConsoleOutput::StdOut()
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return cout;
}

// ������
ConsoleOutput::ConsoleOutput()
{
}

// �Ҹ���
ConsoleOutput::~ConsoleOutput()
{
}

// ǥ�� ����ϱ� �����Ѵ�
// title ǥ�� ����
void ConsoleOutput::BeginTable(STR title)
{
	// ������ ����Ѵ�
	StdOut() << "\n\t\t\t" << title << endl;
}

// ǥ�� ����� ����Ѵ�
// (�ش���, ����� ����)
void ConsoleOutput::PutHeader(string headers[], int number)
{
	columns = number;

	for (int i = 0; i < number; ++i)
		StdOut() << setw(9) << headers[i];

	StdOut() << "\n";
}

// ǥ�� ���ڵ带 ����Ѵ�
// record ���ڵ� �� ����� �����͸� �ǹ��Ѵ�
void ConsoleOutput::PutRecord(string record[])
{
	for (int i = 0; i < columns; ++i)
		StdOut() << setw(9) << record[i];

	StdOut() << "\n";
}

// ǥ �׸��⸦ ��ģ��
void ConsoleOutput::EndTable()
{
	// �ϴ� �� ���� �׳� �� ĭ ����ش�
	StdOut() << "\n";
}

// ȭ�鿡 ���ڿ��� ����Ѵ�
void ConsoleOutput::Write(STR text)
{
	StdOut() << text << "\n";
}
