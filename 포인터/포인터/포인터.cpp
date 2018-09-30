#include <iostream>

using namespace std;

int main()
{
	char c = 'B';
	int i = 19;
	float f = 4.5f;

	cout << "c�� �ּ� = " << (int*)&c << endl;
	cout << "i�� �ּ� = " << &i << endl;
	cout << "f�� �ּ� = " << &f << endl << endl;

	//////////////////////////////////////////////////////////////////////////////////

	int a = 123; // �Ϲ����� ������ �����Ѵ�
	int *p; // ������ ������ �����Ѵ�

	p = &a; // ������ ���� p�� �Ϲݺ��� a�� �ּҸ� ����Ű���Ѵ�

	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;
	cout << "&p = " << &p << endl << endl;

	//////////////////////////////////////////////////////////////////////////////////

	// �������� ������� �׻� 4byte �̴�
	int q = 100;
	int* pq = &q;
	cout << "q�� ������: " << sizeof(q) << endl;
	cout << "pq�� ������: " << sizeof(pq) << endl;

	char w = 'A';
	char* pw = &w;
	cout << "w�� ������: " << sizeof(w) << endl;
	cout << "pw�� ������: " << sizeof(pw) << endl;

	double e = 10.0;
	double* pe = &e;
	cout << "e�� ������: " << sizeof(e) << endl;
	cout << "pe�� ������: " << sizeof(pe) << endl;

	short int r = 20;
	short int* pr = &r;
	cout << "r�� ������: " << sizeof(r) << endl;
	cout << "pr�� ������: " << sizeof(pr) << endl;

	bool t = true;
	bool* pt = &t;
	cout << "t�� ������: " << sizeof(t) << endl;
	cout << "pt�� ������: " << sizeof(pt) << endl;

	/*int u = 300;
	unsigned* y = &u;*/ // ����! �ʱ�ȭ�� int* ���� unsigned int* ���� ��ȯ�� �� �����ϴ�!

	return 0;
}