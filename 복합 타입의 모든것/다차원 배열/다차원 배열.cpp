#include <iostream>

using namespace std;

int main()
{
	const int number1 = 10;
	const int number2 = 10;

	int arr[number1][number2];

	for (int i = 0; i < number1; i++)
	{
		for (int j = 0; j < number2; j++)
		{
			arr[i][j] = i*j;
		}
	}

	while (1)
	{
		int n, m;
		cout << "구구단!! 결과를 보고싶은 곱을 입력해주세요(종료: 113 두번) : ";
		cin >> n >> m;

		if (n == 113 || m == 113)
			break;
		else if (n >= number1 || m >= number2)
		{
			cout << "허용 범위를 넘었습니다! 다시입력해주세요" << endl << endl;
			continue;
		}

		cout << n << " x " << m << " = " << arr[n][m] << endl << endl;
	}

	return 0;
}