#include <iostream>

using namespace std;

void UsingArray(const char arr[]); // �迭�� ���ڷ� ���� �Լ����� // �Ű������� Ÿ���� �����ٶ� �迭�� ���� ������ �������� �ʴ´� // const �Ӽ��� ����Ұ�� ������ �Ȱ��� �ٲ���Ѵ�
int MinValue(int arr[], int n);

int main()
{
	char array[20] = "Hello, World!";

	UsingArray(array); // �迭�� ���ڷ� �Ѱ��ش� // �����δ� �迭�� �����ϴ°������� ������ �����͸� �����ϴ°��̴�

	cout << "In main() : " << array << endl; // �Լ� ȣ�� ���� �迭 ���¸� ����Ѵ�

	///////////////////////

	int arr[10] = { 8,10,7,2,16,9,1,0,3,5 };

	int mid = MinValue(arr, 10);

	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << mid << endl;

	mid = MinValue(arr, 5);
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << mid << endl;


	return 0;
}

void UsingArray(const char arr[]) // char* arr = &array[0] // ���ڰ� const �Ӽ��� ��� ������ ���� �� �ִ� // �迭�� ������ ���⸸�Ҽ��ְ� ��ĥ������ �ϰ������ ���
{
	cout << "In UsingArray() : " << arr << endl;

	//arr[12] = '?'; // �迭�� ������ �ϳ� �����Ѵ� // ȣ���� �Լ����� ������ ������ �Լ� ���� �迭�� ������ �ش�
}

int MinValue(int arr[], int n)
{
	int temp = 0;

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}

	for (int i = 0; i < n; i++) // �����ϸ� ������ �����ϴ°� ���� // �Լ� �ȿ��� ���� �迭������ ������ �����迭�� ���� �� ����Ѵ�
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	int a = n % 2;

	if (a == 0)
		a = (n / 2) - 1;
	else
		a = n / 2; // arr[ (n-1) / 2 ]

	return arr[a];
}

