#include <iostream>

using namespace std;

// �ִ������� �ּҰ������ ���Ѵ�
void GCD_LCM(int a, int b, int* gcd, int* lcm) // �����͸� ������� ������ �ΰ� �̻��� ��ȯ���� �Լ� �ۿ��� ����Ҽ����� 
{
	// ��Ŭ���� ȣ������ ����ؼ� GCD�� ���Ѵ�
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

	cout << "�� ���� �Է��ϼ���: ";
	cin >> x >> y;

	GCD_LCM(x, y, &gcd, &lcm); // ���ڰ� �������̹Ƿ� �ּ� ���� �Ѱ��ټ��ֵ��� �����Ѵ�

	cout << "GCD = " << gcd << endl;
	cout << "LCM = " << lcm << endl;

	return 0;
}