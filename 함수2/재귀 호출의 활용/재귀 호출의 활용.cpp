// 10������ ���� 2������ �ٲٴ� �Լ�
#include <iostream>

using namespace std;

void Convert2Bin(int dec);

int main()
{
	Convert2Bin(13);

	cout << endl;

	return 0;
}

void Convert2Bin(int dec)
{
	// 10������ 0���� �۰ų� ������ �����Ѵ�
	if (dec <= 0) 
		return;

	// ���ڸ� 2�� ���� ���� ���ڷ� �ٽ� ȣ���Ѵ�
	Convert2Bin(dec / 2);

	// ���ڸ� 2�� ���� �������� ����Ѵ�
	cout << dec % 2;
}