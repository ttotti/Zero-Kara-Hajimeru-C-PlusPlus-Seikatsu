#include "DocWriter.h"
#include "HTMLWriter.h"

int main()
{
	// �ڽ� ��ü ����
	HTMLWriter hw("test.html", "Lim-ttotti");

	// �θ�Ŭ������ �����ͷ� �ڽ� ��ü ����Ų��
	DocWriter* pdw = &hw;

	// �����͸� ����ؼ� ���� �Լ� ȣ��
	// �ڽİ�ü�� ����Ų �����Ͱ� ����� �ϴµ� �θ�Ŭ������ �ִ� ����Լ��� ȣ��Ǿ���
	// �̷���� �����Լ��� �����ϸ� �ذ�ȴ�
	pdw->Write();

	return 0;
}