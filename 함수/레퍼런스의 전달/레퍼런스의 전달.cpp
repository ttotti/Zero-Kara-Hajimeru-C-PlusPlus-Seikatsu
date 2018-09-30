#include <iostream>

using namespace std;

void GCD_LCM(int a, int b, int& gcd, int& lcm) // ���۷������ // �Ϲݺ����� �϶��� �ܼ��� ���ڷ� �Ѱ��� ���� ����Ǵ� ��������
															   // ������ �����϶��� �Ű������ͺ����� ������ �ּҸ� ����Ű�� �ִ°��̰�
															   // ���۷��� ������ ���ڷ� �Ѱ��� ������ �Ű������� ���ؼ� �����ǰ� �ִ°��̴�
															   // ������ ���ٴ� ���۷����� ����ϴ°��� ��õ�Ѵ� 
															   // ������ ����� ����(���۷����� �޴��ʸ� &�� ���� �����ʹ� * & �Ѵ� ����) �����ͺ��� �����ϴ�(�̻��� ���� �Ѿ���� �ʴ´�)
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
	if (p) // �����͸� ����Ҷ� �����ϴ�
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