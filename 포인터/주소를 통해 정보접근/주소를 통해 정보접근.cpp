#include <iostream>

using namespace std;

int main()
{
	int i = 123;
	int* p = &i;

	cout << "i = " << i << endl;
	cout << "*p = " << *p << endl; // '*p�� p�� ����Ű�� ��' ��� �ǹ� '&p�� p�� ����Ű�� �ּ�' ��� �ǹ�

	*p = 456;

	cout << "i = " << i << endl;
	cout << "*p = " << *p << endl << endl;

	//////////////////////////////////////////////////////////////////////////////////

	int a = 65;
	char* c = (char*)&a; // ���������� intŸ���� ������ charŸ������ ��ȯ�� �ּҸ� ����Ű�� �ߴ�

	cout << "a = " << a << endl;
	cout << "*c = " << *c << endl; // ��� �ƽ�Ű�ڵ�ǥ 65�� A�� ���Դ�

	int q = 0x12345678;
	char* pw = (char*)&q;

	//cout << hex;
	cout << "pw = " << (int)*pw << endl << endl; // 4����Ʈ�� 0x78 0x56 0x34 0x12(��Ʋ�����)�̷������� ������ִµ� pw�� Ÿ���� char*�̹Ƿ� 1����Ʈ�� ���븸 �������� �ȴ� ��� ����� 78

	//////////////////////////////////////////////////////////////////////////////////

	int o = 100;
	int* pi = &o;
	int* ppi = pi; // �����͸� ����Ű�� ������ ����

	cout << "t�� ��: " << o << endl;
	cout << "pi�� ��: " << *pi << endl;
	cout << "ppi�� ��: " << *ppi << endl;
	cout << "ppi�� ������: " << sizeof(ppi) << endl;

	*pi = 200;

	cout << "t�� ��: " << o << endl;
	cout << "pi�� ��: " << *pi << endl;
	cout << "ppi�� ��: " << *ppi << endl;

	return 0;
}