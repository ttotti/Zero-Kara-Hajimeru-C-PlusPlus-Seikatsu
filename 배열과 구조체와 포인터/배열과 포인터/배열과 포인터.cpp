#include <iostream>

using namespace std;

int main()
{
	float f[5];
	if (f == &f[0]) // f�� �迭�� �̸��̴� ���� �迭�� �̸��� ù��° ������ �ּ��̴�
	{
		// �� if���� true�� �۵��Ѵ� 
	}

	///////////////////////////////////////

	int nArray[10]; // �Ϲ����� �迭 ����

	for (int i = 0; i < 10; i++) // �迭�� Ž���ϸ鼭 ���� �ִ´�
	{
		nArray[i] = i;
	}

	// �������� ������ �̿��� �迭Ž��
	int mArray[10];
	int* p = &mArray[0]; // �����Ͱ� �迭�� ù��° ���Ҹ� ����Ű�� �Ѵ�

	for (int i = 0; i < 10; i++) // *(p + i)�� p�� ����Ű�� ���ҿ��� i��ŭ �ڿ� �ִ� ���Ҹ� ����Ų��
	{
		*(p + i) = i;
	}

	//////////////////////////////////////////////////////

	int zArray[10];
	int* zp = &zArray[0];

	while (zp != &zArray[10])
	{
		*zp = zp - &zArray[0]; // ù��° ���ҿ��� ���̸� ���� ���� ���Ѵ�
		cout << *zp << endl;
		zp++;
	}

	///////////////////////////////////////

	//long lArray[20]; // ����

	//long(*p)[20] = &lArray;

	//for (int i = 0; i < 20; i++)
	//{
	//	(*p)[i] = i;
	//}

	////(p)[3] = 400;

	//cout << "lArray[3] = " << lArray[3] << endl;

	/////////////////////////////////////////

	double a, b, c;

	double* pArray[3]; // ���� Ÿ���� �������̴� 3���� ���Ҹ� ���� �������� �迭�� �����Ѵ�

	cout << endl << "pArray�� ������ = " << sizeof(pArray) << endl;
	pArray[0] = &a;
	pArray[1] = &b;
	pArray[2] = &c;

	return 0;
}