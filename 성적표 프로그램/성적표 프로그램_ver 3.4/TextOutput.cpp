#include "TextOutput.h"

// ostream ��ü�� ��ȯ�Ѵ�
// ��ȯ�� : ostream ��ü�� fout�� ��ȯ�Ѵ�
// ��) out �����Ͱ� TextOutput ��ü�� ����Ű�� �ִٰ� �����ϰ� ShowAll()�Լ��� out->BeginTable()�� ȣ���ϸ�
// TextOutput::BeginTable() �Լ��� ȣ��Ǵ°��� �̷л� �Ǵ�
// ������ TextOutput���� ���� �Լ��� �������� �����Ƿ� ConsoleOutput Ŭ�����κ��� ��ӹ��� ConsoleOutput::BeginTable() �Լ��� ȣ��ȴ�
// BeginTable() �Լ��� StdOut()�� ���� ��ȯ�� ��ü�� ���ڿ��� ����ϴ� ����� ������ �ִµ�
// ���⼭ StdOut()�� �����Լ��̱� ������ ConsoleOutput::BeginTable()�� �ƴ� TextOutput::BeginTable() �� ȣ��ȴ�
// StdOut()�� ���ؼ� ��ȯ�Ǵ� ��ü�� ofstream Ŭ���� Ÿ���� ��ü�� �ǰ� ���ڿ��� �ؽ�Ʈ ���Ͽ� ��µȴ�
// ������ �ٸ� �Լ��� ������ ��Ŀ�������� �����Ѵ�
// �̰� �о ���ذ� �ߵ����ʴ´ٸ� ���ͳ�(Ű����: ostream �� ofstream�� ���)�̳� c++å 771~775p�� ��������
ostream & TextOutput::StdOut()
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return fout;
} 

TextOutput::TextOutput(STR filename)
{
	// ������ �����Ѵ�
	fout.open(filename.c_str());
}

TextOutput::~TextOutput()
{
	// ������ �ݴ´�
	fout.close();
}
