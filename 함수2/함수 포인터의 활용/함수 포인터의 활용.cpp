#include <iostream>

using namespace std;

void ForWindows9x();
void ForWindowsNT();
bool IsWindows9x();
void ImportantFunc();

// ������ �� �ڵ�� ������ �ִ� // �Ź� ���� ȯ���� �˻��Ѵٴ� ���̴� �ѹ��� ���ϴ°����� ����ϴ� // ������ �ڵ尡 �ߺ����ִ� 39��~43�� �� 47��~51�� ���� ������ �ڵ��̴�
int main()
{
	// ���� �߿��� �Լ� ȣ��
	ImportantFunc();

	return 0;
}

// Windows 95/98/Me �� ȯ�濡�� ȣ���ؾ��ϴ� �Լ�
void ForWindows9x()
{
	cout << "Windows 9x�� �Լ��� ȣ���" << endl;
}

// Windows NT/2000/XP �� ȯ�濡�� ȣ���ؾ��ϴ� �Լ�
void ForWindowsNT()
{
	cout << "Windows NT/2000/XP �� �Լ��� ȣ���" << endl;
}

// ���� ����Ǵ� ȯ���� Windows 9x���� ��ȯ�ϴ� �Լ�
bool IsWindows9x()
{
	return false;
}

// ���� �߿��� ���� �ϴ� �Լ�
void ImportantFunc()
{
	// ������ �´� �Լ��� ȣ���Ѵ�
	if (IsWindows9x())
		ForWindows9x();
	else
		ForWindowsNT();

	// �ٽ� �ѹ� ������ �´� �Լ��� ȣ���Ѵ�
	if (IsWindows9x())
		ForWindows9x();
	else
		ForWindowsNT();
}
