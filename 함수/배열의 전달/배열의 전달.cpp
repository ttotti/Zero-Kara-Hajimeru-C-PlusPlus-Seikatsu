#include <iostream>

using namespace std;

void UsingArray(const char arr[]); // 배열을 인자로 갖는 함수원형 // 매개변수의 타입을 적어줄때 배열의 원소 개수는 적어주지 않는다 // const 속성을 사용할경우 원형도 똑같이 바꿔야한다
int MinValue(int arr[], int n);

int main()
{
	char array[20] = "Hello, World!";

	UsingArray(array); // 배열을 인자로 넘겨준다 // 겉으로는 배열을 전달하는것이지만 실제는 포인터를 전달하는것이다

	cout << "In main() : " << array << endl; // 함수 호출 후의 배열 상태를 출력한다

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

void UsingArray(const char arr[]) // char* arr = &array[0] // 인자가 const 속성일 경우 수정을 막을 수 있다 // 배열의 내용을 보기만할수있고 고칠수없게 하고싶을때 사용
{
	cout << "In UsingArray() : " << arr << endl;

	//arr[12] = '?'; // 배열의 내용을 하나 수정한다 // 호출한 함수에서 변경한 내용이 함수 밖의 배열에 영향을 준다
}

int MinValue(int arr[], int n)
{
	int temp = 0;

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}

	for (int i = 0; i < n; i++) // 웬만하면 원본은 보존하는게 낫다 // 함수 안에서 따로 배열변수를 만든후 원본배열을 복사 후 사용한다
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

