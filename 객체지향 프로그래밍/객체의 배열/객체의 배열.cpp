#include "Point.h"
#include <iostream>

using namespace std;

int main()
{
	Point arr[3]; // ��ü�� �迭�� �����Ҷ� �� ��ü���� ����Ʈ �����ڷ� �ʱ�ȭ �ȴ�

	for (int i = 0; i < 3; i++)
		arr[i].Print();
	cout << endl;

	Point arr2[3] = { Point(50,50),Point(100,20),Point(10,10) };

	for (int i = 0; i < 3; i++)
		arr2[i].Print();

	return 0;
}