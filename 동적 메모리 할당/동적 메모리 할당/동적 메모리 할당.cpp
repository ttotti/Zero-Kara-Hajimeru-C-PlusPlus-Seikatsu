#include <iostream>

using namespace std;

int main()
{
	int size;
	cout << "몇 개의 정수를 입력하시겠습니까?";
	cin >> size;

	float* arr = new float[size]; // 메모리 동적 할당 // int 타입의 값을 size 개수만큼 보관할 수 있는 크기의 메모리를 할당한다 // 할당한 메모리의 주소로 arr를 초기화 한다

	cout << "정수를 입력하세요" << endl;
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	float sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];

	float avg = sum / (float)size;
	cout << "합 = " << sum << " 평균 = " << avg << endl;

	cout << "평균보다 높은 점수: ";
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > avg)
			cout << arr[i] << ", ";
	}

	cout << endl;
	delete[] arr; // 메모리의 해제 // 메모리를 다 사용 후에는 반드시 수동으로 해제해주어야 한다 // 해제시킬 메모리 주소지정(arr) 지정해준 주소 해재(delete) 배열일때는 []를 붙여준다

	return 0;
}