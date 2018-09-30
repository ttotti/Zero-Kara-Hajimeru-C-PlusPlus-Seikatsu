#include <iostream>

using namespace std;

// 최대공약수와 최소공배수를 구한다
void GCD_LCM(int a, int b, int* gcd, int* lcm) // 포인터를 사용하지 않으면 두개 이상의 반환값을 함수 밖에서 사용할수없다 
{
	// 유클리드 호제법을 사용해서 GCD를 구한다
	int z;
	int x = a;
	int y = b;

	while (true)
	{
		z = x%y;
		if (0 == z)
			break;

		x = y;
		y = z;
	}

	*gcd = y;
	*lcm = a*b / *gcd;
}

int main()
{
	int gcd = 0;
	int lcm = 0;
	int x = 0, y = 0;

	cout << "두 수를 입력하세요: ";
	cin >> x >> y;

	GCD_LCM(x, y, &gcd, &lcm); // 인자가 포인터이므로 주소 값을 넘겨줄수있도록 변경한다

	cout << "GCD = " << gcd << endl;
	cout << "LCM = " << lcm << endl;

	return 0;
}