#include <iostream>

using namespace std;

int main()
{
	int size;
	cout << "�� ���� ������ �Է��Ͻðڽ��ϱ�?";
	cin >> size;

	float* arr = new float[size]; // �޸� ���� �Ҵ� // int Ÿ���� ���� size ������ŭ ������ �� �ִ� ũ���� �޸𸮸� �Ҵ��Ѵ� // �Ҵ��� �޸��� �ּҷ� arr�� �ʱ�ȭ �Ѵ�

	cout << "������ �Է��ϼ���" << endl;
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	float sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];

	float avg = sum / (float)size;
	cout << "�� = " << sum << " ��� = " << avg << endl;

	cout << "��պ��� ���� ����: ";
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > avg)
			cout << arr[i] << ", ";
	}

	cout << endl;
	delete[] arr; // �޸��� ���� // �޸𸮸� �� ��� �Ŀ��� �ݵ�� �������� �������־�� �Ѵ� // ������ų �޸� �ּ�����(arr) �������� �ּ� ����(delete) �迭�϶��� []�� �ٿ��ش�

	return 0;
}