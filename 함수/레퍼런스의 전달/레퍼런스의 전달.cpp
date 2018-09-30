#include <iostream>

using namespace std;

void GCD_LCM(int a, int b, int& gcd, int& lcm) // 레퍼런스사용 // 일반변수가 일때는 단순히 인자로 넘겨진 값이 복사되는 것이지만
															   // 포인터 변수일때는 매개포인터변수가 인자의 주소를 가르키고 있는것이고
															   // 레퍼런스 변수는 인자로 넘겨진 변수가 매개변수에 의해서 참조되고 있는것이다
															   // 포인터 보다는 레퍼런스를 사용하는것을 추천한다 
															   // 이유는 사용이 쉽고(레퍼런스는 받는쪽만 &을 쓴다 포인터는 * & 둘다 쓴다) 포인터보다 안전하다(이상한 값이 넘어오지 않는다)
{
	int z;
	int x = a;
	int y = b;

	while (true)
	{
		z = x%y;

		if (z == 0)
			break;

		x = y;
		y = z;
	}

	gcd = y;
	lcm = a*b / gcd;
}

void Sub(int i, int* p, int& r)
{
	i = 10;
	if (p) // 포인터를 사용할때 안전하다
		*p = 20;
	r = 30;
}

int main()
{
	int gcd = 0;
	int lcm = 0;
	GCD_LCM(28, 35, gcd, lcm);

	cout << gcd << " , " << lcm << endl;

	int a = 0, b = 0, c = 0;

	Sub(a, &b, c);

	cout << a << ", " << b << ", " << c << endl;
	
	return 0;
}