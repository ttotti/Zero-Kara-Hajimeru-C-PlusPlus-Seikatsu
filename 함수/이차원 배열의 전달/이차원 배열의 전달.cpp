#include <iostream>

using namespace std;

void Using2DArray(int arr[][3]); // 이차원 배열일 경우 매개변수의 타입을 적어줄때 int arr[][3] 과 같이 맨앞의 대괄호를 비워주어야 한다 // 삼차원 이상도 똑같다 맨앞의 대괄호만 비우기
								 // 포인터로 풀어봤을때 int (*arr)[3] 으로 arr[3]과 같은 배열이 5개 있는것이다 그러므로 arr[3]배열에 대한 포인터를 사용해서 가리킬수있다
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