#include <iostream>

using namespace std;

void PrintMessage(); // �Լ� ����
void PrintMyname();
int Three();
char* PrintMyname2();

int main()
{
	PrintMessage(); // �Լ� ȣ��

	/////////////

	for (int i = 0; i < 10; i++)
	{
		PrintMyname();
	}

	/////////////

	int ref;

	ref = Three(); // �Լ��� ȣ���ϰ� ��ȯ���� �����Ѵ�

	cout << "ref = " << ref << endl;

	////////////

	for (int i = 0; i < 10; i++)
	{
		char* name = PrintMyname2();
		cout << name << endl;
	}

	return 0; // return�� �ǹ̴� �� �Լ��� ������ �� �ڿ� ������ ���� ��ȯ�϶� �ΰ��� �ִ�
}

void PrintMessage() // �Լ� ����
{
	cout << "Hi, I'm your first function!!!\n";
}


//////////////////////////////////////////////////////

void PrintMyname()
{
	cout << "My name is Limttotti!!" << endl;
}

//////////////////////////////////////////////////////

int Three() // 3�� ��ȯ�ϴ� �Լ�
{
	return 3;
}

char* PrintMyname2()
{
	return "My name is Lim ttotti2";
}
