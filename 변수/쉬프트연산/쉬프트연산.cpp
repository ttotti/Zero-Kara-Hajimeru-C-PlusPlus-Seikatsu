#include <iostream>

using namespace std;

int main()
{
	int i;

	cout << "���� �Է��Ͻÿ�: ";
	cin >> i;

	i = i << 2; // ���� ����Ʈ������ * 2^x�� ȿ���� �ִ�

	cout << i << endl;

	i = i >> 2; // �ݴ�� ������ ����Ʈ������ / 2^x�� ȿ���� �ִ�

	cout << i << endl;

	return 0;
}