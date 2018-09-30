#include <iostream>

using namespace std;

class DynamicArray
{
public:
	int* arr;

	DynamicArray(int arraySize);
	~DynamicArray();
};

DynamicArray::DynamicArray(int arraySize) // �����ڸ� ����ؼ� ���ڷ� ���� ũ�⸸ŭ �޸𸮸� �Ҵ��Ѵ�
{
	arr = new int[arraySize];
}

DynamicArray::~DynamicArray() // �Ҹ���
{
	delete[] arr; // �޸𸮸� �����Ѵ�
	arr = NULL;
}

int main()
{
	// �� ���� ������ �Է����� �����
	int size;
	cout << "�� ���� ������ �Է��Ͻðڽ��ϱ�? : ";
	cin >> size;

	// �ʿ��� ��ŭ�� �޸𸮸� �غ��Ѵ�
	DynamicArray da(size);

	// ������ �Է� �޴´�
	for (int i = 0; i < size; i++)
		cin >> da.arr[i];

	// �������� ������ ����Ѵ�
	for (int i = size - 1; i >= 0; i--)
		cout << da.arr[i] << " ";

	cout << endl;

	// main() �Լ��� ������ �Ҹ��ڰ� ȣ��ȴ� // �Ҹ��ڿ��� �޸𸮸� �������ֱ� ������ ���� �޸𸮸� �������� �ʿ䰡 ����

	return 0;
}