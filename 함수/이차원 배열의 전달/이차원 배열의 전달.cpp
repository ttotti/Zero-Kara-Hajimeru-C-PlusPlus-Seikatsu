#include <iostream>

using namespace std;

void Using2DArray(int arr[][3]); // ������ �迭�� ��� �Ű������� Ÿ���� �����ٶ� int arr[][3] �� ���� �Ǿ��� ���ȣ�� ����־�� �Ѵ� // ������ �̻� �Ȱ��� �Ǿ��� ���ȣ�� ����
								 // �����ͷ� Ǯ������� int (*arr)[3] ���� arr[3]�� ���� �迭�� 5�� �ִ°��̴� �׷��Ƿ� arr[3]�迭�� ���� �����͸� ����ؼ� ����ų���ִ�
int main()
{
	int array[5][3] = { {1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15} };

	Using2DArray(array);

	return 0;
}

void Using2DArray(int arr[][3])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}