#include <iostream>

using namespace std;

// �Լ� �������� Ȱ��1 �� ����
// ForWindows9x()�� ForWindowsNT()�� ����ų �� �ִ� ������ Ÿ���� ��������
typedef void(*SYSTEM_FUNC)();

void ForWindows9x();
void ForWindowsNT();
bool IsWindows9x();
void ImportantFunc(SYSTEM_FUNC pfnSyst);

int main()
{
	SYSTEM_FUNC pfn;

	if (IsWindows9x()) // ������ Ȯ���ϰ� �˸��� �Լ��� �ּҸ� �����Ϳ� �־�д� // �� �̻� �˻������� �������� // �ʿ��Ҷ� �����͸� ���� �Լ��� ȣ���ϸ� �ȴ�
		pfn = &ForWindows9x;
	else
		pfn = &ForWindowsNT;

	// ���� �߿��� �Լ� ȣ��
	ImportantFunc(pfn); // �Լ��� �����͸� ���ڷ� �Ѱ��ش� // �ٷ� �� �κ��� '�� ���� �Լ��� �ּ� �����ϱ� �ʿ��ϸ� ȣ����' ��� ���ϴ� �κ��̴�

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
void ImportantFunc(SYSTEM_FUNC pfnSyst)
{
	(*pfnSyst)();

	(*pfnSyst)();
}
