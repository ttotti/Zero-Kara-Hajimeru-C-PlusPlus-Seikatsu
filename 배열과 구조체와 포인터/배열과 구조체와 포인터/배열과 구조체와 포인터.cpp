#include <iostream>

using namespace std;

int main()
{
	int array[10]; // �迭����

	int* p = &array[5]; // ������ p�� array[5]�� ����Ű���Ѵ�

	cout << "p = " << p << endl;
	cout << "&array[5] = " << &array[5] << endl; // ����� ������ p �� �迭 array[5]�� �ּҰ� ����

	p++; // �迭�� ������ �������� ��� �����Ϳ� +1�� ���ָ� ���� ���Ҹ� �����Ѷ� ��� �ǹ̰� �ȴ�

	cout << "p = " << p << endl;
	cout << "&array[6] = " << &array[6] << endl << endl; // ����� ����

	////////////////////////////////////////////////////////

	int iArray[10];

	int* pi = &iArray[3]; // int�� 4����Ʈ�� ���ϰ� ����

	cout << "pi = " << pi << endl;
	cout << "pi + 1 = " << pi + 1 << endl;
	cout << "pi + 2 = " << pi + 2 << endl;
	cout << "pi - 1 = " << pi - 1 << endl;

	short sArray[10];
	short* ps = &sArray[3]; // shoat�� 2����Ʈ�� ���ϰ� ����

	cout << "ps = " << ps << endl;
	cout << "ps + 1 = " << ps + 1 << endl;
	cout << "ps + 2 = " << ps + 2 << endl;
	cout << "ps - 1 = " << ps - 1 << endl;

	int sArrays[10];
	int* ps1 = &sArrays[3];
	int* ps2 = &sArrays[7];

	cout << "ps1 = " << ps1 << endl;
	cout << "ps2 = " << ps2 << endl;
	cout << "ps2 - ps1= " << ps2 - ps1 << endl; // �����Ͱ��� ������ �� �����Ͱ� ����Ű�� ���� ���̿� ��� ���Ұ� �ִ����� ��ȯ�Ѵ�

	return 0;
}