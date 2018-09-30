#include <iostream>

using namespace std;

// �ñ״�ó�� �Լ��� �������� ���� �κ��� �ǹ��Ѵ� // ������� int max(int a) �� �ñ״�ó�� int a �κп� �ش��Ѵ�
int max(int a, int b); // �����ε� ������ ������ ������� ������ �Լ� �̸��� ����Ҽ��ִ�
float max(float a, float b);

int main()
{
	int a1 = 10, b1 = 20, c1;
	float a2 = 12.8f, b2 = 3.5f, c2;

	c1 = max(a1, b1);
	cout << c1 << endl;

	c2 = max(a2, b2);
	cout << c2 << endl;

	return 0;
}

int max(int a, int b) // ��ǻ�ʹ� ������ Ÿ���� Ȯ���ؼ� �׿� ���� �� ��︮�� �ñ״�ó�� ���� �Լ��� ȣ���ϰ� �ȴ�
{
	int c;
	
	if (a < b)
		c = b;
	else
		c = a;

	return c;
}

float max(float a, float b)
{
	float c;

	if (a < b)
		c = b;
	else
		c = a;

	return c;
}

// ��ȯ ���� Ʋ�� ���� �����ε� �� �� ����
// �ñ״�ó�� �ٸ����� �Ҽ����� ���(int i) (int& r) �� ��� int�� Ÿ���� ���ڷ� �޾����� ��� �Լ��� ȣ���ؾ��ϴ��� ������ �����
// ������ �Լ��� ã�� ���� funtion(int n) �϶� funtion('A') �̷��� ���� Ÿ���� char�� �־����� �չ����� ȣ���̴� charŸ���� int������ �ڵ� ����ȯ�� �Ǳ⶧���̴�(������ ����)
// funtion(int n) �� funtion(char n) �̷��� �����ε�������� funtion((int)'A') �̷� ������ �ǵ��� �����ٸ� ��ǻ�ʹ� �ǵ��� �Լ��� ȣ���Ҽ��ִ�